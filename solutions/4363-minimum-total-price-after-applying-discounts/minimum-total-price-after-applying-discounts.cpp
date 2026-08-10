class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int p1 = prices.size() - 1;
        int p2 = discounts.size() - 1;

        double sum = 0;

        while(p1 >= 0 && p2 >= 0){
            sum += prices[p1] * (100.0 - discounts[p2]) / 100.0;
            p1--;
            p2--;
        }

        while(p1 >= 0){
            sum += prices[p1--];
        }

        return sum;
    }
};