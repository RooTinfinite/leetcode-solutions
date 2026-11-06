class Solution {
public:
    long long countMagicalPairs(string s) {
        long long n = s.size(), ans = 0;
        vector <int> uniqueLeftCount(27, 0), uniqueRightCount(27, 0);
        vector <int> uniqueLeft(n, 0), uniqueRight(n, 0); 

        set <char> charSet;

        uniqueLeft[0] = 1;
        uniqueLeftCount[1]++;

        for(int j = 1; j < n; j++){
            charSet.insert(s[j]);
            uniqueRight[j] = charSet.size();
            uniqueRightCount[charSet.size()]++;
        }

        for(int i = 1; i <= 26; i++){
            ans += uniqueLeftCount[i] * uniqueRightCount[i];
        }

        for(int j = 1; j + 1 < n; j++){

            //process the left substring
            uniqueLeft[j]++;
            uniqueLeftCount[1]++;

            for(int k = j - 1; k > -1; k--){
                if(s[k] == s[j]) break;
                uniqueLeftCount[uniqueLeft[k]]--;
                uniqueLeft[k]++;
                uniqueLeftCount[uniqueLeft[k]]++;
            }

            //process the right substring
            uniqueRight[j]--;
            uniqueRightCount[1]--;

            for(int k = j + 1; k < n; k++){
                if(s[k] == s[j]) break;
                uniqueRightCount[uniqueRight[k]]--;
                uniqueRight[k]--;
                uniqueRightCount[uniqueRight[k]]++;
            }

            for(int i = 1; i <= 26; i++){
                ans += (long long)uniqueLeftCount[i] * uniqueRightCount[i];
            }
        }

        return ans;
    }
};