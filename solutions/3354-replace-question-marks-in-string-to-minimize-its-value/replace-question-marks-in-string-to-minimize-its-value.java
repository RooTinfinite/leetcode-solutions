public class Solution {
    public String minimizeStringValue(String s) {
        int[] freq = new int[26];
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != '?') {
                freq[s.charAt(i) - 'a']++;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            pq.add(new Pair(freq[i], (char)('a' + i)));
        }
        
        StringBuilder temp = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '?') {
                Pair pair = pq.poll();
                char toInsert = pair.ch;
                int frequency = pair.freq;
                temp.append(toInsert);
                pq.add(new Pair(++frequency, toInsert));
            }
        }
        
        char[] tempArr = temp.toString().toCharArray();
        Arrays.sort(tempArr);
        String sortedTemp = new String(tempArr);
        
        StringBuilder result = new StringBuilder(s);
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '?') {
                result.setCharAt(i, sortedTemp.charAt(j++));
            }
        }
        
        return result.toString();
    }
    
    class Pair implements Comparable<Pair> {
        int freq;
        char ch;
        
        Pair(int freq, char ch) {
            this.freq = freq;
            this.ch = ch;
        }
        
        @Override
        public int compareTo(Pair other) {
            if(this.freq == other.freq) {
                return this.ch - other.ch;
            }
            return this.freq - other.freq;
        }
    }
}