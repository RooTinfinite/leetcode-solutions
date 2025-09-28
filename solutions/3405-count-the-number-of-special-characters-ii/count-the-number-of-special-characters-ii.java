class Solution {
    public int numberOfSpecialChars(String word) {
        int a[][] = new int[26][2];
        int b[][] = new int[26][2];
        for(int i=0;i<26;i++)
        {
            b[i][1]=-1;
        }
        for(int i=0;i<word.length();i++)
        {
            char c = word.charAt(i);
            if(c>='a' && c<='z')
            {
                a[c-'a'][0]++;
                a[c-'a'][1]=i;
            }
            else
            {
                b[c-'A'][0]++;
                if(b[c-'A'][1] == -1)
                {
                    b[c-'A'][1]=i;
                }
            }
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(a[i][0] != 0 && b[i][0] != 0 && a[i][1] < b[i][1])
            {
                count++;
            }
        }
        return count;
    }
}