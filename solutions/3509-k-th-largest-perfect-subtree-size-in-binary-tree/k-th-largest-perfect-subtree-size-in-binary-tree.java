class Solution {
    public class Subtree{
        boolean isp ;
        int height ;
        int size ;
        public Subtree(boolean isp , int height , int size){
            this.isp = isp;
            this.height = height;
            this.size = size;
        }
    }
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        help(root , k , q);
        return q.size() < k ? -1 : q.peek();
    }
    public Subtree help(TreeNode node, int k , PriorityQueue<Integer> q){
        if(node == null){
            return new Subtree(true , -1 , 0);
        }

        Subtree left = help(node.left , k , q);        
        Subtree right = help(node.right , k , q);  

        boolean isp = left.isp && right.isp && (left.height == right.height);
        int height = Math.max(left.height , right.height) + 1;
        int size = left.size + right.size + 1;

        if(isp){
            if(q.size() < k){
                q.offer(size);
            }else{
                q.offer(size);
                q.poll();
            }
        }

        return new Subtree(isp , height , size);
    }
}