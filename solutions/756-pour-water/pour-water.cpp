class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        stack<int> leftFall, rightFall;
        int leftBoundary = K, rightBoundary = K;
        for (int step = 0; step < V; ++step) {
            while (leftBoundary > 0 &&
                   heights[leftBoundary - 1] <= heights[leftBoundary]) {
                --leftBoundary;
                if (heights[leftBoundary] < heights[leftBoundary + 1])
                    leftFall.push(leftBoundary);
            }
            while (rightBoundary < heights.size() - 1 &&
                   heights[rightBoundary + 1] <= heights[rightBoundary]) {
                ++rightBoundary;
                if (heights[rightBoundary] < heights[rightBoundary - 1])
                    rightFall.push(rightBoundary);
            }
            if (!leftFall.empty()) {
                int leftmostFall = leftFall.top();
                ++heights[leftmostFall];
                if (heights[leftmostFall] == heights[leftmostFall + 1])
                    leftFall.pop();
                if (leftmostFall > leftBoundary)
                    leftFall.push(leftmostFall - 1);
            } else if (!rightFall.empty()) {
                int rightmostFall = rightFall.top();
                ++heights[rightmostFall];
                if (heights[rightmostFall] == heights[rightmostFall - 1])
                    rightFall.pop();
                if (rightmostFall < rightBoundary)
                    rightFall.push(rightmostFall + 1);
            } else {
                ++heights[K];
                if (K > leftBoundary)
                    leftFall.push(K - 1);
                if (K < rightBoundary)
                    rightFall.push(K + 1);
            }
        }
        return heights;
    }
};