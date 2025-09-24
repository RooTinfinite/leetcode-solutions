class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int lenght = nums.size();
        int finalResult = 0;

        for (int i = 0; i < lenght; i++)
        {
            if (lenght % (i+1))
            {
                continue;
            }
            else
            {
                finalResult = finalResult + (nums.at(i) * nums.at(i));
            }
        }

        return finalResult;
        
    }


};