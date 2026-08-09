class Solution {
    public int minimumGroups(String[] words) {
        HashSet<String> set = new HashSet<>();

        for (String w : words) {
            StringBuilder even = new StringBuilder();
            StringBuilder odd = new StringBuilder();

            for (int i = 0; i < w.length(); i++) {
                if ((i & 1) == 0)
                    even.append(w.charAt(i));
                else
                    odd.append(w.charAt(i));
            }

            String key = canonical(even.toString()) + "|" + canonical(odd.toString());
            set.add(key);
        }

        return set.size();
    }

    private String canonical(String s){
        int n = s.length();
        if(n <= 1) return s;

        int start = booth(s);
        String ss = s + s;
        return ss.substring(start, start + n);
    }

    private int booth(String s) {
        String t = s + s;
        int n = s.length();

        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            char a = t.charAt(i + k);
            char b = t.charAt(j + k);

            if (a == b) {
                k++;
            } else if (a > b) {
                i = i + k + 1;
                if (i <= j)
                    i = j + 1;
                k = 0;
            } else {
                j = j + k + 1;
                if (j <= i)
                    j = i + 1;
                k = 0;
            }
        }

        return Math.min(i, j);
    }
}