class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hash_map = {}

        for i in range(len(numbers)):
            if ((target - numbers[i]) not in hash_map):
                hash_map[numbers[i]] = i+1
            else:       
                return[hash_map[target - numbers[i]], i+1]