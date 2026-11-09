class Solution {
    public int countStaircase(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            HashMap<Integer, Integer> first = new HashMap<>();
            ArrayList<Integer> freq = new ArrayList<>();
            int invalid = 0;

            for (int j = i; j < n; j++) {
                int num = nums[j];

                if (!first.containsKey(num)) {
                    int idx = freq.size();
                    first.put(num, idx);
                    freq.add(1);

                    if (idx != 0)
                        invalid++;
                } else {
                    int idx = first.get(num);
                    int old = freq.get(idx);
                    int expected = idx + 1;
                    int next = old + 1;

                    if (old != expected)
                        invalid--;

                    if (next > expected)
                        break;

                    freq.set(idx, next);

                    if (next != expected)
                        invalid++;
                }

                if (invalid == 0)
                    ans++;
            }
        }

        return ans;
    }
}