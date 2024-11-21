class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> firstUnique;
        string letters = "abcdefghijklmnopqrstuvwxyz";
        
        for (char letter : letters) {
            int count = 0;
            for (char c : s) {
                if (c == letter) count++;
            }
            if (count == 1) {
                firstUnique.push_back(s.find(letter));
            }
        }
        
        return firstUnique.empty() ? -1 : *min_element(firstUnique.begin(), firstUnique.end());
    }
};