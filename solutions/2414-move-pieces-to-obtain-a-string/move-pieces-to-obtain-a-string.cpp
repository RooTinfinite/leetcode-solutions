class Solution {
public:
    bool canChange(string start, string target) {
        int pos = 0;
        int rCnt = 0, lCnt = 0;
        int len = target.length();
        
        for (int i = 0, j = 0; i < len; i++) {
            if (start[i] == 'R') rCnt++;
            if (start[i] == 'L') lCnt++;
            if (target[i] == 'R') rCnt--;
            if (target[i] == 'L') lCnt--;

            if (start[i] != '_') {
                pos = i;
                while (j < len && target[j] == '_') j++;
                
                if (start[i] != target[j] || 
                    (start[i] == 'R' && pos > j) || 
                    (start[i] == 'L' && pos < j)) {
                    return false;
                }
                j++;
            }
        }

        return rCnt == 0 && lCnt == 0;
    }
};