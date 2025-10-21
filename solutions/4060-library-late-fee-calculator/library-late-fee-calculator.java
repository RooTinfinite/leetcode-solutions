class Solution {
    public int lateFee(int[] daysLate) {
        int n = daysLate.length;
        int ans = 0; 
        
        for(int i = 0 ; i < n; i++){
            int day = daysLate[i];

            if(day == 1) ans += 1;
            else if(day >= 2 && day <= 5) ans += (day * 2);
            else  ans += (day * 3);

        }
        
        return ans;

    }
}