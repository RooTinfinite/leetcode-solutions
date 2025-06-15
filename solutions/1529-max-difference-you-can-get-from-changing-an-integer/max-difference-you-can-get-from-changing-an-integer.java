class Solution {

    public int maxDiff(int num) {
        int min_num = num;
        int max_num = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                String res = change(num, x, y);
                // Check if there are leading zeros
                if (res.charAt(0) != '0') {
                    int res_i = Integer.parseInt(res);
                    min_num = Math.min(min_num, res_i);
                    max_num = Math.max(max_num, res_i);
                }
            }
        }

        return max_num - min_num;
    }

    public String change(int num, int x, int y) {
        StringBuffer num_s = new StringBuffer(String.valueOf(num));
        int length = num_s.length();
        for (int i = 0; i < length; i++) {
            char digit = num_s.charAt(i);
            if (digit - '0' == x) {
                num_s.setCharAt(i, (char) ('0' + y));
            }
        }
        return num_s.toString();
    }
}