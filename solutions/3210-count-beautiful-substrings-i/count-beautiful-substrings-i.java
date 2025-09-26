class Solution {
    public int beautifulSubstrings(String s, int k) {
        int len=s.length();
        int ans=0;
        for(int i=0;i<len;i++)
        {
            int count=0,count1=0;
            for(int j=i;j<len;j++)
            {
                char c=s.charAt(j);
                if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
                {
                    count++;
                }
                else
                {
                    count1++;
                }
                if(count==count1 && (count*count1)%k == 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
}