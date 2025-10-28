class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0;
        Map<Integer, List<Integer>> adjMat = new HashMap();
        for (int i = 0; i < routes.length; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                adjMat.computeIfAbsent(routes[i][j], k -> new ArrayList()).add(i);
            }
        }
        List<Integer> prevQ = new ArrayList();
        Set<Integer> visitedIndexes = new HashSet(), nextIndexes = new HashSet();
        prevQ.addAll(adjMat.computeIfAbsent(target, k -> new ArrayList()));
        int result = 0;
        while (!prevQ.isEmpty()) {
            result++;
            visitedIndexes.addAll(prevQ);
            for (int i : prevQ) { // Will be max 500
                for (int j : routes[i]) { // Will be max 10^5
                    if (j == source) return result;
                    for (int nextIndex : adjMat.get(j)) { // Will be max 500
                        if (!visitedIndexes.contains(nextIndex)) nextIndexes.add(nextIndex);
                    }
                }
            }
            prevQ.clear();
            prevQ.addAll(nextIndexes);
            nextIndexes.clear();
        }
        return -1;
    }
}