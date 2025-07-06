class Solution {
public:
    /*void print(map<int, int>& m)
    {
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            cout<<it->first<<":"<<it->second<<endl;
        }
    }*/
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
    {
        if (boardingCost*4<=runningCost) return -1;

        int rots = 0;
        int net = 0;
        map<int, int> m;
        int curr = 0;
        while (true)
        {
            //cout<<curr<<" "<<rots<<" "<<net<<endl;
            if (rots<customers.size()) curr+=customers[rots];
            if (curr<4)
            {
                if (curr*boardingCost <= runningCost)   //could be max profit, because the instantaneous profit goes down. But also might not be, if a lot of people come later. Memoize this profit and no. of rots
                {
                    if (m.find(net)==m.end())
                    {
                        m[net] = rots;  //for the same net, we need the minimum no. of rots
                    }
                    net += curr*boardingCost - runningCost;
                    rots+=1;
                    curr = 0;
                }
                else
                {
                    net += curr*boardingCost - runningCost;
                    rots+=1;
                    curr = 0;
                }
            }
            else
            {
                net+=4*boardingCost-runningCost;
                curr-=4;
                rots+=1;
            }

            if (curr==0 && rots>=customers.size()) break;
        }

        if (m.find(net)==m.end()) m[net] = rots;
        //print(m);
        auto it = m.end();
        it--;
        if (it->first==0) return -1;    //edge case when customers = [2] and 2 * boardingCost < runningCost. m becomes = {0:0}
        return it->second;
    }
};