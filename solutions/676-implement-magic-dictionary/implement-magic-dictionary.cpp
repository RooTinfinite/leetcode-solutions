class MagicDictionary {
public:
    unordered_set<string>st;
    MagicDictionary() {
        st.clear();
    }
    
    void buildDict(vector<string> arr) {
        for(int i=0;i<arr.size();i++)
        {
            st.insert(arr[i]);
        }
    }
    
    bool search(string s) {
        for(int i=0;i<s.length();i++)
        {
            string temp=s;
            for(int k=0;k<26;k++)
            {
                char curr_char=char(k+'a');
                if(curr_char!=s[i])
                {
                    temp[i]=char(k+'a');
                    if(st.find(temp)!=st.end())
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
