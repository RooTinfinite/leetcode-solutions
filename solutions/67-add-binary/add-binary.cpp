class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) {
            swap(a,b);
        }
        int i, j;
        for(i = b.size()-1, j = a.size()-1; i>=0; i--, j--) {
            a[j]+=b[i]-'0';
            if(j==0) {
                break;
            }
            while(a[j]>'1') {
                a[j-1]+=1;
                a[j]-=2;
            }
        }
        for(;j>0; j--) {
            while(a[j]>'1') {
                a[j-1]+=1;
                a[j]-=2;
            }
        }
        if(a[0]!='0' && a[0]!='1') {
            a[0]-=2;
            a = '1'+a;

        }
        return a;
    }
};