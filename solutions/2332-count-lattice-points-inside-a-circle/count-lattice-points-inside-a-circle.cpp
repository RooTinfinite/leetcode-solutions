class Solution {
public:
    int countLatticePoints(vector<vector<int>>& v) { // v is vector of circles.
        int n = v.size();
        int ans = 0;
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                for(int k=0;k<n;k++){
                    int x=v[k][0],y=v[k][1],r=v[k][2];
                    if((x-i)*(x-i) + (y-j)*(y-j) <= r*r){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};