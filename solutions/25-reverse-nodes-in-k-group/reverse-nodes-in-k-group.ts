function reverseLinkedList(head: ListNode | null, k: number): ListNode | null {
    let new_head: ListNode | null = null;
    let ptr: ListNode | null = head;
    while (k > 0 && ptr != null) {
        let next_node: ListNode | null = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    let count: number = 0;
    let ptr: ListNode | null = head;
    while (count < k && ptr != null) {
        ptr = ptr.next;
        count++;
    }
    if (count == k) {
        let reversedHead: ListNode | null = reverseLinkedList(head, k);
        if (head) head.next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
}