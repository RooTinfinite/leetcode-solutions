class Solution {

    long[][] nCr = new long[51][51];
    public long nthSmallest(long n, int k) {
        calcnCr();

        long l = 1;
        long r = (1L << 50);

        while(l <= r){
            long mid = l + (r-l)/2;

            if(count(mid, k) < n){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return l;
    }

    public void calcnCr(){
        for(int i = 0; i < 51; i++){
            nCr[i][0] = 1;
            for(int j = 1; j <= i; j++){
                nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
            }
        }
    }

    public long count(long mid, int k){
        long total = 0;
        int setBitCount = 0;
        
        for(int i = 50; i >= 0; i--){
            if(((mid >> i) & 1) == 1){
                int need = k - setBitCount;
                if(need >= 0 && need <= i){
                    total += nCr[i][need];
                }
                setBitCount++;
                if(k < setBitCount) break;
            }
        }
        if(setBitCount == k) total++;

        return total;
    }
}