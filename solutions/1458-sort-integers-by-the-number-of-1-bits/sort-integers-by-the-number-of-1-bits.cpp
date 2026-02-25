class Solution {
public:
    static int findWeight(int num) {
        int mask = 1;
        int weight = 0;
        
        while (num > 0) {
            if ((num & mask) > 0) {
                weight++;
                num ^= mask;
            }
            
            mask <<= 1;
        }
        
        return weight;
    }
    
    static bool compare(int a, int b) {
        if (findWeight(a) == findWeight(b)) {
            return a < b;
        }
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};