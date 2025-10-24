class DSU{
    int parent[];
    int size[];

    DSU(int n){
        parent = new int[n];
        size = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }   
    }

    protected int find(int a){
        if(parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    protected void union(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb)
            return;
        
        if(size[pb] >= size[pa]){
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else if(size[pa] > size[pb]){
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
}

class Solution {
    public long maxAlternatingSum(int[] nums, int[][] swaps) {
        int n = nums.length;
        DSU dsu = new DSU(n);

        for(int arr[] : swaps){
            dsu.union(arr[0],arr[1]);
        }

        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0;i<n;i++){
            int p = dsu.find(i);
            List<Integer> list = map.getOrDefault(p,new ArrayList<>());
            list.add(i);
            map.put(p,list);
        }

        long res = 0L;
        for(int key : map.keySet()){
            List<Integer> list = map.get(key);
            List<Long> val = new ArrayList<>();
            int evenCount = 0;
            for(int i : list){
                val.add((long)nums[i]);
                if((i&1)==0)
                    evenCount++;
            }
            Collections.sort(val);
            int l = val.size()-1;
            while(evenCount-- > 0)
                res += val.get(l--);
            
            while(l >= 0)
                res -= val.get(l--);
        }

        return res;
    }
}