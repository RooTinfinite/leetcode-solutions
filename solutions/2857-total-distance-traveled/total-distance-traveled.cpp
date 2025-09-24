class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) 
    {
        int ans = 0;
        while(mainTank >= 5)
        {
            ans += 50;
            if(additionalTank) additionalTank--, mainTank++;
            mainTank -= 5;
        }
        ans += (mainTank*10);
        return ans;
    }
};