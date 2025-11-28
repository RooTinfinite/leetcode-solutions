class Solution {
    public boolean judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            if (c % i == 0) {
                int count = 0;
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
}

// class Solution {
//     public boolean judgeSquareSum(int c) {
//         if (c < 0) {
//             return false;
//         }
        
//         int left = 0;
//         int right = (int) Math.sqrt(c);
//         while (left <= right) {
//             long sum = (long) left * left + (long) right * right;
            
//             if (sum == c) {
//                 return true;
//             } else if (sum < c) {
//                 left++; 
//             } else {
//                 right--; 
//             }
//         }
//         return false;
//     }
// }