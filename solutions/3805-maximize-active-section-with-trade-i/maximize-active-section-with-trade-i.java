
class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int originalOnes = countOnes(s);
        String t = "1" + s + "1";
        List<Integer> onesPos = getOnesPositions(t);
        int maxGain = 0;
        int m = onesPos.size();

        for (int i = 0; i < m; ) {
            int start = onesPos.get(i);
            // Find the end of the current '1's block
            int j = i;
            while (j < m && onesPos.get(j) == start + (j - i)) {
                j++;
            }
            int end = onesPos.get(j - 1);
            // Check if this block is surrounded by '0's
            if (start > 0 && end < t.length() - 1 && t.charAt(start - 1) == '0' && t.charAt(end + 1) == '0') {
                // Find the '1' before start - 1
                int leftOne = findLeftOne(onesPos, start - 1);
                // Find the '1' after end + 1
                int rightOne = findRightOne(onesPos, end + 1);
                // Calculate gain
                int gain = (rightOne - leftOne - 1) - (end - start + 1);
                if (gain > maxGain) {
                    maxGain = gain;
                }
            }
            i = j;
        }

        return originalOnes + maxGain;
    }

    private int countOnes(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                count++;
            }
        }
        return count;
    }

    private List<Integer> getOnesPositions(String t) {
        List<Integer> onesPos = new ArrayList<>();
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == '1') {
                onesPos.add(i);
            }
        }
        return onesPos;
    }

    private int findLeftOne(List<Integer> onesPos, int target) {
        int left = 0;
        int right = onesPos.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (onesPos.get(mid) < target) {
                result = onesPos.get(mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    private int findRightOne(List<Integer> onesPos, int target) {
        int left = 0;
        int right = onesPos.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (onesPos.get(mid) > target) {
                result = onesPos.get(mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
}