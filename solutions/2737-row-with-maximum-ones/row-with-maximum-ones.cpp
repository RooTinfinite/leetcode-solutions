class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = 0;
        int index = 0;
        for(int i = 0; i < mat.size(); i++){
            int countOnes = 0;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                     countOnes++;
                }
            }
            if(countOnes > maxi){
                maxi = countOnes;
                index = i;
            }
        }
        return {index, maxi};
    }
};