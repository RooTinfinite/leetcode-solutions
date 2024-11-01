class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        unordered_set<int> placedCol;
        unordered_set<int> placedPos;
        unordered_set<int> placedNeg;
        
        function<void(int)> backtrack = [&](int r) {
            if (r == n) {
                ans.push_back(board);
                return;
            }
            
            for (int c = 0; c < n; c++) {
                if (placedCol.count(c) || placedPos.count(r + c) || placedNeg.count(r - c)) {
                    continue;
                }
                
                board[r][c] = 'Q';
                placedCol.insert(c);
                placedPos.insert(r + c);
                placedNeg.insert(r - c);
                
                backtrack(r + 1);
                
                board[r][c] = '.';
                placedCol.erase(c);
                placedPos.erase(r + c);
                placedNeg.erase(r - c);
            }
        };
        
        backtrack(0);
        return ans;
    }
};