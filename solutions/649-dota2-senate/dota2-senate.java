
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Deque<Integer> radiant = new LinkedList<>();
        Deque<Integer> dire = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') {
                radiant.offer(i);
            } else {
                dire.offer(i);
            }
        }
        while (!radiant.isEmpty() && !dire.isEmpty()) {
            int r_idx = radiant.poll();
            int d_idx = dire.poll();
            if (r_idx < d_idx) {
                radiant.offer(r_idx + n);
            } else {
                dire.offer(d_idx + n);
            }
        }
        return radiant.isEmpty() ? "Dire" : "Radiant";
    }
}