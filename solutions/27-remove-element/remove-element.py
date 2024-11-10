class Solution:
    def removeElement(self, nums: List[int], target: int) -> int:
        write_pointer = 0
        array_length = len(nums)

        while write_pointer < array_length:
            if nums[write_pointer] == target:
                nums[write_pointer], nums[array_length - 1] = nums[array_length - 1], nums[write_pointer]
                array_length -= 1
            else:
                write_pointer += 1
                
        return array_length