class Solution 
{
public:
    int countTime(string time) 
    {   
        int ans=1;
        
        if(time[0]=='?' && time[1]=='?') //when first both HH are ?? of (HH:MM)
                ans *= 24;   
        
        else
        {
            if(time[0]=='?')  //when first H is ? and second H has some value of (HH:MM)
            {
                if(time[1] < '4') 
                    ans *= 3;
                else
                    ans *= 2;
            }

            if(time[1]=='?') //when second H is ? and first H has some value of (HH:MM)
            {
                if(time[0] < '2')
                    ans *= 10;
                else
                    ans *= 4;
            }
        }
        
        if(time[3]=='?') //for first M of (HH:MM)
        {
            ans *= 6;
        }

        if(time[4]=='?') // for second M of (HH:MM)
        {
            ans *= 10;
        }       
            
        return ans;
    }
};