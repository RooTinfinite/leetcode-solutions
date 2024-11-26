class CombinationIterator {
public:
    vector<string> v;
    int k = 0;
    void solve(string s,string p,int i,int len)
    {
       if(p.size()==len) 
       {
           v.push_back(p);
           return ;
       }
       if(i>=s.size()) return ;
       p.push_back(s[i]);
       solve(s,p,i+1,len);
       p.pop_back();
       solve(s,p,i+1,len);
    }
    CombinationIterator(string s, int len) {
        solve(s,"",0,len);
    }
    string next() {
        if(hasNext())  return v[k++];  
        return "";
    }
    bool hasNext() {
        if(k>v.size()-1) return false;
        return true;
    }
};