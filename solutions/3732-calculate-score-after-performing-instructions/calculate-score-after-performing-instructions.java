class Solution {
    public long calculateScore(String[] instructions, int[] values) {
        long score=0;
        int i=0;
        boolean[] used=new boolean[values.length];
        while(i>=0 && i<instructions.length){
            if(used[i]){
                break;
            }
            used[i]=true;
            if(instructions[i].equals("add")){
                score+=values[i];
                i++;
            }
            else{
                i+=values[i];
            }
        }
        return score;
    }
}