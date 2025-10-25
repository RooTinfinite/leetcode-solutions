class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int num_groups = votes[0].size();
        int num_voters = votes.size();
        vector<vector<int>> pos_counter(26, vector<int>(num_groups));
        for (auto& curr_vote : votes){
            for(int i=0;i<num_groups;i++)
                pos_counter[curr_vote[i]-'A'][i]++;
        }
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char c1, char c2){
            if (pos_counter[c1-'A'] == pos_counter[c2-'A']) return c1 < c2;
            return pos_counter[c1-'A'] > pos_counter[c2-'A'];
            }
        );
        return res;
    }
};