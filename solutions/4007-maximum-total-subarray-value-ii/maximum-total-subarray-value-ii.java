class Solution {

    int infm = Integer.MIN_VALUE;
    int infx = Integer.MAX_VALUE;

    class Segment{

        int[][] tree;
        int n;
        Segment(int[] arr){
            n = arr.length;
            tree = new int[n*4][2];
            build (arr, 0, 0, n-1);
        }

        int[] build(int[] arr, int idx, int a, int b){

            if(a==b){
                tree[idx][0] = arr[a];
                tree[idx][1] = arr[a];
                return tree[idx];
            }

            int m = a + (b-a)/2;

            int[] left = build(arr, idx*2+1, a, m);
            int[] right = build(arr, idx*2+2, m+1, b);

            tree[idx][0] = Math.min( left[0], right[0]);
            tree[idx][1] = Math.max( left[1], right[1]);

            return tree[idx];

        }

        int[] query(int idx, int q1, int q2, int a, int b){

            if(q1> b || q2<a)return new int[]{infx, infm};
            if(q1<=a && q2>=b)return tree[idx];

            int mid = a + (b-a)/2;
            
            int[] left = query(idx*2+1, q1, q2, a, mid);
            int[] right = query(idx*2+2, q1, q2, mid+1, b);

            int minVal = Math.min(left[0], right[0]);
            int maxVal = Math.max(left[1], right[1]);
            return new int[]{minVal, maxVal};
        }

        

    }
    

    public long maxTotalValue(int[] nums, int k) {
        
        long res=0;
        Segment seg = new Segment(nums);
        int n = nums.length;

        PriorityQueue<int[]> pq = new PriorityQueue<>( (a,b)-> Integer.compare(b[0], a[0]));
        HashSet<Long> set = new HashSet<>();

        int[] x = seg.query(0, 0, n-1, 0, n-1);
        pq.add(new int[]{x[1]-x[0], 0, n-1});

        while(k>0){

            int[] curr = pq.poll();

            res+=(long)curr[0];

            int a = curr[1];
            int b = curr[2];

            if(a+1<=b && !set.contains( ((long)(a+1)*n) + b)){
                int[] g = seg.query(0, a+1, b, 0, n-1);
                set.add( ((long)(a+1)*n) + b);
                pq.add(new int[]{ g[1]-g[0], a+1, b});
            }
            
            if(a<=b-1 && !set.contains( ((long)(a)*n) + b-1)){
                int[] h = seg.query(0, a, b-1, 0, n-1);
                set.add( ((long)(a)*n) + b-1);
                pq.add(new int[]{ h[1]-h[0], a, b-1});
            }   
            
            k--;
        }

        return res;

    }
}