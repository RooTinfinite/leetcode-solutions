class Solution {
    public String majorityFrequencyGroup(String s) {
        int[] freq = new int[26];


        for (char a : s.toCharArray()) {
            freq[a - 'a']++;
        }


        HashMap<Integer, String> mp = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                char ch = (char) (i + 'a');
                mp.put(freq[i], mp.getOrDefault(freq[i], "") + ch);
            }
        }

 
        String ans = "";
        int maxCnt = 0;

        for (Map.Entry<Integer, String> entry : mp.entrySet()) {
            int currCnt = entry.getKey();
            String curr = entry.getValue();

            if ((curr.length() > ans.length()) || 
                (curr.length() == ans.length() && currCnt > maxCnt)) {
                ans = curr;
                maxCnt = currCnt;
            }
        }

        return ans;
    }
}