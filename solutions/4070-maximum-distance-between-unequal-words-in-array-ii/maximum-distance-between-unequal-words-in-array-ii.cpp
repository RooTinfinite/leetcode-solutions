#include <string>
#include <vector>
using namespace std;

class Solution {

public:
    int maxDistance(const vector<string>& words) const {
        int front = 0;
        int back = words.size() - 1;
        int maxDistanceBetweenUnequalWords = 0;

        while (front <= back) {
            if (words[front] != (words[words.size() - 1])) {
                maxDistanceBetweenUnequalWords = words.size() - front;
                break;
            }
            if (words[back] != (words[0])) {
                maxDistanceBetweenUnequalWords = back + 1;
                break;
            }
            ++front;
            --back;
        }

        return maxDistanceBetweenUnequalWords;
    }
};