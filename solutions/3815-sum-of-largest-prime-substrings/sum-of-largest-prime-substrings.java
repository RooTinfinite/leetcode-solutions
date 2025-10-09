class Solution {
    private boolean isPrime(long num) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }
        for (long i = 5; i * i <= num; i = i + 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    public long sumOfLargestPrimes(String s) {
        Set<Long> primesFound = new HashSet<>();
        int n = s.length();

        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            long currentNum = s.charAt(i) - '0';

            if (isPrime(currentNum)) {
                primesFound.add(currentNum);
            }

            for (int j = i + 1; j < n; ++j) {
                int digit = s.charAt(j) - '0';
                if (currentNum > Long.MAX_VALUE / 10 || 
                    (currentNum == Long.MAX_VALUE / 10 && digit > Long.MAX_VALUE % 10)) {
                    break; 
                }
                
                currentNum = currentNum * 10 + digit;
                if (isPrime(currentNum)) {
                    primesFound.add(currentNum);
                }
            }
        }

        if (primesFound.isEmpty()) {
            return 0;
        }

        List<Long> sortedPrimes = new ArrayList<>(primesFound);
        
        sortedPrimes.sort(Collections.reverseOrder());

        long sumOfTopPrimes = 0;
        int count = 0;
        for (long p : sortedPrimes) {
            if (count < 3) {
                sumOfTopPrimes += p;
                count++;
            } else {
                break;
            }
        }

        return sumOfTopPrimes;
    }
}