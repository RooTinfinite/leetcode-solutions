class Solution {

    static class TrieNode {
        TrieNode[] child = new TrieNode[2];
        int count = 0;
    }

    static class Trie {
        TrieNode root = new TrieNode();

        void insert(int num) {
            TrieNode node = root;
            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (node.child[bit] == null) {
                    node.child[bit] = new TrieNode();
                }
                node = node.child[bit];
                node.count++;
            }
        }

        void remove(int num) {
            TrieNode node = root;
            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                node = node.child[bit];
                node.count--;
            }
        }

        int getMaxXor(int num) {
            TrieNode node = root;
            int max = 0;

            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opposite = 1 - bit;

                if (node.child[opposite] != null && node.child[opposite].count > 0) {
                    max |= (1 << i);
                    node = node.child[opposite];
                } else {
                    node = node.child[bit];
                }
            }

            return max;
        }
    }

    public int maxXor(int[] nums, int k) {

        int n = nums.length;

        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ nums[i];
        }

        Deque<Integer> minDeque = new ArrayDeque<>();
        Deque<Integer> maxDeque = new ArrayDeque<>();

        Trie trie = new Trie();
        int left = 0;
        int ans = 0;

        trie.insert(prefix[0]);

        for (int right = 0; right < n; right++) {

            // Maintain min deque
            while (!minDeque.isEmpty() && nums[minDeque.peekLast()] > nums[right]) {
                minDeque.pollLast();
            }
            minDeque.addLast(right);

            // Maintain max deque
            while (!maxDeque.isEmpty() && nums[maxDeque.peekLast()] < nums[right]) {
                maxDeque.pollLast();
            }
            maxDeque.addLast(right);

            // Shrink window if invalid
            while (!minDeque.isEmpty() && !maxDeque.isEmpty()
                    && nums[maxDeque.peekFirst()] - nums[minDeque.peekFirst()] > k) {

                if (minDeque.peekFirst() == left) minDeque.pollFirst();
                if (maxDeque.peekFirst() == left) maxDeque.pollFirst();

                trie.remove(prefix[left]);
                left++;
            }

            ans = Math.max(ans, trie.getMaxXor(prefix[right + 1]));

            trie.insert(prefix[right + 1]);
        }

        return ans;
    }
}