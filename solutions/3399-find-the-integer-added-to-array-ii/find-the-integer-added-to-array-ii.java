class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int min = Integer.MAX_VALUE;
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            for (int j = i + 1; j < nums1.length; j++) {
                Set<Integer> st = isTwoSequenceValid(nums1, nums2, i, j);
                if (st.size() == 1) {
                    Optional<Integer> optional = st.stream().findFirst();
                    if (optional.isPresent()) {
                        int retrieved = optional.get();
                        min = Math.min(min, retrieved);
                    }
                }
            }
        }
        return min;
    }

    public Set<Integer> isTwoSequenceValid(int nums1[], int nums2[], int indexOfI, int indexOfJ) {
        int i = 0;
        int j = 0;
        Set<Integer> st = new HashSet<>();
        while (i < nums1.length && j < nums2.length) {
            if (i == indexOfI || i == indexOfJ) {
                i++;
                continue;
            }
            st.add(nums2[j] - nums1[i]);
            i++;
            j++;
        }
        return st;
    }
}

/*
  4,8,12,16,20

  10,14,18
*/