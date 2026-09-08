class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        // sort items using the custom comparator      
        sort(items.begin(), items.end(),
            [](const vector<int> &a, const vector<int> &b) {
                if (a[0] != b[0])
                // item with lower id goes first
                return a[0] < b[0];
                // in case of tie for ids, item with higher score goes first 
                return a[1] > b[1];
            });
        vector<vector<int>> solution;
        int n = items.size();
        int i = 0;
        while (i < n) {
            int id = items[i][0];
            int sum = 0;
            // obtain total using the top 5 scores
            for (int k = i; k < i + this->K; ++k)
                sum += items[k][1];
            // ignore all the other scores for the same id
            while (i < n && items[i][0] == id)
                i++;
            solution.push_back({id, sum / this->K});
        }
        return solution;
    }
};