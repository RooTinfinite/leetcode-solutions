class Solution {
    int n;
    Integer[][] dp;
    public int maxWalls(int[] robots, int[] distance, int[] walls) {

        this.n = robots.length;
        int[][] arr = new int[n][2];
        dp = new Integer[n][2];

        for(int i=0;i<n;i++){

            arr[i][0] = robots[i];
            arr[i][1] = distance[i];

        }

        Arrays.sort(arr, (a,b) -> Integer.compare(a[0], b[0]));
        Arrays.sort(walls);

        return rec(0, 0, arr, walls);   
    }

    int rec(int idx, int last, int[][] arr, int[] walls){

        if(idx==n)return 0;

        if(dp[idx][last]!=null)return dp[idx][last];

        int left = arr[idx][0] - arr[idx][1];
        int right = arr[idx][0] + arr[idx][1];

        if(last==0){
            if(idx-1>=0)
            left = Math.max(left, arr[idx-1][0]+1);
            if(idx+1<n)
            right = Math.min(right, arr[idx+1][0]-1);

            int neg = kill(walls, left, arr[idx][0]) + rec(idx+1, 0, arr, walls);
            int pos = kill(walls, arr[idx][0], right) + rec(idx+1, 1, arr, walls);

            return dp[idx][last]= Math.max(neg, pos);
        }
        else{
            if(idx-1>=0)
            left = Math.max(left, arr[idx-1][0]+arr[idx-1][1]+1);
            if(idx+1<n)
            right = Math.min(right, arr[idx+1][0]-1);

            int neg = kill(walls, left, arr[idx][0]) + rec(idx+1, 0, arr, walls);
            int pos = kill(walls, arr[idx][0], right) + rec(idx+1, 1, arr, walls);

            return dp[idx][last]= Math.max(neg, pos);
        }
    }

    int kill(int[] walls, int a, int b){

        int x = abound(walls, a);
        
        int y = bbound(walls, b);

        if(x==-1){
            if(y==-1)return 0;
            else return y+1;
        }
        else{
            return y-x;
        }
        
    }

    int abound(int[] walls, int v){

        int l = 0;
        int r = walls.length-1;
        int ans = -1;

        while(l<=r){

            int m = l + (r-l)/2;
            
            if(walls[m] < v){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }

        return ans;
    }

    int bbound(int[] walls, int v){

        int l = 0;
        int r = walls.length-1;
        int ans = -1;

        while(l<=r){

            int m = l + (r-l)/2;
            
            if(walls[m] <= v){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }

        return ans;
    }


}