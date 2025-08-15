class DetectSquares { // 216 ms, faster than 66.67%
public:
    int cntPoints[1001][1001] = {};
    vector<pair<int, int>> points;

    void add(vector<int> p) {
        cntPoints[p[0]][p[1]]++;
        points.emplace_back(p[0], p[1]);
    }

    int count(vector<int> p1) {
        int x1 = p1[0], y1 = p1[1], ans = 0;
        for (auto& [x3, y3] : points) {
            if (abs(x1-x3) == 0 || abs(x1-x3) != abs(y1-y3))
                continue; // Skip empty square or invalid square point!
            ans += cntPoints[x1][y3] * cntPoints[x3][y1];
        }
        return ans;
    }
};