impl Solution {
    pub fn asteroids_destroyed(mass: i32, asteroids: Vec<i32>) -> bool {
        let mut asteroids = asteroids;
        asteroids.sort();   // Sort by mass in ascending order
        let mut current_mass = mass as i64;  // Preventing integer overflow
        for asteroid in asteroids {
            // Traverse the asteroids in order, attempt to destroy and update mass or return the result
            if current_mass < asteroid as i64 {
                return false;
            }
            current_mass += asteroid as i64;
        }
        true   // Successfully destroy all asteroids
    }
}