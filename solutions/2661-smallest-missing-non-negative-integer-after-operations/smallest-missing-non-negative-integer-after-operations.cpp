class Solution {
public:
    int findSmallestInteger(vector<int>& v, int value) {
        unordered_map<int,int> moduloCounter;
        for(int x : v) {
            moduloCounter[((x % value) + value) % value] += 1;
        }
        for(int i = 0; i <= v.size(); i += 1) {
            int rem = i % value;
            if(moduloCounter.count(rem) && moduloCounter[rem] > 0) moduloCounter[rem] -= 1;
            else return i;
            
        }
        return 0;
    }
};