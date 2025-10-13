class Solution {
    class Pair {
        int a, b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public long hash(int a, int b) {
        return ((a * 1L) << 32) + b;
    }

    public int minMoves(int sx, int sy, int tx, int ty) {
        if(sx == 0 && sy == 0) {
            return tx == 0 && ty == 0 ? 0 : -1;
        }

        if(sx > tx || sy > ty) {
            return -1;
        }

        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(tx, ty));

        int moves = 0;
        while(!q.isEmpty()) {
            int sz = q.size();
            while(sz-- > 0) {
                Pair p = q.poll();
                int x = p.a, y = p.b;
                if(x == sx && y == sy) return moves;

                if(x > y) {
                    if(x - y <= y) {
                        if(x - y >= sx ) {
                            q.add(new Pair(x - y, y));
                        }
                    } 
                    
                    else if(x % 2 == 0 ) {
                        if(x /2 >= sx) {
                            q.add(new Pair(x / 2, y));
                        }
                    }
                } else if(x < y) {
                    if(x >= y - x) {
                        
                        if(y - x >= sy ) {
                            q.add(new Pair(x , y - x));
                        }

                    } 
                    
                    else if(y % 2 == 0) {
                        if(y / 2 >= sy) {
                            q.add(new Pair(x, y / 2));
                        }
                    }

                } else {
                        q.add(new Pair(0, y));
                        q.add(new Pair(x, 0));
                }
            }
            moves++;
        }

        return -1;
    }
}