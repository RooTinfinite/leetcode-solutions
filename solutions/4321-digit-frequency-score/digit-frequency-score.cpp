class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;

        while(n>0){
            int dig=n%10;
            mp[dig]++;
            n/=10;
        }

        int sum=0;
        for(auto it : mp){
            sum+= it.first*it.second;
        }

        return sum;
    }
};