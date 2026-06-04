class Solution {
public:
    int countMonobit(int n) {
        int count = 0;

        for(int i=0; i<=n; i++){
            int number = i;
            int lastDigit = number & 1;

            bool flag = false;

            while(number > 0){
                
                int curr = number & 1;
                if(curr != lastDigit){
                    flag = true;
                    break;
                }

                number = number >> 1;
            }

            if(flag != true) count++;
        }

        return count;
        
    }
};