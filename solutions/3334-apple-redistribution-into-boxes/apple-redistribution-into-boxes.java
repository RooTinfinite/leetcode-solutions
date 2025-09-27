class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int n = apple.length;
        int m = capacity.length;
        int total_apple = 0;
        
        for(int i = 0; i < n; i++){
            total_apple += apple[i];
        }

        Arrays.sort(capacity);
        int count = 0;
        int freq = 0;
        for(int i = m-1; i >= 0; i--){
            count = count + capacity[i];
            freq++;
            if(count >= total_apple){
                break;
            }
        }
        return freq;
    }
}