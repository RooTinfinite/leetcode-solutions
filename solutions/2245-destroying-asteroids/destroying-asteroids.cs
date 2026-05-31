public class Solution {
    public bool AsteroidsDestroyed(int mass, int[] asteroids) {
        Array.Sort(asteroids);    // Sort by mass in ascending order
        long currentMass = mass;  // Preventing integer overflow
        foreach (int asteroid in asteroids) {
            // Traverse the asteroids in order, attempt to destroy and update
            // mass or return the result
            if (currentMass < asteroid) {
                return false;
            }
            currentMass += asteroid;
        }
        return true;  // Successfully destroy all asteroids
    }
}