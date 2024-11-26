class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int ca =0;
        int cb = 0;
        int times = max(a,b);
        
        string ans="";

       

        if(a>b){
           for(int i=0;i<times;i++){
          ans+="ab";
        }
          int bs = abs(b-a);
       //   cout<<ans<<endl;
          for(int i=1;i<ans.length();i=i+4){
            ans[i] = 'r';
            bs--;
            cout<<bs<<" ";
            if(bs == 0){
              break;
            }
          }
          if(bs>0){
            for(int i = ans.length()-1;i>=0;i--){
              if(ans[i] == 'b'){
                 ans[i] = 'r';
                  bs--;
              }
              if(bs == 0){
                break;
              }
            }
          }
      //  cout<<ans;
        string temp = "";
        for(int i=0;i<ans.length();i++){
          if(ans[i] == 'r'){continue;}
          temp+=ans[i];
          }
          ans = temp;
        }else if(b>a){
           for(int i=0;i<times;i++){
               ans+="ba";
        }
           int as = abs(b-a);
       //   cout<<ans<<endl;
          for(int i=1;i<ans.length();i=i+4){
            ans[i] = 'r';
            as--;
            //cout<<as<<" ";
            if(as == 0){
              break;
            }
          }
          if(as>0){
            for(int i = ans.length()-1;i>=0;i--){
              if(ans[i] == 'a'){
                 ans[i] = 'r';
                  as--;
              }
              if(as == 0){
                break;
              }
            }
          }
      //  cout<<ans;
        string temp = "";
        for(int i=0;i<ans.length();i++){
          if(ans[i] == 'r'){continue;}
          temp+=ans[i];
          }
          ans = temp;
        }else{
    for(int i=0;i<times;i++){
          ans+="ab";
        }
        }

        return ans;
    }
};