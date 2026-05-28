public class TrieNode {
    public TrieNode[] Children = new TrieNode[26];
    public int MinLen = int.MaxValue;
    public int Idx = int.MaxValue;

    public TrieNode() {
        for (int i = 0; i < 26; i++) {
            Children[i] = null;
        }
    }
}

public class Trie {
    public TrieNode Root = new TrieNode();

    public void Insert(string s, int idx) {
        int len = s.Length;
        TrieNode node = Root;
        if (len < node.MinLen) {
            node.MinLen = len;
            node.Idx = idx;
        }
        foreach (char ch in s) {
            int c = ch - 'a';
            if (node.Children[c] == null) {
                node.Children[c] = new TrieNode();
            }
            node = node.Children[c];

            if (len < node.MinLen) {
                node.MinLen = len;
                node.Idx = idx;
            }
        }
    }

    public int Query(string s) {
        TrieNode node = Root;

        foreach (char ch in s) {
            int c = ch - 'a';
            if (node.Children[c] != null) {
                node = node.Children[c];
            } else {
                break;
            }
        }

        return node.Idx;
    }
}

public class Solution {
    public int[] StringIndices(string[] wordsContainer, string[] wordsQuery) {
        Trie trie = new Trie();

        for (int i = 0; i < wordsContainer.Length; i++) {
            char[] chars = wordsContainer[i].ToCharArray();
            Array.Reverse(chars);
            string reversed = new string(chars);
            trie.Insert(reversed, i);
        }

        int[] res = new int[wordsQuery.Length];
        for (int i = 0; i < wordsQuery.Length; i++) {
            char[] chars = wordsQuery[i].ToCharArray();
            Array.Reverse(chars);
            string reversed = new string(chars);
            res[i] = trie.Query(reversed);
        }

        return res;
    }
}