class Solution {
public:
    bool validDigit(int n, int x) {
        int c=0,f=0;
        while(n){
            if(n<10 and n!=x) f=1;
            int d = n%10;
            if(d==x) c++;
            n/=10;
        }
        return c and f;
    }
};