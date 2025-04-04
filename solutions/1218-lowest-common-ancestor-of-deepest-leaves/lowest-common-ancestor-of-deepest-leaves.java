

class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        int depth=depth(root);
        List<Integer>li=new ArrayList<>();
        Queue<TreeNode>qu=new LinkedList<>();
        qu.add(root);
        while(!qu.isEmpty()){
            int size=qu.size();
            depth--;
            for(int i=0;i<size;i++){
                if(depth==0){
                    li.add(qu.peek().val);
                }
                TreeNode nn=qu.poll();
                if(nn.left!=null){
                    qu.add(nn.left);
                }
                if(nn.right!=null){
                    qu.add(nn.right);
                }

            }
        }
        if(li.size()==1) return LCA(root,li.get(0),li.get(0));
        else{
            int a=li.get(0);
            int b=li.get(li.size()-1);
            return LCA(root,a,b);
        }
        
        
    }
    public static TreeNode LCA(TreeNode root,int a,int b){
        if(root==null) return root;
        if(root.val==a || root.val==b) return root;
        TreeNode left=LCA(root.left,a,b);
        TreeNode right=LCA(root.right,a,b);
        if(left==null) return right;
        else if(right==null) return left;
        else return root;

    }
    public static int depth(TreeNode root){
        if(root==null) return 0;
        return 1+Math.max(depth(root.left),depth(root.right));
    }
}