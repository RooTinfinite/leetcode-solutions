class TrieNode {
    TrieNode[] children;
    int count;
    
    public TrieNode() {
        children = new TrieNode[2];
        count = 0;
    }
}

class Solution {
    public long countXorSubarrays(int[] nums, int k)  {
        TrieNode root = new TrieNode();
        int prefixXOR = 0;
        long result = 0;
        
        insert(root, 0); // Initialize with 0
        
        for (int num : nums) {
            prefixXOR ^= num;
            result += query(root, prefixXOR, k);
            insert(root, prefixXOR);
        }
        
        return result;
    }
    
    private void insert(TrieNode root, int num) {
        TrieNode node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node.children[bit] == null) {
                node.children[bit] = new TrieNode();
            }
            node = node.children[bit];
            node.count++;
        }
    }
    
    private long query(TrieNode root, int prefixXOR, int k) {
        TrieNode node = root;
        long count = 0;
        
        for (int i = 31; i >= 0 && node != null; i--) {
            int pBit = (prefixXOR >> i) & 1;
            int kBit = (k >> i) & 1;
            
            if (kBit == 1) {
                // We need the opposite bit to make XOR >= k
                node = node.children[1 - pBit];
            } else {
                // All numbers with opposite bit will give XOR >= k
                if (node.children[1 - pBit] != null) {
                    count += node.children[1 - pBit].count;
                }
                // Continue with same bit to check further bits
                node = node.children[pBit];
            }
        }
        
        // If we've reached the end, check if the remaining number is >= k
        if (node != null) {
            count += node.count;
        }
        
        return count;
    }
}