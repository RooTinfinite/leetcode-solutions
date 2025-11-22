class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> Q;
        for (NestedInteger nested : nestedList) {
            Q.push(nested);
        }

        int depth = 1;
        int maxDepth = 0;
        int sumOfElements = 0;
        int sumOfProducts = 0;

        while (!Q.empty()) {
            int size = Q.size();
            maxDepth = max(maxDepth, depth);
            
            for (int i = 0; i < size; i++) {
                NestedInteger nested = Q.front(); 
                Q.pop();
                
                if (nested.isInteger()) {
                    sumOfElements += nested.getInteger();
                    sumOfProducts += nested.getInteger() * depth;
                } else {
                    for (NestedInteger nestedNextLevel : nested.getList()) {
                        Q.push(nestedNextLevel);
                    }
                }
            }
            depth++;
        }
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }
};