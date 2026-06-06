/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} level
 * @return {number}
 */
var levelMedian = function (root, level) {
  const temp = [];
  inOrder(root, 0, level, temp);

  if (temp.length === 0) return -1;
  return temp[Math.trunc(temp.length / 2)];
};

function inOrder(root, currLevel, level, temp) {
  if (!root) return;

  inOrder(root.left, currLevel + 1, level, temp);
  if (currLevel === level) {
    temp.push(root.val);
  }
  inOrder(root.right, currLevel + 1, level, temp);
}