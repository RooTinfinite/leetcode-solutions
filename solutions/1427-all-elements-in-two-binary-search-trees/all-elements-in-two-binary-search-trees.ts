function getAllElements(
  root1: TreeNode | null,
  root2: TreeNode | null,
  list: number[] = []
): number[] {
  const getAllNodes = (root: TreeNode | null) => {
    if (root) {
      list.push(root.val);
      getAllNodes(root.left);
      getAllNodes(root.right);
    }
  };

  getAllNodes(root1);
  getAllNodes(root2);

  return list.sort((a, b) => a - b);
}