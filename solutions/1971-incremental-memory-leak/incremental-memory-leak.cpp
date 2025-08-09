class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while(max(memory1, memory2) >= i){
            if(memory1 >= memory2)
                memory1 -= i;
            else
                memory2 -= i;
            i++;
        }
        return {i, memory1, memory2};
    }
};