class Solution {
public:
    bool canChange(string start, string target) {
        int index , r = 0, l = 0;
        int size = target.length();
        for (int i = 0, j = 0; i < size; i++){
            if (start[i]=='R') r++;
            if (start[i]=='L') l++;
            if (target[i]=='R') r--;
            if (target[i]=='L') l--;

            if (start[i]!='_'){
                index = i;
                while (j < size && target[j]=='_') j++;
                if(start[i]!=target[j] || (start[i]=='R' && index > j) || (start[i]=='L' && index < j)) return false;
                j++;
            }
        }

        if (r == 0 && l == 0) return true;
        else return false;
    }
};