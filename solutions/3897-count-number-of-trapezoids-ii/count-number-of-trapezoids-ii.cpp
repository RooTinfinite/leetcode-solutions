#include <bits/stdc++.h>
#include <ranges>
#include <tuple>
using namespace std;


class Solution {
public:
    static const long long DEFAULT_SCALE = 1000000000LL;
    long long encodeFraction(long long x, long long y, long long bias = 2000, long long scale = DEFAULT_SCALE) {
        long long gcd = __gcd(x, y);
        x /= gcd;
        y /= gcd;
        return x + bias + (y + bias) * scale;
    }

    long long getAngle(double x1, double y1, double x2, double y2) {
        long long x = x2 - x1;
        long long y = y2 - y1;
        return encodeFraction(x, y);
    }

    long long getIntersection(double x1, double y1, double x2, double y2) {
        if (y1 == y2) {
            return encodeFraction(DEFAULT_SCALE / 10, y1);
        }
        // find intersection with x axis
        // y - y1 = (y2 - y1) / (x2 - x1) * (x - x1)
        // when y = 0
        // x = x1 - y1 * (x2 - x1) / (y2 - y1)
        // Make sure there are no error while dividing intergers
        return encodeFraction(x1 * (y2 - y1) - y1 * (x2 - x1), y2 - y1, 0);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        // m[angle][intersection][length] = count
        unordered_map<long long, unordered_map<long long, unordered_map<long long, long long>>> m;
        for (int i1 = 0; i1 < points.size(); i1++) {
            for (int i2 = i1 + 1; i2 < points.size(); i2++) {
                long long x1 = points[i1][0], y1 = points[i1][1];
                long long x2 = points[i2][0], y2 = points[i2][1];
                long long angle = getAngle(x1, y1, x2, y2);
                long long intersection = getIntersection(x1, y1, x2, y2);
                long long len = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                m[angle][intersection][len]++;
            }
        }
        long long trapezoidCount = 0;
        long long parallelogramCount = 0;
        for (auto it1 = m.begin(); it1 != m.end(); it1++) {
            auto [count, parallelogram] = countTrapezoids2(it1->second);
            trapezoidCount += count;
            parallelogramCount += parallelogram;
        }
        return trapezoidCount + parallelogramCount / 2;
    }

    pair<long long, long long> countTrapezoids2(unordered_map<long long, unordered_map<long long, long long>>& groupedByIntersectionM) {
        long long edgeCount = 0;
        for (auto& [intersection, groupedByLen] : groupedByIntersectionM) {
            for (auto& [len, c] : groupedByLen) {
                edgeCount += c;
            }
        }
        long long trapezoidCount = 0;
        for (auto& [intersection, groupedByLen] : groupedByIntersectionM) {
            int count = 0;
            for (auto& [len, c] : groupedByLen) {
                count += c;
            }
            trapezoidCount += count * (edgeCount - count);
            edgeCount -= count;
        }
        
        // Hanle parallelogram
        // groupByLen[length][intersection]
        unordered_map<long long, unordered_map<long long, long long>> groupByLenM;
        for (auto& [intersection, groupedByLen] : groupedByIntersectionM) {
            for (auto& [len, c] : groupedByLen) {
                groupByLenM[len][intersection] += c;
            }
        }
        long long parallelogramCount = 0;
        for (auto& [len, groupByIntersection] : groupByLenM) {
            int total = 0;
            for (auto& [intersection, c] : groupByIntersection) {
                total += c;
            }
            for (auto& [intersection, c] : groupByIntersection) {
                parallelogramCount += c * (total - c);
                total -= c;
            }
        }

        return {trapezoidCount - parallelogramCount, parallelogramCount};
    }
};