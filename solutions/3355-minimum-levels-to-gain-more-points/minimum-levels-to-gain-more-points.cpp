class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
    }

    int minimumLevels(vector<int>& possible) {
        int sum {};
        int n = possible.size();
        for (int& num : possible)
            sum += (num ? 1 : -1);

        cout << sum << '\n';

        int firstPlayer = 0;
        for (int i = 0; i < n-1; ++i)
        {
            firstPlayer += (possible[i] ? 1 : -1);
            if (firstPlayer > sum-firstPlayer)
                return i + 1;
        }
        return -1;
    }
};