class Solution {
 public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double> pq(nums.begin(),nums.end());
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        double temp = sum;
        int cnt=0;
        while(temp>sum/2){
            
            double a = pq.top(); pq.pop();
            
            temp-=a;
            
            a=a/2;
            temp+=a;
           
            pq.push(a);
            cnt++;
            
        }
        return cnt;
    }
};