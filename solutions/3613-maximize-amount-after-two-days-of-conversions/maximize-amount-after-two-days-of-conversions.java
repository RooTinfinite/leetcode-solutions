class Solution {
    public double maxAmount(String initialCurrency, List<List<String>> pairs1, double[] rates1, List<List<String>> pairs2, double[] rates2) {
        double maxCost = 1.0;
        Map<String, List<Pair<String, Double>>> graph1 = graph(pairs1, rates1);
        Map<String, List<Pair<String, Double>>> graph2 = graph(pairs2, rates2);

        Map<String, Double> cost1 = new HashMap<>();
        dfs(initialCurrency, 1.0, graph1, new HashSet<>(), cost1);
        Map<String, Double> cost2 = new HashMap<>();
        dfs(initialCurrency, 1.0, graph2, new HashSet<>(), cost2);    

        for(String curr: cost1.keySet()) {
            double mul1 = cost1.get(curr);
            if (cost2.containsKey(curr)) {
                double mul2 = 1/cost2.get(curr);
                maxCost = Math.max(maxCost, mul1 * mul2);
            }
        }
        return maxCost;
    }


    private void dfs(String node, double curCost, Map<String, List<Pair<String, Double>>> graph, Set<String> visited, Map<String, Double> cost) {
        if (visited.contains(node)) { return; }
        visited.add(node);
        cost.put(node, curCost);
        if (!graph.containsKey(node)) { return; }
        for (Pair<String, Double> pair: graph.get(node)) {
            dfs(pair.getKey(), curCost * pair.getValue(), graph, visited, cost);
        }
    }

    private Map<String, List<Pair<String, Double>>> graph(List<List<String>> pairs, double[] rates) {
        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        for (int i = 0; i < pairs.size(); i++) {
            List<String> pair = pairs.get(i);
            graph.computeIfAbsent(pair.get(0), (x) -> new ArrayList<>())
                .add(new Pair(pair.get(1), rates[i]));
            graph.computeIfAbsent(pair.get(1), (x) -> new ArrayList<>())
                .add(new Pair(pair.get(0), 1.0/rates[i]));
        } 
        return graph;
    }
 }