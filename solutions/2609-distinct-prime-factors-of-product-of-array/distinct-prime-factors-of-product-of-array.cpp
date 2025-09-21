class Solution {
private:
    vector<int> preCalc(int n){
        vector<int> prime(n+1, 0);
        int pr = 2;
        while(pr * pr<= n){
            if(prime[pr]== 0){
                for (int i=2*pr; i<n+1; i=i+pr)
                        prime[i]= 1;
            }
            pr++;
          }


        vector<int> ans;
        for (int i=2; i<n; i++) 
            if (prime[i]==0) 
                ans.push_back(i);
        
        return ans;
    }
public:
    
    int helper(vector<int>&arr, vector<int>& Pans){
        int ctr = 0;
        for(int p : Pans){
            for(int val : arr){
                if(val%p == 0){
                    ctr++;
                    break;
                }
            }
        }
        return ctr;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> Pans = preCalc(1001);
        return helper(nums, Pans);
 
        
        
    }
};