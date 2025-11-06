function swapPairs(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(-1);
    dummy.next = head;
    let prevNode = dummy;
    while (head && head.next) {
        const firstNode = head;
        const secondNode = head.next;
        prevNode.next = secondNode;
        firstNode.next = secondNode.next;
        secondNode.next = firstNode;
        prevNode = firstNode;
        head = firstNode.next;
    }
    return dummy.next;
}