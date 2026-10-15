class Solution {
public:
    int dist(char a, char b){
        int x = abs((a-'0') - (b-'0'));
        return min(x, 10-x);
    }

    int minRotations(string s) {
        int total = 0;
        char last = '0';

        for(char c : s){
            total += dist(last, c);
            last = c;
        }

        return total;
    }
};