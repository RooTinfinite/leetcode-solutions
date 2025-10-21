class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int res = 0;
        for (const int& d : daysLate) {
            if (d == 1)
                res++;
            else if (d >= 2 && d <= 5)
                res += (2 * d);
            else
                res += (3 * d);
        }
        return res;
    }
};