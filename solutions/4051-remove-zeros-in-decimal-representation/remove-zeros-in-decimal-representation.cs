using System;

public class Solution {
    public long RemoveZeros(long n) {
        string result = n.ToString().Replace("0", "");
        return long.Parse(result);
    }
}