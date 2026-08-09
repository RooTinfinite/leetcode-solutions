#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Custom hash function for vector<int> to be used in unordered_set
struct VectorHasher {
    size_t operator()(const vector<int>& V) const {
        size_t hash = V.size();
        for(auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        vector<int> start = nums;
        vector<int> target = nums;
        sort(target.begin(), target.end());
        
        if (start == target) return 0;
        
        queue<vector<int>> q;
        unordered_set<vector<int>, VectorHasher> visited;
        
        q.push(start);
        visited.insert(start);
        
        int res = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                vector<int> curr = q.front();
                q.pop();
                
                for (int p : pre) {
                    vector<int> nextState = curr;
                    // Reverse the prefix
                    reverse(nextState.begin(), nextState.begin() + p);
                    
                    if (nextState == target) {
                        return res + 1;
                    }
                    
                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};