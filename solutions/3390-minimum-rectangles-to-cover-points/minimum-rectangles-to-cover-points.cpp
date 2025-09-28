class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &Points, int Dist){
        int n = Points.size() , Rectangles = 0;
        sort(Points.begin(),Points.end());
        for(int x1 = 0 , x2 = 0 ; x2 < n ; x2++){
            if(Points[x2][0] - Points[x1][0] > Dist){
                x1 = x2;
                Rectangles++;
            }
        }
        return 1 + Rectangles;
    }
};