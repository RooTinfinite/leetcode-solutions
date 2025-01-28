class Solution {
    int MOD = 1000000007;

    int[][] nCr;
    public void buildBinomialTable(int nMax) {
        nCr = new int[nMax+1][nMax+1];
        for(int i=0; i<=nMax; i++){
            nCr[i][0] = 1;
            for(int j=1; j<=i; j++){
                nCr[i][j] = (int)(((long)nCr[i-1][j-1] + nCr[i-1][j]) % MOD);
            }
        }
    }

    public int modFix(long x) {
        long y = x % MOD;
        return (int)((y + MOD) % MOD);
    }

    public int subsequencesWithMiddleMode(int[] nums) {
        int n = nums.length;
        buildBinomialTable(n);

        if(n < 5) return 0;

        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            map.computeIfAbsent(nums[i], z -> new ArrayList<>()).add(i);
        }

        for(var e : map.entrySet()){
            Collections.sort(e.getValue());
        }

        int[] leftCount = new int[n];
        int[] rightCount = new int[n];

        for(int k = 0; k < n; k++){
            int c = nums[k];
            List<Integer> posList = map.get(c);
            int lc = countLess(posList, k); 
            int rc = posList.size() - lc - 1;
            leftCount[k] = lc;
            rightCount[k] = rc;
        }

        long ans = 0L;

        for(int k = 2; k <= n - 3; k++){
            int cVal = nums[k];
            int leftC = leftCount[k];
            int rightC = rightCount[k];
            int leftNonC = k - leftC;
            int rightNonC = (n-1 - k) - rightC;

            if(leftNonC < 0 || rightNonC < 0) continue;

            long waysT5 = 0;
            if(leftC >= 2 && rightC >= 2){
                waysT5 = ((long)nCr[leftC][2] * nCr[rightC][2]) % MOD;
            }

            long waysT4 = 0;
            if(leftC >= 2 && rightC >= 1){
                if(rightNonC >= 1){
                    waysT4 += (long)nCr[leftC][2] * nCr[rightC][1] % MOD
                              * nCr[leftNonC][0] % MOD
                              * nCr[rightNonC][1] % MOD;
                }
            }
            if(leftC >= 1 && rightC >= 2){
                if(leftNonC >= 1){
                    long tmp = (long)nCr[leftC][1] * nCr[rightC][2] % MOD
                               * nCr[leftNonC][1] % MOD
                               * nCr[rightNonC][0] % MOD;
                    waysT4 += tmp;
                }
            }
            waysT4 %= MOD;

            long waysT3 = 0;
            if(rightC >= 2){
                long tmp = (long)nCr[leftC][0] * nCr[rightC][2] % MOD
                           * nCr[leftNonC][2] % MOD
                           * nCr[rightNonC][0] % MOD;
                waysT3 = (waysT3 + tmp) % MOD;
            }
            if(leftC >= 1 && rightC >= 1){
                long tmp = (long)nCr[leftC][1] * nCr[rightC][1] % MOD
                           * nCr[leftNonC][1] % MOD
                           * nCr[rightNonC][1] % MOD;
                waysT3 = (waysT3 + tmp) % MOD;
            }
            if(leftC >= 2){
                long tmp = (long)nCr[leftC][2] * nCr[rightC][0] % MOD
                           * nCr[leftNonC][0] % MOD
                           * nCr[rightNonC][2] % MOD;
                waysT3 = (waysT3 + tmp) % MOD;
            }

            Map<Integer,Integer> leftFreqMap = new HashMap<>();
            Map<Integer,Integer> rightFreqMap = new HashMap<>();
                for(var e : map.entrySet()){
                    int v = e.getKey();
                    if(v == cVal) continue;
                    List<Integer> posList = e.getValue();
                    int fLeft = countLess(posList, k);
                    if(fLeft > 0){
                        leftFreqMap.put(v, fLeft);
                    }
                    int fRight = countGreater(posList, k);
                    if(fRight > 0){
                        rightFreqMap.put(v, fRight);
                    }
                }

            long sumLeft = 0, sumSqLeft = 0;
            for(var e : leftFreqMap.entrySet()){
                long f = e.getValue();
                sumLeft += f;
                sumSqLeft += (f*f);
            }
            long sumRight = 0, sumSqRight = 0;
            for(var e : rightFreqMap.entrySet()){
                long f = e.getValue();
                sumRight += f;
                sumSqRight += (f*f);
            }

            sumLeft %= MOD; 
            sumRight %= MOD;
            sumSqLeft %= MOD;
            sumSqRight %= MOD;

            HashMap<Integer, Long> ways2DistinctExRight = new HashMap<>();
            for(var e : rightFreqMap.entrySet()){
                int v = e.getKey();
                long fv = e.getValue();
                long sr = (sumRight - fv + MOD) % MOD;
                long srSq = (sumSqRight - (fv*fv % MOD) + MOD) % MOD;
                long t = (sr*sr - srSq) % MOD;
                t = (t * inv2) % MOD;
                ways2DistinctExRight.put(v, (long)modFix(t));
            }
            long temp = ( (sumRight*sumRight) % MOD - sumSqRight + MOD ) % MOD;
            temp = (temp * inv2) % MOD;

            HashMap<Integer, Long> ways2DistinctExLeft = new HashMap<>();
            for(var e : leftFreqMap.entrySet()){
                int v = e.getKey();
                long fv = e.getValue();
                long sl = (sumLeft - fv + MOD) % MOD;
                long slSq = (sumSqLeft - (fv*fv % MOD) + MOD) % MOD;
                long t = (sl*sl - slSq) % MOD;
                t = (t * inv2) % MOD;
                ways2DistinctExLeft.put(v, (long)modFix(t));
            }
            long tempp = ( (sumLeft*sumLeft) % MOD - sumSqLeft + MOD ) % MOD;
            tempp = (tempp * inv2) % MOD;

            long f2Left = 0;
            if(leftC >= 1 && rightNonC >= 2){
                long chooseC = nCr[leftC][1];
                for(var e : leftFreqMap.entrySet()){
                    int v = e.getKey();
                    long freqV = e.getValue();
                    Long val = ways2DistinctExRight.get(v); 
                    long waysEx = (val == null ? temp : val);
                    long addMe = (freqV % MOD) * waysEx % MOD;
                    f2Left = (f2Left + addMe) % MOD;
                }
                f2Left = (f2Left * chooseC) % MOD;
            }

            long f2Right = 0;
            if(rightC >= 1 && leftNonC >= 2){
                long chooseC = nCr[rightC][1]; 
                for(var e : rightFreqMap.entrySet()){
                    int w = e.getKey();
                    long freqW = e.getValue();
                    Long val = ways2DistinctExLeft.get(w);
                    long waysEx = (val == null ? tempp : val);
                    long addMe = (freqW % MOD) * waysEx % MOD;
                    f2Right = (f2Right + addMe) % MOD;
                }
                f2Right = (f2Right * chooseC) % MOD;
            }

            long waysT2 = (f2Left + f2Right) % MOD;

            long totalForK = (waysT5 + waysT4 + waysT3 + waysT2) % MOD;
            ans = (ans + totalForK) % MOD;
        }

        return (int)ans;
    }

    long inv2 = modInverse(2, MOD);

    public long modInverse(long a, long m){
        return modExp(a, m-2, m);
    }
    public long modExp(long base, long exp, long m){
        long result = 1;
        long cur = base % m;
        long e = exp;
        while(e > 0){
            if((e & 1) == 1){
                result = (result * cur) % m;
            }
            cur = (cur * cur) % m;
            e >>= 1;
        }
        return result;
    }

    public int countLess(List<Integer> posList, int x){
        int lo = 0, hi = posList.size();
        while(lo < hi){
            int mid = (lo + hi) >>> 1;
            if(posList.get(mid) < x){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    public int countGreater(List<Integer> posList, int x){
        int lo = 0, hi = posList.size();
        while(lo < hi){
            int mid = (lo + hi) >>> 1;
            if(posList.get(mid) <= x){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return posList.size() - lo;
    }
}