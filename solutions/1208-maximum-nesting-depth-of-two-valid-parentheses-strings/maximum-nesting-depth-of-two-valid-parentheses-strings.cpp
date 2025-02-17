class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>res;
        for(int i=0;i<seq.length();i+=2){
            if(seq[i]==seq[i+1]){
                res.insert(res.end(),{0,1}); // if two adjacents are same then add one one to both subsequence
            }
            else{
                res.insert(res.end(),{0,0}); // if two adjacents are different then add it to any one of them as it does not affects the final ans
            }
        }
        return res;
    }
};