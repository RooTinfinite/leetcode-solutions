const int N = 26;
struct Trie {
    Trie* next[N];
    bool isEnd = 0;
    Trie() { fill(next, next + N, (Trie*)NULL); }
    /*
    ~Trie() {// destructor
        for (int i = 0; i < N; ++i)
            if (next[i] != NULL)
                delete next[i];
    }
    */
};

class Solution {
public:
    static vector<string> partitionString(string& s) {
        const int n = s.size();
        Trie trie;
        Trie* root = &trie;

        vector<string> ans;
        string t = "";
        Trie* node = root;
        // Integrate search & insert for Trie in the loop
        for (char c : s) {
            const int i = c - 'a';
            t += c;
            if (node->next[i] == NULL) {
                node->next[i] = new Trie();
                node->next[i]->isEnd = 1;
                ans.push_back(t);
                t = "";
                node = root; // begin with new search & insert
            } else
                node = node->next[i];
        }
        return ans;
    }
};