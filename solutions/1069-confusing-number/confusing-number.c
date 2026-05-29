bool confusingNumber(int n){
    int rotDigit[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    
    int numCopy = n, rotNum = 0;
    while(numCopy > 0) {
        int unitDigit = numCopy % 10;
        
        if(rotDigit[unitDigit] == -1) return false;
        
        rotNum = rotNum * 10 + rotDigit[unitDigit];
        numCopy /= 10;
    } 
    return n != rotNum;
}
