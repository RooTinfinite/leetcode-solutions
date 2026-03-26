class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        HashMap<Long, Integer> h = new HashMap<Long, Integer>();
        long totalSum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                totalSum += grid[i][j];
                long t = grid[i][j] * 1l;
                if (!h.containsKey(t)) {
                    h.put(t, 1);
                } else {
                    h.put(t, h.get(t) + 1);
                }
            }
        }
        long sum = 0;
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        for (int i = 0; i < grid.length - 1; i++) {
            {
                for (int j = 0; j < grid[i].length; j++) {
                    sum += grid[i][j];
                    long t = grid[i][j] * 1l;
                    if (!map.containsKey(t)) {
                        map.put(t, 1);
                    } else {
                        map.put(t, map.get(t) + 1);
                    }
                }
                if (sum == totalSum - sum) {
                    return true;
                } else {
                    if (sum > (totalSum - sum)) {
                        long p = sum - (totalSum - sum);
                        if (i != 0) {
                            if (map.containsKey(p)) {
                                if(grid[0].length==1)
                                {
                                    long r=grid[0][0]*1l;
                                    long s=grid[i][0]*1l;
                                     if (r == p || s == p) {
                                    return true;
                                }
                                    
                                }
                                else
                                {
                                return true;
                                }
                            }
                        } else {
                            long r = grid[0][0] * 1l;
                            long s = grid[0][grid[0].length - 1] * 1l;
                            if (grid[0].length != 1) {
                                if (r == p || s == p) {
                                    return true;
                                }
                            }
                        }
                    } else {
                        long p = (totalSum - sum) - sum;
                        if (i != grid.length - 2) {
                            if (h.containsKey(p)) {
                                int x = h.get(p);
                                if (map.containsKey(p)) {
                                    int y = map.get(p);
                                    if (y < x) {
                                        if(grid[0].length!=1)
                                        {
                                        return true;
                                        }
                                        else
                                        {
                                            long r=grid[grid.length-1][0]*1l;
                                            long s=grid[i+1][0]*1l;
                                            if(r==p || s==p)
                                            {
                                                return true;
                                            }
                                        }
                                    }
                                } else {
                                    if(grid[0].length!=1)
                                        {
                                        return true;
                                        }
                                        else
                                        {
                                            long r=grid[grid.length-1][0]*1l;
                                            long s=grid[i+1][0]*1l;
                                            if(r==p || s==p)
                                            {
                                                return true;
                                            }
                                        }
                                }
                            }
                        } else {
                            long r = grid[grid.length - 1][0] * 1l;
                            long s = grid[grid.length - 1][grid[0].length - 1] * 1l;
                            if (grid[0].length != 1) {
                                if (r == p || s == p) {
                                    return true;
                                }
                            }
                        }
                    }
                }

            }

        }
        map = new HashMap<Long, Integer>();
        sum = 0;
        for (int i = 0; i < grid[0].length - 1; i++) {
            for (int j = 0; j < grid.length; j++) {
                long t = grid[j][i] * 1l;
                if (!map.containsKey(t)) {
                    map.put(t, 1);
                } else {
                    map.put(t, map.get(t) + 1);
                }
                sum += grid[j][i];
            }
            if (sum == (totalSum - sum)) {
                return true;
            } else {
                if (sum > totalSum - sum) {
                    if (i != 0) {
                        long p = sum - (totalSum - sum);
                        if (map.containsKey(p)) {
                           if(grid.length>1)
                           {
                            return true;
                           }
                            else
                           {
                                long r = grid[0][0] * 1l;
                                long s = grid[0][i] * 1l;
                                 if (r == p || s == p) {
                                return true;
                            }
                           }
                        }
                    } else {
                        long p = sum - (totalSum - sum);
                        long r = grid[0][0] * 1l;
                        long s = grid[grid.length - 1][0] * 1l;
                        if(grid.length!=1)
                        {
                            if(r==p || s==p)
                            {
                                return true;
                            }
                        }
                    }
                } else {
                    long p = (totalSum - sum) - sum;
                    if (i != grid[0].length - 2) {
                        if (h.containsKey(p)) {
                            int x = h.get(p);
                            if (map.containsKey(p)) {
                                int y = map.get(p);
                                if (y < x) {
                                    if(grid.length!=1)
                                    {
                                       return true;
                                    }
                                    else
                                    {
                                        long r=grid[0][i+1]*1l;
                                        long s=grid[0][grid[0].length-1]*1l;
                                        if(r==p || s==p)
                                        {
                                            return true;
                                        }
                                    }
                                }
                            } else {
                                if(grid.length!=1)
                                    {
                                       return true;
                                    }
                                    else
                                    {
                                        long r=grid[0][i+1]*1l;
                                        long s=grid[0][grid[0].length-1]*1l;
                                        if(r==p || s==p)
                                        {
                                            return true;
                                        }
                                    }
                            }
                        }
                    } else {
                        long r = grid[0][grid[0].length - 1] * 1l;
                        long s = grid[grid.length - 1][grid[0].length - 1] * 1l;
                        if (grid.length != 1) {
                            if (r == p || s == p) {
                                return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
}