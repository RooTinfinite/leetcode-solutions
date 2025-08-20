class Solution {
public:
    int minimumBuckets(string s) {
        if(s.length()==1){
            if(s[0]=='H') return -1;
            else return 0;
        }
        int count = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(i!=0 and i!=n-1 and s[i]=='H' and s[i+1]=='H' and s[i-1]=='H') return -1;
            if(i==0 and s[i]=='H' and s[i+1]=='H') return -1;
            if(i==n-1 and s[i-1]=='H' and s[i]=='H') return -1;
        }
        for(int i=0;i<n;i++){
            if(i==0 and s[i]=='H'){
                s[i+1]='B';
                count++;
            }
            else if(s[i]=='H' and s[i-1]!='B'){
                if(i+1<n and s[i+1]!='H'){
                    count++;
                    s[i+1]='B';
                }
                else{
                    count++;
                    s[i-1] = 'B';
                }
            }
        }
        return count;
    }
};