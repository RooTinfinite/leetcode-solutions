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
 * @return {number}
 */
var averageOfSubtree = function(root) {
    let result = 0;

    const traverse = (node) => {
        if (!node) {
            return [0, 0];
        }

        const [leftSum, leftCount] = traverse(node.left);
        const [rightSum, rightCount] = traverse(node.right);

        const currSum = node.val + leftSum + rightSum;
        const currCount = 1 + leftCount + rightCount;

        if (Math.floor(currSum / currCount) === node.val) {
            result++;
        }

        return [currSum, currCount];
    };

    traverse(root);

    return result;
};