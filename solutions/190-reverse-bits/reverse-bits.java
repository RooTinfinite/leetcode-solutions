class Solution {
    private int reverseByte(int byteVal, Map<Integer, Integer> cache) {
        if (cache.containsKey(byteVal)) {
            return cache.get(byteVal);
        }
        int value = (int)(((byteVal * 0x0202020202L) & 0x010884422010L) % 1023);
        cache.put(byteVal, value);
        return value;
    }

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0;
        int power = 24;
        Map<Integer, Integer> cache = new HashMap<>();
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n >>>= 8; // Use unsigned shift
            power -= 8;
        }
        return ret;
    }
}