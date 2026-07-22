class Solution {
    public int minLights(int[] l) {
        int[] li = new int[l.length];
        int max = 0;

        for (int i = 0; i < l.length; i++) {
            if (max > 0)
                li[i] = -1;

            if (l[i] > 0) {
                max = Math.max(l[i], max - 1);
                if (max > 0)
                    li[i] = -1;
            } else {
                if (max > 0)
                    li[i] = -1;
                max--;
            }
        }

        max = 0;

        for (int i = l.length - 1; i >= 0; i--) {
            if (max > 0)
                li[i] = -1;

            if (l[i] > 0) {
                max = Math.max(l[i], max - 1);
                if (max > 0)
                    li[i] = -1;
            } else {
                if (max > 0)
                    li[i] = -1;
                max--;
            }
        }

        int count = 0, ans = 0;

        for (int i = 0; i < l.length; i++) {
            if (li[i] != -1) {
                count++;
            } else {
                ans += (count + 2) / 3;
                count = 0;
            }
        }

        if (count > 0)
            ans += (count + 2) / 3;

        return ans;
    }
}