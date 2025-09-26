class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {        
        
        // horizontal and vertical four directions 
        for (auto direction : vector<vector<int>> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int dx = direction[0];
            int dy = direction[1];
            for (int i = 1; i < 8; ++i) {
                //  if we spot bishop just break, because the rook may be in a blind spot to queen. no need to check further
                if (e + i * dx == c && f + i * dy == d) {
                    break;
                }
                // if we spot rook , we can capture queen in 1 move
                if (e + i * dx == a && f + i * dy == b) {
                    return 1;
                }
            }
        }
        // horizontal and vertical four directions 
        for (auto direction : vector<vector<int>> {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}}) {
            int dx = direction[0];
            int dy = direction[1];
            // move in diagonal four directions 
            for (int i = 1; i < 8; ++i) {
                //  if we spot rook just break, because the bishop may be in a blind spot. no need to check further
                if (e + i * dx == a && f + i * dy == b) {
                    break;
                }
                //  if we spot bishop , we can capture queen in 1 move
                if (e + i * dx == c && f + i * dy == d) {
                    return 1;
                }
            }
        }

        return 2;
    }
};