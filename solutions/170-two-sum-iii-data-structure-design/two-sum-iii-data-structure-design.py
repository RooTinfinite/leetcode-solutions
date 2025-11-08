class TwoSum(object):

    def __init__(self) -> None:
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.is_sorted = False

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        # Inserting while maintaining the ascending order.
        # for index, num in enumerate(self.nums):
        #     if number <= num:
        #         self.nums.insert(index, number)
        #         return
        ## larger than any number
        # self.nums.append(number)

        self.nums.append(number)
        self.is_sorted = False

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        if not self.is_sorted:
            self.nums.sort()
            self.is_sorted = True

        low, high = 0, len(self.nums) - 1
        while low < high:
            currSum = self.nums[low] + self.nums[high]
            if currSum < value:
                low += 1
            elif currSum > value:
                high -= 1
            else:  # currSum == value
                return True

        return False