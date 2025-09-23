class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        #if ans == -1 then n = 0
        def find_leftmost_set_bit_index(n):
            ans = -1
            for i in range(64):
                if n & (1 << i):
                    ans = i
            return ans


        def convert_num_to_array(n):
            ans = [0] * 64
            for i in range(64):
                if n & (1 << i):
                    ans[i] = 1
            return ans
        
        def convert_array_to_num(arr):
            assert(len(arr) == 64)

            ans = 0

            for i in range(64):
                if arr[i]:
                    ans = ans | (1 << i)
            return ans

        
        def add_arrays(a, b):
            assert(len(a) == len(b))
            sum_ = [0] * 64
            for i in range(len(a)):
                sum_[i] = a[i] + b[i]
            return sum_
        
        def subtract_arrays(a, b):
            assert(len(a) == len(b))
            result = [0] * 64
            for i in range(len(a)):
                result[i] = a[i] - b[i]
            return result

        leftmost = set()
        leftmost_bit_index = -1

        or_result = [0] * 64

        for num in nums:
            num_array = convert_num_to_array(num)

            or_result = add_arrays(or_result, num_array)

            tmp = find_leftmost_set_bit_index(num)

            if tmp > leftmost_bit_index:
                leftmost_bit_index = tmp
                leftmost = set([num])
        
            elif tmp == leftmost_bit_index:
                leftmost.add(num)
            
        
        answer = convert_array_to_num(or_result)

        for num in leftmost:
            num_array = convert_num_to_array(num)
            difference_array = subtract_arrays(or_result, num_array)

            difference = convert_array_to_num(difference_array)

            new_num = (num << k)

            answer = max(answer, difference | new_num)
        
        return answer