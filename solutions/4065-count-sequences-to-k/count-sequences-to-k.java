import java.util.*;
import java.math.*;

class Solution {
    public int countSequences(int[] nums, long k) {
        Map<String, Long> prev = new HashMap<>();
        prev.put("1#1", 1L);

        for (int x : nums) {
            Map<String, Long> nw = new HashMap<>();

            for (Map.Entry<String, Long> entry : prev.entrySet()) {
                String key = entry.getKey();
                long ways = entry.getValue();

                String[] parts = key.split("#");
                long num = Long.parseLong(parts[0]);
                long den = Long.parseLong(parts[1]);

                String same = num + "#" + den;
                nw.put(same, nw.getOrDefault(same, 0L) + ways);

                long g = gcd(x, den);
                long nnum = num * (x / g);
                long nden = den / g;
                String mul = nnum + "#" + nden;
                nw.put(mul, nw.getOrDefault(mul, 0L) + ways);

                g = gcd(x, num);
                nnum = num / g;
                nden = den * (x / g);
                String div = nnum + "#" + nden;
                nw.put(div, nw.getOrDefault(div, 0L) + ways);
            }

            prev = nw;
        }

        long ans = 0;
        for (Map.Entry<String, Long> entry : prev.entrySet()) {
            String[] parts = entry.getKey().split("#");
            long num = Long.parseLong(parts[0]);
            long den = Long.parseLong(parts[1]);
            long ways = entry.getValue();

            if (num % den == 0 && num / den == k)
                ans += ways;
        }

        return (int) ans;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}