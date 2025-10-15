import java.util.Arrays;

public class XORBasisExample {

    static class XORBasis {
        private final int[] basis; 
        private final int maxBits; 

        public XORBasis(int maxBits) {
            this.maxBits = maxBits;
            this.basis = new int[maxBits];
        }

     
        public void insert(int x) {
            for (int i = maxBits - 1; i >= 0; i--) {
                if ((x >> i & 1) == 1) { 
                    if (basis[i] == 0) {
                        basis[i] = x; 
                        return;
                    } else {
                        x ^= basis[i]; 
                    }
                }
            }
        }

        public int maxXORSubset() {
            int maxXOR = 0;
            for (int i = maxBits - 1; i >= 0; i--) {
                if ((maxXOR ^ basis[i]) > maxXOR) {
                    maxXOR ^= basis[i]; 
                }
            }
            return maxXOR;
        }

        public boolean canForm(int x) {
            for (int i = maxBits - 1; i >= 0; i--) {
                if ((x >> i & 1) == 1) {
                    x ^= basis[i];
                }
            }
            return x == 0;
        }
    }

    public static void main(String[] args) {
        int[] nums = {5, 2, 3, 4, 6};
        XORBasis basis = new XORBasis(32); 

        for (int num : nums) {
            basis.insert(num);
        }

        
        int maxXOR = basis.maxXORSubset();
        System.out.println("Maximum XOR subset: " + maxXOR); 

        
        System.out.println("Can form 4? " + basis.canForm(4)); 
        System.out.println("Can form 7? " + basis.canForm(7)); 
        System.out.println("Can form 8? " + basis.canForm(8)); 
    }
}

class Solution {
    public long maximizeXorAndXor(int[] nums) {
        int n = nums.length;

        int[] xor1 = new int[1<<n];
        long[] xor2 = new long[1<<n];
        int[] and = new int[1<<n];

        for(int i = 0; i < n; i++) and[1<<i] = xor1[1<<i] = nums[i];
        for(int i = 3; i < xor1.length; i++) {
            int lowest = i & -i;
            if(lowest == i) continue;
            xor1[i] = xor1[i - lowest] ^ xor1[lowest];
            and[i] = and[i - lowest] & and[lowest];
        }

        for(int i = 1; i < xor2.length; i++) {
            XORBasisExample.XORBasis basis = new XORBasisExample.XORBasis(32); 

            for(int j = 0; j < n; j++) {
                if(((1<<j)&i) != 0) {
                    basis.insert(nums[j] & ~xor1[i]);
                }
            }
          
            int maxXOR = basis.maxXORSubset();
            xor2[i] = xor1[i] + 2 * maxXOR;
        }
        long res = 0;
        for(int i = 0; i < xor2.length; i++) {
            int maskOfOther = (1<<n) - 1 - i;
            res = Math.max(res, xor2[i] + and[maskOfOther]);
        }
        return res;
    }
}