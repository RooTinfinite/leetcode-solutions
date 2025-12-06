#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set2;

class Solution {
    const int MAX = 1e6;
public:
    long long minInversionCount(vector<int>& nums, int k) {
        ordered_set2 data; 
        long long answer = 0, runningAnswer = 0;
        vector<long long>answers;
        
        for (int i = 0; i < k; i++) {
            // how many elements are greater than {num[i], i}
            answer += (data.size() - data.order_of_key({nums[i], i}));
            data.insert({nums[i], i});
        }
        
        answers.push_back(answer);

        for (int remove = 0, i = k; i < nums.size(); i++, remove++) {
            // remove it then compute how many elements less than {num[i], i}, avoiding duplicate also 

            data.erase({nums[remove], remove});  
            answer -= data.order_of_key({nums[remove]-1, MAX});

        // continue the normal flow as in the first loop above 
            answer += (data.size() - data.order_of_key({nums[i], i}));
            data.insert({nums[i], i});
            
            answers.push_back(answer);
        }
        
        return *min_element(answers.begin(), answers.end()); 
    }
};