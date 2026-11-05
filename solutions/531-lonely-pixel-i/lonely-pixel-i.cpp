
class Solution {
public:
    // Returns true if the cell at (x, y) is lonely.
    // There should not be any other black cell 
    // In the first row and column except (x, y) itself.
    bool check(vector<vector<char>>& picture, int x, int y) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (picture[i][y] == 'B');
        }
        
        for (int j = 0; j < m; j++) {
            // avoid double count (x, y)
            if (j != y) cnt += (picture[x][j] == 'B');
        }
        return picture[x][y] == 'B' && cnt == 1;
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        int answer = 0;
        // Lonely cells in the first row
        for (int j = 0; j < m; j++) {
            answer += check(picture, 0, j);
        }
        //Lonely cells in the first column
        for (int i = 1; i < n; i++) {
            answer += check(picture, i, 0);
        }

        // Convert cell 'B' to '1' and 'W' to '0'
        for (int j = 0; j < m; j++) {
            picture[0][j] = (picture[0][j] == 'B' ? '1' : '0');
        }
        
        for (int i = 0; i < n; i++) {
            picture[i][0] = (picture[i][0] == 'B' ? '1' : '0');
        }
        
        // If the cell is black increment the count of corresponding row and column by 1
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    picture[i][0]++;
                    picture[0][j]++;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    if (picture[0][j] == '1' && picture[i][0] == '1') {
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
};