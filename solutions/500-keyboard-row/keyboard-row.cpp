class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char, int> umap;
        int flag;
        int temp;
        for(auto x:"qwertyuiop")
        {
            umap[x]+=1;
        }
        for(auto x:"asdfghjkl")
        {
            umap[x]+=2;
        }
        for(auto x:"zxcvbnm")
        {
            umap[x]+=3;
        }
        for(auto w:words)
        {
            flag=umap[tolower(w[0])];
            temp=0;
            for(auto x:w)
            {
                if(umap[tolower(x)] != flag) //umap.find(key) != umap.end()
                {
                    temp=1;
                    break;
                }
            }
            if(temp==0)
            {
                res.push_back(w);
            }
        }
        return res;
    }
};