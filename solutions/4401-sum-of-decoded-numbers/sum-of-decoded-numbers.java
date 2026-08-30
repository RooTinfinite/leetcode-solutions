class Solution {
    public long power(long fir,long sec,long mod){
        long result = 1;
        fir%=mod;
        while(sec>0){
            if(sec%2==1){
                result = (result*fir)%mod;
            }
            fir = (fir*fir)%mod;
            sec/=2;
        }
        return result;
    }
    public int sumDecoded(long[] nums) {
        int n = nums.length;
        long ans = 0;
        long[] vornelqati = nums;
        long mod = 1000000007L;
        for(int i=0;i<n;i++){
            long num = vornelqati[i];
            int ed =(int)( num%10);
            num = num/10;
            String s = String.valueOf(num);
            long fir = Long.parseLong(s.substring(0,ed));
            long sec = Long.parseLong(s.substring(ed));
            long value = power(fir,sec,mod);
            ans = (ans+value)%mod;
        }
        return (int)ans;
    }
}