/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
    const temp = [];
    let node = head;
    while (node) {
        temp.push(node.val);
        node = node.next;
    }
    const n = temp.length;
    node = head;
    let res = -Infinity;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        res = Math.max(res, node.val + temp.pop());
        node = node.next;
    }
    return res;
};