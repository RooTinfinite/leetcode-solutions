#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<long long> colSum(n, 0);
        vector<vector<long long>> ops_ring(k, vector<long long>(n, 0));
        
        bool hasCandidate = false;
        long long candidateX = 0;
        
        long long sumOps0 = 0;
        long long sumOps1 = 0;
        long long minX = LLONG_MIN;
        
        for (int i = 0; i < m; ++i) {
            if (i >= k) {
                int evictRow = i % k;
                for (int j = 0; j < n; ++j) {
                    colSum[j] -= ops_ring[evictRow][j];
                    ops_ring[evictRow][j] = 0;
                }
            }
            
            long long window_sum = 0;
            for (int j = 0; j < n; ++j) {
                window_sum += colSum[j];
                long long req0 = -grid[i][j] - window_sum;
                
                if (i <= m - k && j <= n - k) {
                    ops_ring[i % k][j] = req0;
                    colSum[j] += req0;
                    window_sum += req0;
                    
                    long long o1 = (i % k == 0 && j % k == 0) ? 1 : 0;
                    sumOps0 += req0;
                    sumOps1 += o1;
                    
                    if (o1 == 1) {
                        if (-req0 > minX) minX = -req0;
                    } else {
                        if (req0 < 0) return -1;
                    }
                } else {
                    long long r0 = req0;
                    long long r1 = ((i / k) * k > m - k || (j / k) * k > n - k) ? 1 : 0;
                    
                    if (r1 != 0) {
                        long long x = -r0;
                        if (!hasCandidate) {
                            candidateX = x;
                            hasCandidate = true;
                        } else if (candidateX != x) {
                            return -1;
                        }
                    } else {
                        if (r0 != 0) return -1;
                    }
                }
                
                if (j >= k - 1) {
                    window_sum -= colSum[j - k + 1];
                }
            }
        }
        
        if (hasCandidate) {
            if (candidateX < minX) return -1;
        } else {
            candidateX = minX;
        }
        
        return sumOps0 + candidateX * sumOps1;
    }
};