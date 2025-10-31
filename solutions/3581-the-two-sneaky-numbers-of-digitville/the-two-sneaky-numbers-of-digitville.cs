public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        List<int> res = new List<int>();
        Dictionary<int, int> count = new Dictionary<int, int>();
        foreach (int x in nums) {
            if (!count.ContainsKey(x))
                count[x] = 0;
            count[x]++;
            if (count[x] == 2) {
                res.Add(x);
            }
        }
        return res.ToArray();
    }
}