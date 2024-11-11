class Solution {
    
    ArrayList<Integer> primes = new ArrayList<Integer>();
    
    public void getPrimes(){
        
        boolean[] visited = new boolean[10001];
        
        for(int i = 2; i <= 10000; i++){
            if(!visited[i]){
                visited[i] = true;
                primes.add(i);
                
                int j = i;
                while(j <= 10000){
                    visited[j] = true;
                    j += i;
                }
            }
        }
        
    }
    
    public boolean primeSubOperation(int[] nums) {
        getPrimes();
        
        for(int i = 0; i < nums.length; i++){
            int prime = 0;
            if(i == 0){
                for(int j : primes){
                    if(j >= nums[i]){
                        break;
                    }

                    prime = j;
                }

                nums[i] -= prime;

                // if(prime != 0)
                //     primes.remove((Integer)prime);
            }else{
                for(int j : primes){
                    if(j >= nums[i]){
                        break;
                    }

                    if(nums[i-1] < (nums[i] - j)){
                        prime = j;
                    }
                }

                nums[i] -= prime;

                // if(prime != 0)
                //     primes.remove((Integer)prime);
            }
        }

        System.out.println(Arrays.toString(nums));

        for(int i = 1; i < nums.length; i++){
            if(nums[i-1] >= nums[i]){
                return false;
            }
        }

        return true;
    }
}