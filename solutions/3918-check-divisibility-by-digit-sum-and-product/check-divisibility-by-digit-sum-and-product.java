public class Solution {
    public boolean checkDivisibility(int n) {
        return n % (
            String.valueOf(n).chars().map(c -> c - '0').sum()
          + String.valueOf(n).chars().map(c -> c - '0').reduce(1, (a,b) -> a*b)
        ) == 0;
    }
}
