class Solution {

    private static final int RUN = 32;

    public String largestNumber(int[] nums) {
        // Convert int array to Integer array for custom sorting
        Integer[] numsArray = Arrays.stream(nums)
            .boxed()
            .toArray(Integer[]::new);
        // Sort the numbers using custom Tim Sort
        timSort(numsArray);
        // Concatenate sorted numbers to form the largest number
        StringBuilder largestNum = new StringBuilder();
        for (int num : numsArray) {
            largestNum.append(num);
        }
        // Handle the case where the largest number is zero
        return largestNum.charAt(0) == '0' ? "0" : largestNum.toString();
    }

    private void insertionSort(Integer[] nums, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            int temp = nums[i];
            int j = i - 1;
            while (j >= left && compare(temp, nums[j])) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = temp;
        }
    }

    private void merge(Integer[] nums, int left, int mid, int right) {
        Integer[] leftArr = Arrays.copyOfRange(nums, left, mid + 1);
        Integer[] rightArr = Arrays.copyOfRange(nums, mid + 1, right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArr.length && j < rightArr.length) {
            if (compare(leftArr[i], rightArr[j])) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }
        while (i < leftArr.length) nums[k++] = leftArr[i++];
        while (j < rightArr.length) nums[k++] = rightArr[j++];
    }

    private void timSort(Integer[] nums) {
        int n = nums.length;
        // Sort small runs with insertion sort
        for (int i = 0; i < n; i += RUN) {
            insertionSort(nums, i, Math.min(i + RUN - 1, n - 1));
        }
        // Merge sorted runs
        for (int size = RUN; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min(left + 2 * size - 1, n - 1);
                if (mid < right) {
                    merge(nums, left, mid, right);
                }
            }
        }
    }

    private boolean compare(int firstNum, int secondNum) {
        String firstStr = Integer.toString(firstNum);
        String secondStr = Integer.toString(secondNum);
        return (firstStr + secondStr).compareTo(secondStr + firstStr) > 0;
    }
}