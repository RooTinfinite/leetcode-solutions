class Solution {
    private int[] result = new int[2];
    private boolean[] visited;
    private List<List<int[]>> graph;
    private boolean[] used;
    private int[][] next;
    private int[] prev;
    
    public int[] longestSpecialPath(int[][] edges, int[] values) {
        int n = values.length;
        int maxValue = 0;
        for (int v : values) maxValue = Math.max(maxValue, v);
        
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        
        for (int[] e : edges) {
            graph.get(e[0]).add(new int[]{e[1], e[2]});
            graph.get(e[1]).add(new int[]{e[0], e[2]});
        }
        
        visited = new boolean[n];
        used = new boolean[maxValue + 1];
        next = new int[n][2];
        prev = new int[n];
        result[0] = 0;
        result[1] = 1;
        
        used[values[0]] = true;
        visited[0] = true;
        process(values, 0, 0, 1, 0, -1);
        
        return result;
    }
    
    private void process(int[] values, int node, int len, int count, int start, int repeat) {
        if (len > result[0]) {
            result[0] = len;
            result[1] = count;
        } else if (len == result[0]) {
            result[1] = Math.min(result[1], count);
        }
        
        Map<Integer, List<int[]>> updates = new HashMap<>();
        
        for (int[] edge : graph.get(node)) {
            int nextNode = edge[0];
            int weight = edge[1];
            
            if (visited[nextNode]) continue;
            
            visited[nextNode] = true;
            next[node] = new int[]{nextNode, weight};
            prev[nextNode] = node;
            
            int val = values[nextNode];
            
            if (!used[val]) {
                used[val] = true;
                process(values, nextNode, len + weight, count + 1, start, repeat);
                used[val] = false;
            } else if (used[val] && repeat == -1) {
                process(values, nextNode, len + weight, count + 1, start, val);
            } else {
                if (!updates.containsKey(val)) updates.put(val, new ArrayList<>());
                updates.get(val).add(edge);
            }
            
            visited[nextNode] = false;
        }
        
        int originalStart = start;
        int originalLen = len;
        int originalRepeat = repeat;
        int originalCount = count;
        
        for (Map.Entry<Integer, List<int[]>> entry : updates.entrySet()) {
            int val = entry.getKey();
            
            while (true) {
                len -= next[start][1];
                count--;
                
                if (values[start] == repeat) {
                    repeat = val;
                    start = next[start][0];
                    break;
                }
                
                if (values[start] == val) {
                    start = next[start][0];
                    break;
                }
                
                used[values[start]] = false;
                start = next[start][0];
            }
            
            for (int[] edge : entry.getValue()) {
                int nextNode = edge[0];
                int weight = edge[1];
                
                visited[nextNode] = true;
                next[node] = new int[]{nextNode, weight};
                prev[nextNode] = node;
                
                process(values, nextNode, len + weight, count + 1, start, repeat);
                
                visited[nextNode] = false;
            }
            
            while (start != originalStart) {
                start = prev[start];
                used[values[start]] = true;
            }
            
            len = originalLen;
            repeat = originalRepeat;
            count = originalCount;
        }
    }
}