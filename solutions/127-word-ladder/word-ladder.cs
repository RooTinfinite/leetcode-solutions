public class Solution {
    public int LadderLength(string beginWord, string endWord,
                            IList<string> wordList) {
        int L = beginWord.Length;
        Dictionary<string, List<string>> allComboDict =
            new Dictionary<string, List<string>>();
        foreach (string word in wordList) {
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                if (!allComboDict.ContainsKey(newWord))
                    allComboDict[newWord] = new List<string>();
                allComboDict[newWord].Add(word);
            }
        }

        Queue<Tuple<string, int>> Q = new Queue<Tuple<string, int>>();
        Q.Enqueue(new Tuple<string, int>(beginWord, 1));
        Dictionary<string, bool> visited = new Dictionary<string, bool>();
        visited[beginWord] = true;
        while (Q.Any()) {
            var node = Q.Dequeue();
            string word = node.Item1;
            int level = node.Item2;
            for (int i = 0; i < L; i++) {
                string newWord = word.Substring(0, i) + '*' +
                                 word.Substring(i + 1, L - i - 1);
                foreach (string adjacentWord in allComboDict.GetValueOrDefault(
                             newWord, new List<string>())) {
                    if (adjacentWord.Equals(endWord))
                        return level + 1;
                    if (!visited.ContainsKey(adjacentWord)) {
                        visited[adjacentWord] = true;
                        Q.Enqueue(
                            new Tuple<string, int>(adjacentWord, level + 1));
                    }
                }
            }
        }

        return 0;
    }
}