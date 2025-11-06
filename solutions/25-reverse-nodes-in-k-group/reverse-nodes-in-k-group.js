var reverseLinkedList = function (head, k) {
    let new_head = null;
    let ptr = head;
    while (k > 0) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
};
var reverseKGroup = function (head, k) {
    let count = 0;
    let ptr = head;
    while (count < k && ptr != null) {
        ptr = ptr.next;
        count++;
    }
    if (count == k) {
        let reversedHead = reverseLinkedList(head, k);
        head.next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
};