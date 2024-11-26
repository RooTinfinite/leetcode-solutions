class Solution {
public:
    bool isValid(string s) 
    {
        int idx = s.find("abc");
        while(idx != -1)
        {
            s.erase(idx, 3);
            idx = s.find("abc");
        }
        return s.empty();
    }
};