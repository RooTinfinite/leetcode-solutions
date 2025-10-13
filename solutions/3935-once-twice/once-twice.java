class Solution {
    public int[] onceTwice(int[] nums) {
        int[] arr = { 0, 0, -1 };
        for (int num : nums) {
            arr = get(arr, num);
        }
        if (arr[0] == 0) {
            int[] arr1 = { 0, 0, -1 };
            for (int num : nums) {
                if ((num & arr[1]) == arr[1]) {
                    arr1 = get(arr1, num);
                }
            }
            return new int[] { arr1[1] ^ arr[1], arr1[1] };
        } else {
            int[] arr1 = { 0, 0, -1 };
            for (int num : nums) {
                if ((num & arr[0]) == arr[0]) {
                    arr1 = get(arr1, num);
                }
            }
            return new int[] { arr1[0], arr1[0] ^ arr[0] | arr[1] };
        }
    }

    public int[] get(int[] arr, int num) {
        int temp1 = arr[0] & num;
        int temp2 = arr[1] & num;
        int temp3 = arr[2] & num;
        arr[0] = (arr[0] - temp1) | temp3;
        arr[1] = (arr[1] - temp2) | temp1;
        arr[2] = (arr[2] - temp3) | temp2;
        return arr;
    }
}