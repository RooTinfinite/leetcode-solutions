class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
      vector<int>v(2,0);
      int h=max(c,max(a,b));
      int mn=min(c,min(a,b));
      int mid;
      if(a==h){
        mid=max(b,c);
      }else if(b==h){
        mid=max(a,c);
      }else{
        mid=max(a,b);
      }
    if(mn+1==mid && mid+1==h)
    return v;
    int x=0,y=0;
    if((h-mid)<=2 || (mid-mn)<=2){
        x=1;
        y=(h-mid)+(mid-mn)-2;
        v[0]=x;
        v[1]=y;
    }else{
        x=2;
         y=(h-mid)+(mid-mn)-2;
        v[0]=x;
        v[1]=y;
    }
      return v;  
    }
};