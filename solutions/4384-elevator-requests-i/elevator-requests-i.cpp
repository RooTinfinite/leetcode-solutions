class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int t=0, last=0;
        for(int r : requests){
            t+=abs(r-last);
            last=r;
        }
        return t;
    }
};