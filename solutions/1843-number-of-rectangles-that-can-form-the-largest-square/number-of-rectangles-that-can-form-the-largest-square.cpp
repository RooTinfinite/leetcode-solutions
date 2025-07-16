class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& v){
        unordered_map<int,int> m;

        for(int i=0;i<v.size();i++){
            m[min(v[i][0],v[i][1])]++;
        }

        int a=INT_MIN,b=-1;
        for(auto x : m){
            if(x.first>a){
                a=x.first;
                b=x.second;
            }
        }
        
        return b;
    }
};