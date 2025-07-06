
public class Solution
{
    public int NumIdenticalPairs(int[] A)
    {
        int ans = 0;
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in A)
        {
            if (cnt.ContainsKey(x))
                ans += cnt[x]++;
            else
                cnt[x] = 1;
        }
        return ans;
    }
}