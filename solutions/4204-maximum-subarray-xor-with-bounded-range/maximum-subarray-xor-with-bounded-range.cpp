struct TrieNode {
    TrieNode* child[2];
    int count;
    
    TrieNode() {
        child[0] = child[1] = nullptr;
        count = 0;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int x) {
        TrieNode* node = root;
        
        for(int i = 16; i >= 0; i--) {
            int bit = (x >> i) & 1;
            
            if(!node->child[bit])
                node->child[bit] = new TrieNode();
        
            node = node->child[bit];
            node->count++;
        }
    }
    
    void remove(int x) {
        TrieNode* node = root;
        
        for(int i = 16; i >= 0; i--) {
            int bit = (x >> i) & 1;
            node = node->child[bit];
            node->count--;
        }
    }
    
    int maxXor(int x) {
        TrieNode* node = root;
        int res = 0;
        
        for(int i = 16; i >= 0; i--) {
            int bit = (x >> i) & 1, desired = 1 - bit;
            
            if(node->child[desired] && node->child[desired]->count > 0) {
                res |= (1 << i);
                node = node->child[desired];
            } 
            
            else 
                node = node->child[bit];
        }
        
        return res;
    }
};

class Solution {
public:
    int maxXor(vector<int>& A, int k) {
        int n = A.size(), l = 0, res = 0;
        vector<int> pre(n + 1);

        for(int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] ^ A[i];

        multiset<int> ms;
        
        Trie trie;
        trie.insert(pre[0]);

        for(int r = 0; r < n; ++r) {
            ms.insert(A[r]);
            
            while(!ms.empty() && *prev(end(ms)) - *begin(ms) > k) {
                ms.erase(ms.find(A[l]));
                trie.remove(pre[l++]);
            }

            res = max(res, trie.maxXor(pre[r + 1]));
            trie.insert(pre[r + 1]);
        }

        return res;
    }
};