class Solution {
public:
    int numberOfSpecialChars(string word) {
        int or_lower = 0, or_upper = 0;
        for(char ch : word){
            if(islower(ch)){
                or_lower |= (1<< (ch-'a'));
            }else{
                or_upper |= (1<< (ch-'A'));
            }
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(or_lower & (1<<i) && or_upper & (1<<i)) ans++;
        }
        
        return ans;
    }
};