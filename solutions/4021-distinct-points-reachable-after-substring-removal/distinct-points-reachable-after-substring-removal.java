class Solution {
    public int distinctPoints(String s, int k) {
        int n = s.length();
        int rDp[] = new int[n+1];
        int cDp[] = new int[n+1];

        for(int i=n-1;i>=0;i--){
            char c = s.charAt(i);
            rDp[i] = rDp[i+1];
            cDp[i] = cDp[i+1];
            if(c=='U')
                cDp[i]++;
            else if(c=='D')
                cDp[i]--;
            else if(c=='L')
                rDp[i]--;
            else
                rDp[i]++;
        }

        Set<String> set = new HashSet<>();
        for(int start=0;start+k<=n;start++){
            int end = start+k;

            int r = rDp[0] - rDp[start] + rDp[end];
            int c = cDp[0] - cDp[start] + cDp[end];

            String str = r + "," + c;
            set.add(str);
        }

        return set.size();
    }
}