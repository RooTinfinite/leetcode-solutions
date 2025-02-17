class Solution {
public:
    bool divisorGame(int n) {
        int winner = 0;
        while(n!=1){
            winner += 1;
            n -= 1;
        }
        
        if(winner%2==0){   
            return false; 
        }else{
            return true;
        }

    }
};