class BIT:
    __slots__ = ('n', 'tree')
    def __init__(self, n: int):
        self.n = n
        self.tree = [0] * (n + 2)

    def add(self, i: int, delta: int) -> None:
        while i <= self.n:
            self.tree[i] += delta
            i += i & -i

    def sum(self, i: int) -> int:
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def find_kth(self, k: int) -> int:
        idx = 0
        bit_mask = 1 << (self.n.bit_length() - 1)
        while bit_mask:
            nxt = idx + bit_mask
            if nxt <= self.n and self.tree[nxt] < k:
                idx = nxt
                k -= self.tree[nxt]
            bit_mask >>= 1
        return idx + 1
class Solution:
    def countOfPeaks(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        n = len(nums)
        def F(x: int) -> int:
            return ((x - 1) * (x - 2) // 2) if x >= 3 else 0

        bit_c = BIT(n)     # count of peaks
        bit_gap = BIT(n)   # gap values stored at peaks
        P = [0] * n        # current peak indicators

        def add_peak(p: int) -> None:
            # number of peaks < p
            cnt_prev = bit_c.sum(p)          # bit_c.sum(p) sums array indices < p
            prev_p = bit_c.find_kth(cnt_prev) - 1 if cnt_prev > 0 else -1
            cnt_total = bit_c.sum(n)
            cnt_upto_p = bit_c.sum(p + 1)    # peaks <= p
            next_p = bit_c.find_kth(cnt_upto_p + 1) - 1 if cnt_upto_p < cnt_total else -1

            if prev_p != -1:
                old_gap = F(next_p - prev_p + 1) if next_p != -1 else 0
                new_gap = F(p - prev_p + 1)
                bit_gap.add(prev_p + 1, new_gap - old_gap)

            new_gap_p = F(next_p - p + 1) if next_p != -1 else 0
            bit_gap.add(p + 1, new_gap_p)
            bit_c.add(p + 1, 1)
            P[p] = 1

        def remove_peak(p: int) -> None:
            cnt_prev = bit_c.sum(p)
            prev_p = bit_c.find_kth(cnt_prev) - 1 if cnt_prev > 0 else -1
            cnt_total = bit_c.sum(n)
            cnt_upto_p = bit_c.sum(p + 1)
            next_p = bit_c.find_kth(cnt_upto_p + 1) - 1 if cnt_upto_p < cnt_total else -1

            cur_gap_p = F(next_p - p + 1) if next_p != -1 else 0
            bit_gap.add(p + 1, -cur_gap_p)

            if prev_p != -1:
                old_gap = F(p - prev_p + 1)
                new_gap = F(next_p - prev_p + 1) if next_p != -1 else 0
                bit_gap.add(prev_p + 1, new_gap - old_gap)

            bit_c.add(p + 1, -1)
            P[p] = 0

        # Initialise peaks
        for i in range(1, n - 1):
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                P[i] = 1
        for i in range(n):
            if P[i]:
                add_peak(i)

        ans = []
        for q in queries:
            if q[0] == 1:
                L, R = q[1], q[2]
                if R - L + 1 < 3:
                    ans.append(0)
                    continue

                total_F = F(R - L + 1)
                cnt_upto_L = bit_c.sum(L + 1)       
                cnt_upto_Rminus1 = bit_c.sum(R)     

                if cnt_upto_Rminus1 - cnt_upto_L == 0:
                    ans.append(0)
                else:
                    first = bit_c.find_kth(cnt_upto_L + 1) - 1
                    last = bit_c.find_kth(cnt_upto_Rminus1) - 1
                    sum_gap_internal = bit_gap.sum(last) - bit_gap.sum(first)
                    non_peak = F(first - L + 1) + F(R - last + 1) + sum_gap_internal
                    ans.append(total_F - non_peak)
            else:
                idx, val = q[1], q[2]
                nums[idx] = val
                for i in (idx - 1, idx, idx + 1):
                    if 0 <= i < n:
                        is_peak = (i > 0 and i < n - 1 and
                                   nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
                        if P[i] != is_peak:
                            if is_peak:
                                add_peak(i)
                            else:
                                remove_peak(i)

        return ans