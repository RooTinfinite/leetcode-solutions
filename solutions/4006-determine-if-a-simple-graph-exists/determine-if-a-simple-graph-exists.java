

class Solution {
    public boolean simpleGraphExists(int[] degrees) {
        // cnt[i] : number of nodes having degree i
        int[] cnt = new int[degrees.length];
        for(int i : degrees) {
            if(i >= cnt.length) return false;
            cnt[i]++;
        }

        // remove nodes from high degree
        for(int i = cnt.length - 1; i > 0;) {
            if(cnt[i] != 0) {
                if(cnt[i] > i) {
                    cnt[i] -= i + 1;
                    cnt[i-1] += i;
                }else{
                    int last = cnt[i] - 1;
                    cnt[i] = 0;
                    int r = i - last;
                    for(int j = i - 1; j > 0; j--) {
                        if(cnt[j] > 0) {
                            int cut = Math.min(cnt[j], r);
                            r -= cut;
                            cnt[j] += last - cut;
                            last = cut;
                        }else if(last != 0) {
                            cnt[j] += last;
                            last = 0;
                        }
                        if(last == 0 && r == 0) break;
                    }
                    if(r != 0) return false;
                }
            }else i--;
        }
        for(int i = 1; i < cnt.length; i++) if(cnt[i] > 0) return false;
        return true;
    }
}