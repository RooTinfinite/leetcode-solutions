class Solution {

    //to find the digit sum
    int sum(int num) {
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    //minimum swaps needed to make both array equal
    int solve(int[] nums, int[][] arr) {
        int n = arr.length;
        Map<Integer, Integer> map = new HashMap<>();
        //add the elements with its index in map
        for (int i = 0; i < n; i++)
            map.put(nums[i], i);
        //to track the visited elements
        boolean[] v = new boolean[n];
        int ans = 0;
        //travel all the elements
        for (int i = 0; i < n; i++) {
            //if the current element is already visited 
            //or the element is in correct sorted place
            if (v[i] || nums[i] == arr[i][1])
                continue;
            //find the size of cycle , we can swap the elements in 
            //cycle somehow in minimum swaps of size-1
            int size = 0;
            int j = i;

            while (!v[j]) {
                v[j] = true;
                j = map.get(arr[j][1]);
                size++;
            }

            if (size > 1)
                ans += (size - 1);
        }
        return ans;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = sum(nums[i]);
            arr[i][1] = nums[i];
        }
        //sort based on digit sum
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0]; 
            return a[1] - b[1]; 
        });

        return solve(nums, arr);
    }
}