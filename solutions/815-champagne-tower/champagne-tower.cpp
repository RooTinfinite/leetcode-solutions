double A[2][102];// as global variable
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured==0) return 0;
        // reset to 0 only for needs
        memset(A[0], 0, (query_row+2)*sizeof(double));
    
        A[0][0]=poured; //poured
        for(int i=0; i<query_row; i++){
            // consider the parities for the current i & the next one
            bool cur=i&1, nxt=!cur;
            // clear the next row
            memset(A[nxt], 0, (i+2)*sizeof(double));
            for(int j=0; j<=i; j++){
                double A_ij=A[cur][j];
                if ( A_ij<=1) continue;
                double excess=(A_ij-1)/2.0;
                A[nxt][j]+=excess;
                A[nxt][j+1]+=excess;
            }
        }
        // query_row&1
        return min(1.0, A[query_row&1][query_glass]);
    }
};