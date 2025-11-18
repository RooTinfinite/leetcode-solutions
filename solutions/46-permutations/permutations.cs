public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        List<IList<int>> ans = new List<IList<int>>();
        Backtrack(new List<int>(), ans, nums);
        return ans;
    }

    void Backtrack(List<int> curr, List<IList<int>> ans, int[] nums) {
        if (curr.Count == nums.Length) {
            ans.Add(new List<int>(curr));
            return;
        }

        foreach (int num in nums) {
            if (!curr.Contains(num)) {
                curr.Add(num);
                Backtrack(curr, ans, nums);
                curr.RemoveAt(curr.Count - 1);
            }
        }
    }
}