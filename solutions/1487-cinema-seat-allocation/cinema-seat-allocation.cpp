class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int,vector<int>>seats;
        int count = 0;

        for (auto reserved : reservedSeats) {
            int x = reserved[0];
            int y = reserved[1];
            if(!seats.count(x))
             seats[x]=vector<int>(11,0);
            seats[x][y]=1;
        }

        int emptyRow=n-seats.size();
        count+=(2*emptyRow);

        for (auto it : seats) {
            auto i = it.first;

            bool left  = (seats[i][2]==0 && seats[i][3]==0 && seats[i][4]==0 && seats[i][5]==0);
            bool mid   = (seats[i][4]==0 && seats[i][5]==0 && seats[i][6]==0 && seats[i][7]==0);
            bool right = (seats[i][6]==0 && seats[i][7]==0 && seats[i][8]==0 && seats[i][9]==0);

            if (left && right) {
                count += 2;
            }
            else if (left || mid || right) {
                count += 1;
            }
        }

        return count;
    }
};