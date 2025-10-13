class Solution {
    static int[] tree;
    static int n;

   
    static void build(int[] nums) {
        n = nums.length;
        tree = new int[4 * n]; 
        buildUtil(nums, 0, 0, n - 1);
    }

    static void buildUtil(int[] nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildUtil(nums, 2 * node + 1, start, mid);
            buildUtil(nums, 2 * node + 2, mid + 1, end);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

  
    static int query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }
    
    static int queryUtil(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftGCD = queryUtil(2 * node + 1, start, mid, l, r);
        int rightGCD = queryUtil(2 * node + 2, mid + 1, end, l, r);
        return gcd(leftGCD, rightGCD);
    }
	
	
	public int minStable(int[] nums, int maxC) {

        if(maxC == nums.length) return 0;

        int lo = 1;
        int hi = nums.length;
        int ans = nums.length;
        boolean allOne = true;
        int countOfNotOne = 0;
        tree = new int[8*nums.length];
        
        for(int i = 0;i<nums.length;i++){
            if(nums[i]!=1){
                allOne = false;
                countOfNotOne++;
            }
        }
        if(allOne || countOfNotOne ==maxC){
            return 0;
        }
        build(nums);
        while(lo<=hi){
            int mid = (lo+hi)/2;

            boolean ok = isPossible(nums, maxC,mid);

            if(ok){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
        
    }

    static boolean isPossible(int []nums, int max, int mid){

        int gcd = 0;
        int i = 0;
        
        while(i<nums.length) {
        	
        	if((i+mid)>=nums.length) break;
        	
        	gcd = query(i,i+mid);
        	
        	
        	if(gcd >=2) {
        		i = i+mid;
        		max--;
        	}
        	i++;
        }
        
        
        
        
        return (max>=0);
    }

    static int gcd(int a, int b){
        if(b==0) return a;

        return gcd(b, a%b);
    }
    
}