class Solution {
public:
    int addMinimum(string word)
    {
        int n = word.size(), ans = 0;
        int i = 0;
        while(i < n)
        {
            //getting the character indexes
            int curr = word[i] - 'a';
            int next = (i + 1 >= n)? -1 : word[i + 1] - 'a';
            int nextToNext = (i + 2 >= n)? -1 : word[i + 2] - 'a';
            
            if (curr < next && next < nextToNext) { i += 3; }  //"abc"
            else if (curr < next) { ans++; i += 2; } //"ab" or "ac" or "bc"
            else { ans += 2; i++; } //"a" or "b" or "c"
        }
        return ans;
    }
};