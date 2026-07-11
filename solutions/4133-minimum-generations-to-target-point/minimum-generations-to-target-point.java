class Solution {

    private int cal(int a, int b) {
        int xa = a / 100;
        int ya = (a % 100) / 10;
        int za = a % 10;

        int xb = b / 100;
        int yb = (b % 100) / 10;
        int zb = b % 10;

        return 100 * ((xa + xb) / 2) + 10 * ((ya + yb) / 2) + (za + zb) / 2;
    }

    public int minGenerations(int[][] points, int[] target) {

        Set<Integer> s = new HashSet<>();

        for (int[] p : points) s.add(100 * p[0] + 10 * p[1] + p[2]);

        int t = 100 * target[0] + 10 * target[1] + target[2];

        int ans = 0;

        while (!s.contains(t)) {

            Set<Integer> temp = new HashSet<>(s);

            List<Integer> arr = new ArrayList<>(s);

            for (int i = 0; i < arr.size(); i++) {
                for (int j = i + 1; j < arr.size(); j++) {
                    temp.add(cal(arr.get(i), arr.get(j)));
                }
            }

            if (temp.equals(s)) {
                return -1;
            }

            s = temp;
            ans++;
        }

        return ans;
    }
}