class Solution:
	def checkIfExist(self, arr: List[int]) -> bool:

		def BinarySearch(array, target):

			low = 0
			high = len(array) - 1

			while low <= high:

				mid = (low + high ) // 2

				if array[mid] == target:
					return mid

				elif array[mid] < target:
					low = mid + 1

				elif array[mid] > target:
					high = mid - 1

			return -1

		array = sorted(arr)

		for i in range(len(array)):

			index = BinarySearch(array, array[i] * 2)

			if index != -1 and index != i:

				return True

		return False