public class Solution {

    public int maxDistance(String s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            switch (c) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = Math.max(
                ans,
                Math.min(
                    Math.abs(latitude) + Math.abs(longitude) + k * 2,
                    i + 1
                )
            );
        }
        return ans;
    }
}