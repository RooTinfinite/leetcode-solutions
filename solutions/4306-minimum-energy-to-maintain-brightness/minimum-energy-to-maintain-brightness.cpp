class Solution {
public:
    long long minEnergy(int n, int br, vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        long long at=0;
        long long st=i[0][0],end=i[0][1];
        for(int x=0;x<i.size();x++){
            if(i[x][0]<=end){
                end=max(end,(long long)i[x][1]);
            }
            else{
                at+=end-st+1;
                st=i[x][0];
                end=i[x][1];
            }
        }
        at+=end-st+1;
        long long need=(br+2)/3;
        return need*at;
    }
};