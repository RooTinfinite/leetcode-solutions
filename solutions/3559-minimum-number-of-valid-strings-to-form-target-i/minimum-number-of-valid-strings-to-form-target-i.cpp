class Node {
public:
    Node* lists[26];
    bool flag = false;

};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int ch = c - 'a';
            if (!node->lists[ch]) {
                node->lists[ch] = new Node();
            }
            node = node->lists[ch];
            node->flag = true;
        }
    }

   
    vector<int> search(const string& target, int start) {
        vector<int> valid_lengths;
        Node* node = root;
        for (int i = start; i < target.length(); i++) {
            if (!node->lists[target[i] - 'a']) break;
            node = node->lists[target[i] - 'a'];
            if (node->flag) {
                valid_lengths.push_back(i - start + 1);
            }
        }
        return valid_lengths;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;

        for (const string& word : words) {
            trie.insert(word);
        }

        int n = target.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  
        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;

            vector<int> lengths = trie.search(target, i);
            for (int len : lengths) {
                dp[i + len] = min(dp[i + len], dp[i] + 1);
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};