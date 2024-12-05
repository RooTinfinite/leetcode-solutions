bool canChange(char* start, char* target) {
    if (strcmp(start, target) == 0) {
        return true;
    }
    
    int waitL = 0;
    int waitR = 0;
    int len = strlen(start);
    
    for (int i = 0; i < len; i++) {
        char curr = start[i];
        char goal = target[i];
        
        if (curr == 'R') {
            if (waitL > 0) {
                return false;
            }
            waitR++;
        }
        
        if (goal == 'L') {
            if (waitR > 0) {
                return false;
            }
            waitL++;
        }
        
        if (goal == 'R') {
            if (waitR == 0) {
                return false;
            }
            waitR--;
        }
        
        if (curr == 'L') {
            if (waitL == 0) {
                return false;
            }
            waitL--;
        }
    }
    
    return waitL == 0 && waitR == 0;
}

