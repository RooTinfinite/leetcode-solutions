class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long temp = mass;
        for (int i = 0; i < asteroids.length; i++) {
            if (asteroids[i] <= temp) temp += asteroids[i];
            else return false;
        }
        return true;
    }
}