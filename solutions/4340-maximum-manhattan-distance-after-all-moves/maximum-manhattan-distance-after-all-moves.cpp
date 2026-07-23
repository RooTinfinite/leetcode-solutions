class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,ct=0;
        for(int i=0;i<moves.size();i++){
            char ch=moves[i];
            if(ch=='L'){
                x+=-1;
            }
            else if(ch=='R')x+=1;
            else if(ch=='D')y-=1;
            else if(ch=='U')y+=1;
            else ct++;
        }
        int ans=(abs(x)+abs(y));
        return ans+ct;
    }
};