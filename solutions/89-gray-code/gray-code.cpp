class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        // there are 2 ^ n numbers in the Gray code sequence.
        int sequenceLength = 1 << n;
        for (int i = 0; i < sequenceLength; i++) {
            int num = i ^ i >> 1;
            result.push_back(num);
        }
        return result;
    }
};