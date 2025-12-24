class Solution {
public:
    array<array<int, 3>, 3> A3{};
    inline void insert(int x){
        const int r=x%3;
        auto& A=A3[r];
        if (x>=A[0]){
            A[2]=A[1];
            A[1]=exchange(A[0], x);
        }
        else if(x>=A[1]) A[2]=exchange(A[1], x);
        else if (x>=A[2]) A[2]=x;
    }
    int maximumSum(vector<int>& nums) {
        for(int x: nums) 
            insert(x);
        int maxSum=(A3[0][0]>0 & A3[1][0]>0 & A3[2][0]>0)
        ? A3[0][0]+A3[1][0]+A3[2][0] : 0;
        for(int r=0; r<3; r++)
            if (A3[r][2]>0) maxSum=max(maxSum, A3[r][0]+A3[r][1]+A3[r][2]);
        return maxSum;
    }
};