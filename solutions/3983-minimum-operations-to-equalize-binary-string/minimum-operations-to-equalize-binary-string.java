class Solution {
    public int minOperations(String s, int k) {
        int n=s.length();
        int []dp=new int[n+1];
        Arrays.fill(dp,-1);
        TreeSet<Integer> even = new TreeSet<>();
        TreeSet<Integer> odd = new TreeSet<>();
        for (int i = 2; i <= n; i += 2) even.add(i);
        for (int i = 1; i <= n; i += 2) odd.add(i);
        dp[0]=0;
        Queue<Integer>q=new LinkedList<>();
        q.add(0);
        while(!q.isEmpty()){
            int x=q.poll();
            int minz=Math.max(0,k-(n-x) );
            int maxz=Math.min(x,k);
            int stx=x+k-2*maxz;
            int endx=x+k-2*minz;
        
            TreeSet<Integer>set=((stx%2)==0)?even:odd;

            Integer curr=set.ceiling(stx);
            while(curr!=null && curr<=endx){
                dp[curr]=1+dp[x];
                q.add(curr);
                Integer next = set.higher(curr);
                set.remove(curr);
                curr = next;
            }

        }
        int cnt=0;
        for(char ch:s.toCharArray()){
            if(ch=='0'){
                cnt++;
            }
        }


        return dp[cnt];
    }
}