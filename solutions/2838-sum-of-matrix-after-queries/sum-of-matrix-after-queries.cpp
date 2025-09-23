class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int rowCount = n, colCount = n;
        vector<bool> rowSeen(n , false), colSeen(n , false);
        long long sum = 0;
        for(int i = queries.size() - 1; i >= 0; --i){
            int type = queries[i][0], index = queries[i][1], val = queries[i][2];
            if(!type && !rowSeen[index]){
                --rowCount;
                rowSeen[index] = true;
                sum += 1LL * colCount * val; 
            }
            if(type && !colSeen[index]){
                --colCount;
                colSeen[index] = true;
                sum += 1LL * rowCount * val;
            }
        }
        return sum;
    }
};