class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        maxheap = []
        for char, freq in Counter(s).items():
            heappush(maxheap, (-freq, char))

        temp = []
        count = 0
        ans = ''
        while len(ans) < len(s):
            if not maxheap:
                return ''

            freq, char = heappop(maxheap)

            ans += char
            if freq != -1:
                temp.append((freq + 1, char))


            count += 1
            if count >= k:

                count = 0
                while temp:
                    heappush(maxheap, temp.pop())
        
        return ans
        