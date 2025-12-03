// C#

public class Solution {
    public int ClimbStairs(int n) {
        double sqrt5 = Math.Sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        return (int)((Math.Pow(phi, n + 1) - Math.Pow(psi, n + 1)) / sqrt5);
    }
}