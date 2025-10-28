class Solution {

    int[] kmp(String s) {
        int[] pre = new int[s.length()];
        pre[0] = -1;
        for(int i = 1; i < s.length(); i++) {
            int j = pre[i - 1];
            while(j != -1 && s.charAt(j + 1) != s.charAt(i)) {
                j = pre[j];
            }
            if(s.charAt(j + 1) == s.charAt(i)) j++;
            pre[i] = j;
        }
        return pre;
    }


    public String generateString(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        char[] a = new char[m + n - 1];
        
        for(int i = 0, j = 0; i < m; i++) {
            if(str1.charAt(i) == 'T') {
                if(j < i) j = i;
                while(j < i + n) {
                    a[j] = str2.charAt(j++ - i);
                }
            }
        }

        int[] pre = kmp(str2);

        char[] actual = str1.toCharArray();

        int j = 0;
        for(int i = 0; i < a.length; i++) {
            if(str2.charAt(j) == a[i]) {
                if(j == n - 1) {
                    if(actual[i - j] != 'T') return "";
                    actual[i - j] = 'F';
                    j = pre[j];
                }
            } else {
                j--;
                while(j != -1 && str2.charAt(j + 1) != a[i] ) j = pre[j];
                if(str2.charAt(j + 1) == a[i]) j++;
            }
            j++;
        }

        for(char t : actual) if(t == 'T') return "";

        // fill A with 'a' and find if there is any KMP match
        // between A and str2 corresponding to a 'F' in str1,
        // if so, retry from last unfixed character.
        actual = str1.toCharArray();
        j = 0;
        int lastdot = -1;
        for(int i = 0; i < a.length; i++) {
            if(a[i] == 0) {
                lastdot = i;
                a[i] = 'a';
            }
            if(str2.charAt(j) == a[i]) {
                if(j == n - 1) {
                    if(actual[i - j] != 'T') { // found a match but a 'F'
                        a[lastdot]++;
                        j -= i - lastdot + 1; // retry
                        i = lastdot - 1; // retry
                    }else{
                        j = pre[j];
                    }
                }
            } else {
                j--;
                while(j != -1 && str2.charAt(j + 1) != a[i] ) j = pre[j];
                if(str2.charAt(j + 1) == a[i]) j++;
            }
            j++;
        }

        return new String(a);
    }
}