class Solution {
public:
    string finalString(string s) {
        string res="";
        deque<char> dq;
        bool rev=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='i'){
               rev=!rev;
            }
            else {
                if(rev){
                    dq.push_front(s[i]);
                }
                else{
                    dq.push_back(s[i]);
                }
            }
        }

        while(!dq.empty()){
            if(rev){
                res+=dq.back();
                dq.pop_back();
            }
            else{
                res+=dq.front();
                dq.pop_front();
            }
        }

        return res;
    }
};