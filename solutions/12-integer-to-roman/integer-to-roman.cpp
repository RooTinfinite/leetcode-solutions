class Solution {
public:
    string intToRoman(int num) {
        int n[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string str;
        int i =0;
        while(num>0){
            if(num>=n[i]){
                str+=s[i];
                num-=n[i];
            }
            else ++i;
        }
        return str;
    }
};