class Solution {
public:
    int gaussianSum(int n) {
        return (n + 1) * n / 2;
    }
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        // setting up necessary variables
        int countLoops = 0, partialSum = gaussianSum(n), squaredN = n * n, numberOfNs, i, nextValue;
        // computing how many full loops we can get
        while (partialSum <= candies) {
            countLoops++;
            candies -= partialSum;
            partialSum += squaredN;
        }
        // filling the vector with the full runs
        numberOfNs = gaussianSum(countLoops - 1);
        for (i = 0; i < res.size(); i++) res[i] =  numberOfNs * n + (i + 1) * (countLoops);
        // adding residual values to each cell as long as we can proceed like that
        nextValue = min(candies, countLoops * n + 1);
        i = 0;
        while (candies) {
            candies -= nextValue;
            res[i++] += nextValue;
            nextValue = min(candies, nextValue + 1);
        }
        return res;
    }
};