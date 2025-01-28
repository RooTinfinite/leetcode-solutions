class Solution {
    public int numberOfSubstrings(String str) {
        int ans = 0;
        for (int zero = 0; zero * zero < str.length(); zero++) {
            int lastPos = -1;
            int[] count = new int[] { 0, 0 };
            for (int s = 0, e = 0; e < str.length(); e++) {
                count[str.charAt(e) - '0']++;
                while (s < e) {
                    if (str.charAt(s) == '0' && count[0] > zero) {
                        count[0]--;
                        lastPos = s;
                    } else if (str.charAt(s) == '1' && (count[1] - 1) >= (zero * zero)) {
                        count[1]--;
                    } else {
                        break;
                    }
                    s++;
                }
                if (count[0] == zero && count[1] >= count[0] * count[0])
                    ans += (s - lastPos);
            }
        }
        return ans;
    }
}