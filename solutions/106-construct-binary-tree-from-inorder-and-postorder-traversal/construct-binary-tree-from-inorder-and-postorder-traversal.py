class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # If either of the input lists are empty, the tree is empty, so return None
        if not inorder or not postorder:
            return None

        # Initialize indices to the last elements of the inorder and postorder traversals
        ip = len(inorder) - 1
        pp = len(postorder) - 1

        # Create an empty stack to help us build the binary tree
        st = []
        # Initialize prev to None since we haven't processed any nodes yet
        prev = None
        # Create the root node using the last element in the postorder traversal
        root = TreeNode(postorder[pp])
        # Push the root onto the stack and move to the next element in the postorder traversal
        st.append(root)
        pp -= 1

        # Process the rest of the nodes in the postorder traversal
        while pp >= 0:
            # While the stack is not empty and the top of the stack is the current inorder element
            while st and st[-1].val == inorder[ip]:
                # The top of the stack is the parent of the current node, so pop it off the stack and update prev
                prev = st.pop()
                ip -= 1
            # Create a new node for the current postorder element
            new_node = TreeNode(postorder[pp])
            # If prev is not None, the parent of the current node is prev, so attach the node as the left child of prev
            if prev:
                prev.left = new_node
            # If prev is None, the parent of the current node is the current top of the stack, so attach the node as the right child of the current top of the stack
            elif st:
                curr_top = st[-1]
                curr_top.right = new_node
            # Push the new node onto the stack, reset prev to None, and move to the next element in the postorder traversal
            st.append(new_node)
            prev = None
            pp -= 1

        # Return the root of the binary tree
        return root