class Solution {
public:
    vector<string>ans;
    int tot=0;
    void solve(int pos,int len,int k,bool flag,string &temp){
        if(k>tot)return;
        if(pos==len){
            ans.push_back(temp);
            return;
        }
        temp+='0';
        solve(pos+1,len,k,false,temp);
        temp.pop_back();
        if(flag==false){
            temp+='1';
            solve(pos+1,len,k+pos,true,temp);
            temp.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string temp;
        tot=k;
        solve(0,n,0,false,temp);
        return ans;
    }
};