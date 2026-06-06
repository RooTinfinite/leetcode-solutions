class Solution {
    public List<Long> mergeAdjacent(int[] nums) {
        Stack<Long> stack=new Stack<>();
        for(int i:nums){
            long curr=i;
            while(!stack.isEmpty()&&stack.peek()==curr){
                curr=stack.pop()+curr;
            }
            stack.push(curr);
        }
        return new ArrayList<>(stack);
    }
}