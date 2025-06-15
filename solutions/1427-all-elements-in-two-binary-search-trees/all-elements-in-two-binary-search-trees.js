var getAllElements = function (root1, root2, list = []) {
  const getAllNodes = (root) => {
    if (root) {
      list.push(root.val);
      getAllNodes(root.left);
      getAllNodes(root.right);
    }
  };

  getAllNodes(root1);
  getAllNodes(root2);

  return list.sort((a, b) => a - b);
};