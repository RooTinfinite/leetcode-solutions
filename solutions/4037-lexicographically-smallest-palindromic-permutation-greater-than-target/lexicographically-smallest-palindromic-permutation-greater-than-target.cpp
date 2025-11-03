class Solution {
public:
    string ans;

    bool func(vector<char>& path,vector<int>& cnt,string & target, bool big,char mid,int n){
        if(!ans.empty())return true;
        int half=n/2;
        if(path.size()==half){
            string left(path.begin(),path.end());
            string right=left;
            reverse(right.begin(),right.end());
            string pal="";
            if(n%2!=0)pal=left+mid+right;
            else pal=left+right;
            if(pal>target){
                ans=pal;
                return true;
            }
            return false;
        }
        int i=path.size();
        for(int c=0;c<26;c++){
            if(cnt[c]==0)continue;
            if(!big && c+'a'<target[i])continue;

            path.push_back(c+'a');
            cnt[c]--;
            bool newbig=big || (c+'a' >target[i]);
            if(func(path,cnt,target,newbig,mid,n))return true;
            path.pop_back();
            cnt[c]++;
        }
        return false;
    }

    
    string lexPalindromicPermutation(string s, string target) {
        vector<int>cnt(26,0);
        for(char c:s)cnt[c-'a']++;
        ans="";
        int odd=0;
        char mid=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2){
            odd++;
            mid='a'+i ;   
            }
            cnt[i]/=2;
        }
        if(odd>1)return "";
        vector<char>path;
        func(path,cnt,target,false,mid,s.size());
        return ans;
    }
};