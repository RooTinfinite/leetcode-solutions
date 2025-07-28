class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        vector<int> store;
        for (int i = 0; i < queries.size(); i++) {
            int h = queries[i][0];
            int k = queries[i][1];
            int r = queries[i][2];

            int count = 0;
            for (int j = 0; j < points.size(); j++) {
                int a = points[j][0];
                int b = points[j][1];

                if (pow((a - h), 2) + pow((b - k), 2) <= pow(r, 2)) {
                    count += 1;
                }
            }

            store.push_back(count);
        }

        return store;
    }
};