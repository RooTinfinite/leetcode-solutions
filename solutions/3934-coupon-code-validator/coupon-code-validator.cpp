class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> validCoupons;
        unordered_set<string> categories = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (int i = 0; i < n; ++i) {
            bool charValid = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    charValid = false;
                    break;
                }
            }
            if (isActive[i] && (code[i].length() > 0) && charValid && (categories.count(businessLine[i]) > 0)) {
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }

        ranges::sort(validCoupons);

        vector<string> result;
        for (auto [bline, couponCode] : validCoupons) {
            result.push_back(couponCode);
        }

        return result;
    }
};