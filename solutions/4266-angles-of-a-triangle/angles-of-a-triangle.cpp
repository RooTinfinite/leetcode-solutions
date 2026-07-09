class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        /*
        sum of two sides should be greater than third

        cos(A) = (b^2+c^2-a^2) /(2bc)
        */

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        // triangle inequality check (positive area)
        if (a + b <= c || b + c <= a || c + a <= b)
            return {};

        // Law of Cosines
        double A = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI;
        double B = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI;
        double C = acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / M_PI;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());
        return ans;
    }
};