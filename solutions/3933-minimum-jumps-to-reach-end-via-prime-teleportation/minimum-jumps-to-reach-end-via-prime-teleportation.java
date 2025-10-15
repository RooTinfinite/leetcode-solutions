class Solution {
    public int minJumps(int[] a) {
        int n = a.length;
        if (n==1 || n==2) return n-1;
        
        int max = a[0];
        for (var v: a) max=Math.max(max, v);
        var isp = isPrime(max);

        List<Integer>[] inv = new List[max+1];
        for (int i=0;i<n;i++) {
            if (inv[a[i]]==null) inv[a[i]] = new ArrayList<Integer>();
            inv[a[i]].add(i);
        }
        
        var q = new ArrayDeque<Integer>();
        q.add(0);
        var ans = n-1;
        boolean[] vis = new boolean[n];
        boolean[] pvis = new boolean[max+1];
        vis[0] = true;
        int jumps = 0;
        while (q.size() > 0 && ans == n-1) {
            var size = q.size();
            jumps++;
            // System.out.println("jumps: " + jumps + "" + q);
            while (size-->0 && ans == n-1) {
                var curr = q.pollFirst();
                if (curr - 1 >= 0 && !vis[curr-1]) {
                    vis[curr-1] = true;
                    q.addLast(curr-1);
                }
                if (curr + 1 < n && !vis[curr+1]) {
                    if (curr+1 == n-1) {
                        ans = jumps;
                        break;
                    }
                    vis[curr+1] = true;
                    q.addLast(curr+1);
                }
                // System.out.println("checking a[curr] for prime "+a[curr]);
                if (isp[a[curr]] && !pvis[a[curr]]) {
                    int p = a[curr];
                    pvis[p]=true;
                    for (int i = 1; i*p <= max; i++) {
                        var v = i*p;
                        if (inv[v]==null) continue;
                        for (var index: inv[v]) {
                            if (vis[index]) continue;
                            vis[index] = true;
                            if (index == n-1) {
                                ans = jumps;
                                break;
                            }
                            q.addLast(index);
                        }
                    }
                }
            }            
        }

        return ans;
    }

    private boolean[] isPrime(int max) {
        boolean[] isp = new boolean[max+1];
        Arrays.fill(isp, true);
        isp[0]=false;
        isp[1]=false;
        for (int i = 2; i*i<=max; i++) {
            if (!isp[i]) continue;
            for (int j=i+i; j<= max; j+=i) isp[j]=false;
        }
        return isp;
    }
}