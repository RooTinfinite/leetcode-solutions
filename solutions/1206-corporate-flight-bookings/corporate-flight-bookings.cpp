class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    { 
       
         vector<int> pre(n,0);
        for(int i = 0 ; i<bookings.size();i++)
        {
            int firstindex = bookings[i][0];
            int secondindex = bookings[i][1];
            int value = bookings[i][2];
            pre[firstindex-1] += value ; 
            if(secondindex<pre.size())
            pre[secondindex] += - value ; 


        }
        for(int i = 1; i<pre.size();i++)
        pre[i] += pre[i-1];



        return pre ; 
      
        
    }
};