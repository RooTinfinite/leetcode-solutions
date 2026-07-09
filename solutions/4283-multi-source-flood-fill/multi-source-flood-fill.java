class Solution {
    public int[][] colorGrid(int n, int m, int[][] sources) {
        int[][] grid = new int[n][m];
        Queue<int[]> q = new LinkedList<>();

        int totalColored = 0;

        for(int[] s : sources){
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            totalColored++;
            q.offer(new int[]{r, c});
        }

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};

        while(!q.isEmpty() && totalColored < n * m){
            int size = q.size();
            Map<String, Integer> updates = new HashMap<>();

            while(size-- > 0){
                int[] cur = q.poll();
                int r = cur[0], c = cur[1];

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                        String key = nr + "," + nc;
                        updates.put(key, Math.max(
                                updates.getOrDefault(key, 0),
                                grid[r][c]
                        ));
                    }
                }
            }

            for(Map.Entry<String, Integer> it : updates.entrySet()){
                String[] parts = it.getKey().split(",");
                int r = Integer.parseInt(parts[0]);
                int c = Integer.parseInt(parts[1]);

                grid[r][c] = it.getValue();
                totalColored++;
                q.offer(new int[]{r, c});
            }
        }

        return grid;
    }
}