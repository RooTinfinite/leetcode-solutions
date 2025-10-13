class Solution {

    static class DSU {
        int parent[], size[];

        DSU(int n){
            parent = new int[n+1];
            size = new int[n+1];

            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x){
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void union(int a, int b){
            a = find(a);
            b = find(b);
            if(a == b) return;

            if(size[a] < size[b]){
                int tmp = a;
                a = b;
                b = tmp;
            }

            parent[b] = a;
            size[a] += size[b];
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {

        DSU dsu = new DSU(c);

        for(int[] e : connections){
            dsu.union(e[0], e[1]);
        }

        HashMap<Integer, PriorityQueue<Integer>> map = new HashMap<>();
        boolean[] onoff = new boolean[c+1];
        Arrays.fill(onoff,true);

        for(int i=1; i<=c; i++){
            int par = dsu.find(i);
            map.computeIfAbsent(par, _ -> new PriorityQueue<>()).add(i);
        }

        List<Integer> list = new ArrayList<>();

        for(int[] q : queries) {
            if(q[0] == 1){
                if(onoff[q[1]]){
                    list.add(q[1]);
                } else {
                    int par = dsu.find(q[1]);
                    PriorityQueue<Integer> heap = map.get(par);

                    while(heap != null && !heap.isEmpty() && !onoff[heap.peek()]){
                        heap.poll();
                    }

                    int ans = (heap == null || heap.isEmpty()) ? -1 : heap.peek();
                    list.add(ans);
                }
            } else {
                if(onoff[q[1]]){
                    onoff[q[1]] = false;
                }
            }
        }

        return list.stream().mapToInt(Integer::intValue).toArray();   
    }
}