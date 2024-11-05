int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int j = 0;
    for (int i = 0; i < asteroidsSize; i++) {
        int asteroid = asteroids[i];

        while (j > 0 && asteroids[j - 1] > 0 && asteroid < 0 && asteroids[j - 1] < abs(asteroid)) 
        {
            j--;
        }

        if (j == 0 || asteroid > 0 || asteroids[j - 1] < 0) {
            asteroids[j++] = asteroid;
        } else if (asteroids[j - 1] == abs(asteroid)) {
            j--;
        }
    }

    int* result = (int*)malloc(j * sizeof(int));
    for (int i = 0; i < j; i++) {
        result[i] = asteroids[i];
    }

    *returnSize = j;
    return result;
}