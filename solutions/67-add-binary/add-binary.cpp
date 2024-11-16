class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;

        while(i>=0||j>=0){
            char current='0';

            if(i>=0){if(a[i]=='1'){current++;}}
            if(j>=0){if(b[j]=='1'){current++;}}
            if(carry=='1'){
                current++;
                carry='0';
            }

            if(current=='0' || current=='1'){ans+=current;}   
            else if(current=='2'){
                ans+='0';
                carry='1';
            }
            else if(current=='3'){
                ans+='1';
                carry='1';
            }
            i--;
            j--; 
        }

        if(carry=='1'){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};