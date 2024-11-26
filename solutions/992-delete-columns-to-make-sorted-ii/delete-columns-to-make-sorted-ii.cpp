class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        
        int n=str.size();
        int m=str[0].size();
        
        vector<string>vec(n,""); //To store string in lexicographical order
       
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                vec[j]+=str[j][i]; //Adding one character from each row 
            }
          
            int var=1;
            
            for(int j=1;j<n;j++)
            {
                if(vec[j]<vec[j-1]) // Checking if all string are in lexicographical order or not
                {
                    var=-1;
                    break;
                }
            }
            
            if(var==-1) // If string are not in lexicographical order then we willl remove current added elemet from all strings
            {
                for(int j=0;j<n;j++)
                {
                    vec[j].pop_back();
                }
            }
        }
        
        
        return m-vec[0].size();
    }
};