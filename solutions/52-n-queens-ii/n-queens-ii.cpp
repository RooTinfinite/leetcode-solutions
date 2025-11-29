class Solution {
public:

void solve(int col,vector<string> &cur_board,vector<vector<string>> &ans,
    vector<int> &left_row,vector<int> &upper_dia,vector<int> &lower_dia,int n)
    {
        if(col==n)
        {
            ans.push_back(cur_board);
            return;
        }

        for(int row = 0;row<n;row++)
        {
            if(left_row[row]==0 and upper_dia[row+col]==0 and lower_dia[n-1 + col-row]==0)
            {
                cur_board[row][col]='Q';
                left_row[row]=1;
                upper_dia[row+col] = 1;
                lower_dia[n-1+col-row] = 1;

                solve( col+1,cur_board,ans,left_row,upper_dia,lower_dia, n);

                cur_board[row][col]='.';
                left_row[row] = 0;
                upper_dia[row+col] = 0;
                lower_dia[n-1+col-row] = 0;
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> cur_board(n);
        string s(n,'.');
        for (int i=0;i<n;i++)
        {
            cur_board[i]=s;
        }
        vector <int> left_row(n,0),upper_dia((2*n)-1,0),lower_dia((2*n)-1,0);

        solve(0,cur_board,ans,left_row,upper_dia,lower_dia,n);
        return ans.size();
    }
};