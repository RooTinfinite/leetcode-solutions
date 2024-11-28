using int2 = pair<int, int>; 
const static int d[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m) {
        return i * m + j;
    }

    static int minimumObstacles(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size(), N=100000;
        unsigned dist[N];
        fill(dist, dist + n*m, INT_MAX);

        int2 q[N]; 
        int back = N/2, front = N/2; 

        q[back++] = {0, 0}; 
        dist[0] = 0;

        while (back != front) {
            auto [currD, ij] = q[front]; 
            front=(front==N-1)?0:front+1;
            auto [i, j] = div(ij, m);

            if (i == n - 1 && j == m - 1)
                return currD;

            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                int nextD = currD + grid[r][s];
                int rs = idx(r, s, m);

                if (nextD < dist[rs]) {
                    dist[rs] = nextD;
                    int2 next = {dist[rs], rs};

                    if (grid[r][s] == 0) {
                        front=(front==0)?N-1:front-1;
                        q[front] = next; 
                    } 
                    else {
                        q[back] = next; 
                        back=(back==N-1)?0:back+1;
                    }
                }
            }
        }
        return -1;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'a';
}();