class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> blocks;
        blocks.push_back(nums);
        vector<int> power(15, 0);

        for(int i =0; i<15;++i)
        {
            int bit = 14-i;
            int current_power=0;
            bool stopped = false;

            vector<vector<int>> new_blocks;

            for(auto& block : blocks)
            {
                if(stopped)
                {
                    new_blocks.push_back(block);
                }
                else
                {
                    vector<int> s_yes, s_no;
                    for(int num : block)
                    {
                        if((num>>bit)&1)
                        {
                            s_yes.push_back(num);
                        }
                        else
                        {
                            s_no.push_back(num);
                        }
                    }
                    if(s_no.empty())
                    {
                        current_power+=s_yes.size();
                        new_blocks.push_back(s_yes);
                    }
                    else
                    {
                        current_power += s_yes.size();
                        if(!s_yes.empty()) new_blocks.push_back(s_yes);
                        if(!s_no.empty()) new_blocks.push_back(s_no);
                        stopped= true;
                    }
                }
            }
            power[i] = current_power;
            blocks = move(new_blocks);
        }
        return power;
    }
};