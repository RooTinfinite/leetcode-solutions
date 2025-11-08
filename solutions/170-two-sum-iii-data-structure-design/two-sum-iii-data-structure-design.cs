public class TwoSum {
    private Dictionary<int, int> num_counts;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.num_counts = new Dictionary<int, int>();
    }

    /** Add the number to an internal data structure. */
    public void Add(int number) {
        if (this.num_counts.ContainsKey(number))
            this.num_counts[number] += 1;
        else
            this.num_counts.Add(number, 1);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public bool Find(int value) {
        foreach (KeyValuePair<int, int> entry in this.num_counts) {
            int complement = value - entry.Key;
            if (complement != entry.Key) {
                if (this.num_counts.ContainsKey(complement))
                    return true;
            } else {
                if (entry.Value > 1)
                    return true;
            }
        }

        return false;
    }
}