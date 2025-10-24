class Solution {
    public int maxDistance(String[] words) {
        if (words == null || words.length < 2) {
            return 0;
        }

        String first = words[0];
        String last = words[words.length - 1];
        int lastIndex = words.length - 1;

        int indexOfFirstNotLast = -1;
        for (int i = 0; i < words.length; i++) {
            if (!words[i].equals(last)) {
                indexOfFirstNotLast = i;
                break;
            }
        }

        int distance1 = 0;
        if (indexOfFirstNotLast != -1) {
            distance1 = lastIndex - indexOfFirstNotLast + 1;
        }

        int indexOfLastNotFirst = -1;
        for (int i = words.length - 1; i >= 0; i--) {
            if (!words[i].equals(first)) {
                indexOfLastNotFirst = i;
                break;
            }
        }

        int distance2 = 0;
        if (indexOfLastNotFirst != -1) {
            distance2 = indexOfLastNotFirst + 1;
        }

        return Math.max(distance1, distance2);
    }
}