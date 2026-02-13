public class Solution {
    public int LongestBalanced(string s) {
        var results = new int[] {
            Solve1(s, 'a'),
            Solve1(s, 'b'),
            Solve1(s, 'c'),
            Solve2(s, 'a', 'b'),
            Solve2(s, 'a', 'c'),
            Solve2(s, 'b', 'c'),
            Solve3(s)
        };
        return results.Max();
    }

    static int Solve1(string s, char t) {
        int result = 0;
        int count = 0;
        foreach(var c in s) {
            if (c == t) {
                count++;
                result = Math.Max(result, count);
            } else {
                count = 0;
            }
        }
        return result;
    }

    static int Solve2(string s, char t1, char t2) {
        int result = 0;
        int[] counts = new int[2];
        var previousPositions = new Dictionary<int, int>();
        for (int i = 0; i < s.Length; i++) {
            var c = s[i];
            if (c != t1 && c != t2) {
                previousPositions.Clear();
                counts[0] = 0;
                counts[1] = 0;
            } else {
                if (c == t1) {
                    counts[0]++;
                } else {
                    counts[1]++;
                }
                if (counts[0] == counts[1]) {
                    result = Math.Max(result, counts[0] * 2);
                } else {
                    var diff = counts[0] - counts[1];
                    if (previousPositions.TryGetValue(diff, out var previous)) {
                        result = Math.Max(result, i - previous);
                    } else {
                        previousPositions[diff] = i;
                    }
                }
            }
        }
        return result;
    }

    static int Solve3(string s) {
        int result = 0;
        int[] counts = new int[3];
        var previousPositions = new Dictionary<long, int>();
        for (int i = 0; i < s.Length; i++) {
            var c = s[i];
            counts[c - 'a']++;
            if (counts[0] == counts[1] && counts[1] == counts[2]) {
                result = i + 1;
            } else {
                var diff = (counts[0] - counts[1]) * 100001 + counts[1] - counts[2];
                if (previousPositions.TryGetValue(diff, out var previous)) {
                    result = Math.Max(result, i - previous);
                } else {
                    previousPositions[diff] = i;
                }
            }
        }
        return result;
    }
}