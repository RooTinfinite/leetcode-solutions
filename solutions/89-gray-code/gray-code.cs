public class Solution {
    public IList<int> GrayCode(int n) {
        IList<int> result = new List<int>();
        // there are 2 ^ n numbers in the Gray code sequence.
        int sequenceLength = 1 << n;
        for (int i = 0; i < sequenceLength; i++) {
            int num = i ^ i >> 1;
            result.Add(num);
        }

        return result;
    }
}