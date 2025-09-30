class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) return 0;
        long totalEnergy = currentEnergy;
        for (int j = enemyEnergies.length - 1; j > 0; --j) totalEnergy += enemyEnergies[j];
        return totalEnergy / enemyEnergies[0];
    }
}