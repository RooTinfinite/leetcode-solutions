var asteroidsDestroyed = function (mass, asteroids) {
    asteroids.sort((a, b) => a - b); // Sort by mass in ascending order
    let currentMass = mass; // JavaScript numbers can safely handle large integers
    for (const asteroid of asteroids) {
        // Traverse the asteroids in order, attempt to destroy and update mass or return the result
        if (currentMass < asteroid) {
            return false;
        }
        currentMass += asteroid;
    }
    return true; // Successfully destroy all asteroids
};