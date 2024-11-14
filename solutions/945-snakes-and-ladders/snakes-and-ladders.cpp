typedef pair<int,int> Pi;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows=board.size(), cols = board[0].size(), target=rows*cols, r, c, p;
        vector<int> visited(rows*cols + 1); // cells on board start from 1
        // queue contains <priority, square> sorted ascending by priority
        // prio = #steps * 1000 + (500 - square);
        // number of steps is critical and adds 1000; 500 is selected as it is higher than the max cell (20*20=400)
        priority_queue<Pi, vector<Pi>, greater<Pi>> q;
        q.push(make_pair(0,1)); // 0 steps to position 1
        visited[1] = true;
        while(q.size())
        {
            auto step_pos = q.top(); q.pop();
            int s = step_pos.first/1000 + 1;
            
            for(int i=1; i<=6; i++)
            {
                auto p = step_pos.second+i;
                if(visited[p]) continue;
                visited[p] = true;
                
                r = rows - (p-1) / cols - 1;
                c = (p-1) % cols;
                if((rows-r-1)%2) c = cols - c - 1; // change direction for odd lines
                int ladder = board[r][c];
                if(ladder>0 && ladder<=target)
                    p = ladder; // no update for steps. allow to come here again with a dice
                    
                if(p == target) return s;
                q.push(make_pair(s*1000+500-p, p));
            }
        }
        return -1;
    }
};