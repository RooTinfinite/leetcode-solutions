class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) 
    {
        int s = 0, t = x;
        while (t > 0) 
        {
            s += t % 10;
            t /= 10;
        }
        return (x % s == 0) ? s : -1;
    }
};