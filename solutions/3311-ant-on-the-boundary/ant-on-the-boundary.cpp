class Solution {
public:
    int returnToBoundaryCount(vector<int>& v) {
        int s=0,c=0;
        for(auto i:v) {
            s=s+i;
            if(s==0)
                c++;
        }
        return c;
    }
};