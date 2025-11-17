public class Solution {
    public IList<IList<string>> Partition(string s) {
        int len = s.Length;
        bool[,] dp = new bool[len, len];
        IList<IList<string>> result = new List<IList<string>>();
        dfs(result, s, 0, new List<string>(), dp);
        return result;
    }

    void dfs(IList<IList<string>> result, string s, int start,
             IList<string> currentList, bool[,] dp) {
        if (start >= s.Length)
            result.Add(new List<string>(currentList));
        for (int end = start; end < s.Length; end++) {
            if (s[start] == s[end] &&
                (end - start <= 2 || dp[start + 1, end - 1])) {
                dp[start, end] = true;
                currentList.Add(s.Substring(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.RemoveAt(currentList.Count - 1);
            }
        }
    }
}