class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        queue<pair<int,int>> q;
        q.emplace(tx,ty);
        int count = 0;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x == sx and y == sy) return count;
            if(x > y){
                if(x > 2*y){
                    if(x%2 == 0){
                        if(x/2 >= sx){
                            q.emplace(x/2,y);
                        }
                    }
                }else{
                    if(x-y >= sx){
                        q.emplace(x-y,y);
                    }
                }
            }else if(y > x){
                if(y > 2*x){
                    if(y%2 == 0){
                        if(y/2 >= sy){
                            q.emplace(x,y/2);
                        }
                    }
                }else{
                    if(y-x >= sy){
                        q.emplace(x,y-x);
                    }
                }
            }else{
                if(sx == 0){
                    q.emplace(0,y);
                }
                if(sy == 0){
                    q.emplace(x,0);
                }
            }
            count++;
        }
        return -1;
    }
};