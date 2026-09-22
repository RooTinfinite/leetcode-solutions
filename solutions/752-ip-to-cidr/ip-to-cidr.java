class Solution {
    public List<String> ipToCIDR(String ip, int n) {
        List<String> answer = new ArrayList<>();

        long ipValue = ipToLong(ip);
        while (n > 0) {
            // get max block size
            int maxBlockSize = maxBlockSize(ipValue, n);

            // build answer
            answer.add(longToIp(ipValue) + "/" + (33 - maxBlockSize));
            
            // decrement num ips left and increment initial ip value based on max block size
            int numValuesRepresented = 1 << (maxBlockSize - 1);
            ipValue += numValuesRepresented;
            n -= numValuesRepresented;
        }
        
        return answer;
    }

    // Gets the max block size. A max block can be extended if:
    // - it's less than 32 bits
    // - all lesser significant bits to the right are 0s
    // - the amount of values the block can represent are <= the number of values left to represent (n)
    private int maxBlockSize(long startNum, int n) {
        int blockSize = 1; // initial size is 1
        while (blockSize < 32 && (startNum & (1 << (blockSize - 1))) == 0 && ((1 << blockSize) <= n)) {
            blockSize++;
        }
        return blockSize;
    }

    // converts an ip bit string to a long
    private long ipToLong(String ip) {
        long result = 0;
        String[] chunks = ip.split("\\.");
        for (String chunk : chunks) {
            result = result * 256 + Integer.parseInt(chunk);
        }
        return result;
    }

    // converts a long to a 32 bit ip string
    private String longToIp(long num) {
        return String.format("%s.%s.%s.%s", (num >> 24) & 255, (num >> 16) & 255, (num >> 8) & 255, num & 255);
    }
}