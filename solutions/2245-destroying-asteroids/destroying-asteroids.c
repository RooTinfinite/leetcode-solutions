// Comparison function for sorting
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int),
          cmp);                    // Sort by mass in ascending order
    long long currentMass = mass;  // Preventing integer overflow
    for (int i = 0; i < asteroidsSize; i++) {
        // Traverse the asteroids in order, attempt to destroy and update mass
        // or return the result
        if (currentMass < asteroids[i]) {
            return false;
        }
        currentMass += asteroids[i];
    }
    return true;  // Successfully destroy all asteroids
}