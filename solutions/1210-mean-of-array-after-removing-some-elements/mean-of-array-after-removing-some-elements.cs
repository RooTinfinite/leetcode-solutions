//C# Code
public class Solution {
    public double TrimMean(int[] arr) {
        Array.Sort(arr);
        var n = arr.Length;
        
        var start = n / 20;
        var end = n - start;
        var sum = 0;
        
        for (var i = start; i < end; i++)
            sum += arr[i];
        
        return (double)sum / (end - start);
    }
}