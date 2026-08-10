class Solution {
    public int countValidPrefixes(String s) {
        int cnt = 0, ans = 0;

        for(char ch : s.toCharArray()){
            cnt = ch == '1' ? cnt + 1 : cnt - 1;

            if(cnt >= -1 && cnt <= 1)
                ans++;
        }

        return ans;
    }
}