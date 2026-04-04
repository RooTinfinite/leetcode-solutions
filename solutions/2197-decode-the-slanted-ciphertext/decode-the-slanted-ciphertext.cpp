class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) 
    {
        if(encodedText.empty())
        {
            return "";
        }
        
        string ans = "";
        int cols = encodedText.size()/rows;
        int i = 0;
        int j = 0;
        int n = rows;
        int m = cols;

        while(j<m)
        {
            int l = i;
            int r = j;
            while(l<n && r<m)
            {
                int id = (m*l) + r;
                ans+=encodedText[id];
                l++;
                r++;
            }
            j++;
        }

        int id = ans.length()-1;
        while(ans[id]==' ' && id>=0)
        {
            id--;
        }
        id++;

        return ans.substr(0,id);
    }
};