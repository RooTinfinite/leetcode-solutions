//C++ Code
// Start Of Edwards310's Template...

#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (int a = b; a < c; a++)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

// end of Edwards310's Template
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int sum = 0, cnt = 0, len = arr.size();
        SORT(arr);
        int percent5 = len / 20;
        FOR(i, percent5, len - percent5){
            sum += arr[i];
            cnt++;
        }
        return (double)sum / cnt;
    }
};