var leafSimilar = function(root1, root2) 
{
    const v1 = [];
    const v2 = [];        
    const inorder = (root, v) => {
        if (root) 
        {
                inorder(root.left, v);
                if (!root.left && !root.right) 
                {
                    v.push(root.val);
                }
                inorder(root.right, v);
            }
        };
        inorder(root1, v1);
        inorder(root2, v2);
        return JSON.stringify(v1) === JSON.stringify(v2);
};