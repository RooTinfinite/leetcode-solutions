class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;
        long long int temp = x, answer = 0;
        while(x)
        {
            int digit = x % 10;
            answer = (answer * 10) + digit;
            x = x / 10;
        }
        
        if(temp == answer) return true;
        return false;
    }
};