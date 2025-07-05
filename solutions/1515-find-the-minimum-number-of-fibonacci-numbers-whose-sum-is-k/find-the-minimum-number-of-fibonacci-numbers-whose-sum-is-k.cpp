class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>v;
        v.push_back(1);
        v.push_back(1);
        while(v.back()<k){
            v.push_back(v[v.size()-1] + v[v.size()-2]);
        }
        int count = 0;
        priority_queue<int>pq(v.begin(),v.end());
        while(k!=0){
            if(k>=pq.top()){
                k -= pq.top();
                count++;
            }
            else pq.pop();
        }
        return count;
    }
};