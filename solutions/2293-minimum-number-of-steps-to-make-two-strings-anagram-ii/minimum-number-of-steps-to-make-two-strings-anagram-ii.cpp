class Solution
{
public:
    int minSteps(string& s, string& t)
    {
        int list[26]={0};
        for(char c:s)
        {
            list[c-'a']++;
        }
        for(char c:t)
        {
            list[c-'a']--;
        }
        int ret=0;
        for(int i=0;i<26;i++)
        {
            ret+=abs(list[i]);
        }
        return ret;
    }
};