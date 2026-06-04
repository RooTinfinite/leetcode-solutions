class Solution {
    public int countMonobit(int n) {
        int limit = 1, count = 1;
        while(limit <= n){
            limit = limit + (int)Math.pow(2,count);
             count++;
        }
        return count;
    }
}