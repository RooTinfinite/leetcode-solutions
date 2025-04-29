class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int k = mat1[0].size();
        int m = mat2[0].size();
        
        // Product matrix will have 'n x m' size.
        vector<vector<int>> ans (n, vector<int>(m, 0));
        
        for (int rowIndex = 0; rowIndex < n; ++rowIndex) {
            for (int elementIndex = 0; elementIndex < k; ++elementIndex) {
                // If current element of mat1 is non-zero then iterate over all columns of mat2.
                if (mat1[rowIndex][elementIndex] != 0)  {
                    for (int colIndex = 0; colIndex < m; ++colIndex) {
                        ans[rowIndex][colIndex] += mat1[rowIndex][elementIndex] * mat2[elementIndex][colIndex];
                    }
                }
            }
        }
        
        return ans;
    }
};