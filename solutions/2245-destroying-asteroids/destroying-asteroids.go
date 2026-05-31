func asteroidsDestroyed(mass int, asteroids []int) bool {
	sort.Ints(asteroids)       // Sort by mass in ascending order
	currentMass := int64(mass) // Preventing integer overflow
	for _, asteroid := range asteroids {
		// Traverse the asteroids in order, attempt to destroy and update mass
		// or return the result
		if currentMass < int64(asteroid) {
			return false
		}
		currentMass += int64(asteroid)
	}
	return true // Successfully destroy all asteroids
}