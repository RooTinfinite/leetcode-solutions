class Solution {
public:
 int countPrimeSetBits(int l, int r) {
 set<int> p = { 2, 3, 5, 7, 11, 13, 17, 19};// max possible prime no. 19.Because of range is 10^6  
        int x=0;
        while((r-l+1)!=0){
        int i=0;
        int y=l;// here we put the value to y because if you use l as code than value of l change.....
        while(y!=0){
        i+=(y&1);
        y=y>>1;
         }
        x+=p.count(i);
        l++;
        }
        return x;
  }
};