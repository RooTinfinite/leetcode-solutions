var longestConsecutive = function(root) {
    
    if(!root) return 0;
    let max = 0;
    
    const helper = function(node, target, length){
        
        if(node === null) return;
        
        if(node.val === target){
            length++;
            max = length > max ? length : max;
     
        }else{
            length = 1;
        }
        
        if(node.left) {helper(node.left,  node.val + 1,length)};
        if(node.right) {helper(node.right, node.val + 1,length)};        
    }
    
    helper(root, root.val, max);
    
    return max;
};