class Solution {
public:
    using ll = long long;
    long long maxEnergyBoost(vector<int> &A, vector<int> &B){
        ll A1 = 0 , B1 = 0 , A2 = 0 , B2 = 0;
        for(int i = 0 ; i < A.size() ; i++){
            ll currA = A[i] + max(A1 , B2);
            ll currB = B[i] + max(B1 , A2);
            A2 = A1 , A1 = currA;
            B2 = B1 , B1 = currB;
        }
        return max(A1 , B1);
    }
};