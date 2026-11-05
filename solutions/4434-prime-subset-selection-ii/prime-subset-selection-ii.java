class Solution {
    int INF = Integer.MAX_VALUE;
    int[][]dp;

    public List<Integer> maxPrimeSubset(int n, int s) {
        
        List<Integer> primes = getPrimes(n);

        dp = new int[primes.size()+1][s+1];

        for(int[]row: dp){
            Arrays.fill(row, -1);
        }

        int target = s;
        int minCount = INF;
        while(target >= 0){
            minCount = minPrimes(0, primes, target);
            if(minCount != INF){
                break;
            }
            target--;
        }

        int remSum = target;
        int remCount = minCount;
        List<Integer> ans = new ArrayList<>();

        for(int i=0; i<primes.size(); i++){
            if(remSum >= primes.get(i) && minPrimes(i+1, primes, remSum-primes.get(i)) == remCount-1){
                ans.add(primes.get(i));
                remSum-= primes.get(i);
                remCount--;
            }
        }

        return ans;
    }

    public int minPrimes(int idx, List<Integer> primes, int target){

        if(target == 0) return 0;
        if(idx == primes.size()) return INF;

        if(dp[idx][target] != -1) return dp[idx][target];

        int result = minPrimes(idx+1, primes, target);

        if(primes.get(idx) <= target){
            int next = minPrimes(idx+1, primes, target - primes.get(idx));

            if(next != INF){
                result = Math.min(result, 1 + next);
            }
        }

        return dp[idx][target] = result;
    }

    private List<Integer> getPrimes(int n){
        boolean []isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);

        for(int k=2; k*k<=n; k++){
            if(isPrime[k]){
                for(int i=k*k; i<=n; i+=k){
                    isPrime[i] = false;
                }
            }
        }

        List<Integer> primes = new ArrayList<>();
        for(int i=2; i<=n; i++){
            if(isPrime[i]) primes.add(i);
        }

        return primes;

    }
}