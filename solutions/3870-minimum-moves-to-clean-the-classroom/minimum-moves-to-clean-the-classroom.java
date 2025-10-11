class Solution {
    static class State {
        int r;      // row
        int c;      // column
        int mask;   // the state's mask (states of picked/not picked litters on all coordinates)
        int e;      // remaining energy at the state
        int steps;  // steps at the state

        State(int r, int c, int mask, int e, int steps) {
            this.r = r;
            this.c = c;
            this.mask = mask;
            this.e = e;
            this.steps = steps;
        }
    }
    public int minMoves(String[] classroom, int energy) {
        Map<Integer, Integer> rowColToBitIdx = new HashMap<>();
        int m = classroom.length, n = classroom[0].length();
        int L = 0, startR = 0, startC = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(classroom[i].charAt(j) == 'L') {
                    rowColToBitIdx.put(i*100 + j, L++);
                }
                else if(classroom[i].charAt(j) == 'S') {
                    startR = i;
                    startC = j;
                }
            }
        }

        int allCollected = (1 << L) - 1; 
        int[][] dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int[][][] bestEnergy = new int[m][n][1 << L];

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                Arrays.fill(bestEnergy[i][j], -1);
            }
        }

        Queue<State> q = new LinkedList<>();
        q.offer(new State(startR, startC, 0, energy, 0));

        while(!q.isEmpty()) {
            State s = q.poll();

            int litterState = 
                classroom[s.r].charAt(s.c) == 'L' ? 
                (s.mask | (1 << rowColToBitIdx.get(s.r * 100 + s.c))) : 
                s.mask;
            if(litterState == allCollected)
                return s.steps;

            int nextEnergy = classroom[s.r].charAt(s.c) == 'R' ? energy - 1 : s.e - 1;
            if(nextEnergy < 0) continue; 
            for(int[] dir : dirs) {
                int nextR = s.r + dir[0], nextC = s.c + dir[1];
                if(nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || classroom[nextR].charAt(nextC) == 'X') 
                    continue;
                
                if(bestEnergy[nextR][nextC][litterState] < nextEnergy){
                    bestEnergy[nextR][nextC][litterState] = nextEnergy;
                    q.offer(new State(nextR, nextC, litterState, nextEnergy, s.steps + 1));
                }
            }
            // System.out.println(q);
        }
        return -1;
    }
}