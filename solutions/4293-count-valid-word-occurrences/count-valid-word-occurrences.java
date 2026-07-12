class Solution {
    public int[] countWordOccurrences(String[] chunks, String[] queries) {
        StringBuilder s = new StringBuilder();

        for (String x : chunks) {
            s.append(x);
        }

        String v = s.toString();

        HashMap<String, Integer> m = new HashMap<>();

        int i = 0;
        int n = v.length();

        while (i < n) {
            char c = v.charAt(i);

            if (c < 'a' || c > 'z') {
                i++;
                continue;
            }

            StringBuilder t = new StringBuilder();

            int j = i;

            while (j < n) {
                c = v.charAt(j);

                if (c >= 'a' && c <= 'z') {
                    t.append(c);
                    j++;
                    continue;
                } else if (c == '-' &&
                        j > i &&
                        j + 1 < n &&
                        v.charAt(j - 1) >= 'a' &&
                        v.charAt(j - 1) <= 'z' &&
                        v.charAt(j + 1) >= 'a' &&
                        v.charAt(j + 1) <= 'z') {
                    t.append(c);
                    j++;
                } else {
                    break;
                }
            }
            String w = t.toString();
            m.put(w, m.getOrDefault(w, 0) + 1);
            i = j;
        }

        int[] a = new int[queries.length];

        for (i = 0; i < queries.length; i++) {
            a[i] = m.getOrDefault(queries[i], 0);
        }

        return a;
    }
}