import java.math.*;
class Solution {
    public long popcountDepth(long n, int k) {
        if(k==0)return 1;
        if(n==1)return 0;

        int count, pos, totalBits=0;
        long copy=n, ans=0;
        while(copy>0){
            totalBits++;
            copy>>=1;
        }        
        int depths[]=getDepths(totalBits);
        BigInteger fact[]=new BigInteger[totalBits+1];
        getFact(totalBits, fact);
         

        for(int fixedBits=0; totalBits>0;fixedBits++){
            for(int variableBits=totalBits-1;variableBits>=0;variableBits--){
                if(fixedBits==0 && variableBits==0){
                    continue;
                }else if(depths[fixedBits+variableBits]==k){
                    ans+=getNCR(totalBits-1, variableBits, fact);
                    if(fixedBits==0 && variableBits==1){
                        ans-=1;//don't count 1
                    } 
                }
            }
            
            // means no high bit on left of totalBits
            int highBitPos=0;
            copy=n;
            for(int i=1;i<totalBits;i++){
                if((copy&1)==1){
                    highBitPos=i;
                }
                copy>>=1;
            }
            totalBits=highBitPos;
        }

        count=0;
        while(n>0){
            if((n&1)==1)    count++;
            n>>=1;
        }
        if(depths[count]==k) ans++;

        return ans;
    }

    private int[] getDepths(int bits){
        int depths[]=new int[bits+1], copy, count;
        depths[0]=-1;
        for(int i=1;i<=bits;i++){
            depths[i]=1;
            copy=i;
            while(copy>1){
                depths[i]++;
                count=0;
                while(copy>0){
                    if((copy&1)==1) count++;
                    copy>>=1;
                }
                copy=count;
            }
        }
        return depths;
    }

    private long getNCR(int n, int r, BigInteger fact[]){
        //since the solution is expecting a long return value, this value will fit into long according to the testcases
        return fact[n].divide(fact[r].multiply(fact[n-r])).longValue();
    }
    
    private void getFact(int n, BigInteger fact[]){
        if(n==0){
            fact[0]=new BigInteger("1");
            return;
        }
        getFact(n-1, fact);
        fact[n]=new BigInteger(n+"");
        fact[n]=fact[n].multiply(fact[n-1]);
    }
}