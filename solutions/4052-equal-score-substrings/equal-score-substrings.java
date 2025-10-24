class Solution {
    public boolean scoreBalance(String s) {
        int n=s.length();
        HashSet<Integer> set = new HashSet<>();
        int sum=0;
        
        for(int i=0;i<n;i++)
            {
                sum += s.charAt(i)-'a'+1;
                set.add(sum);
            }
        if(sum%2!=0) return false;
        return set.contains(sum/2);
    }
}