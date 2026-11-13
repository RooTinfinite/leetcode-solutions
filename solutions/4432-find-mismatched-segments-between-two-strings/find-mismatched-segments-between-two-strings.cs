public class Solution
{
    public IList<IList<string>> FindMismatchedSegments(string s1, string s2)
    {
        var result = new List<IList<string>>();

        for (int l = 0, r = 0; r <= s1.Length; r++)
        {
            if (r < s1.Length && s1[r] != s2[r])
                continue;

            if (l != r)
                result.Add([s1[l..r], s2[l..r]]);

            l = r + 1;
        }

        return result;
    }
}