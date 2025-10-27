function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null,
): ListNode | null {
    let dummyHead = new ListNode(0);
    let curr = dummyHead;
    let carry = 0;
    while (l1 !== null || l2 !== null || carry !== 0) {
        let x = l1 !== null ? l1.val : 0;
        let y = l2 !== null ? l2.val : 0;
        let sum = carry + x + y;
        carry = Math.floor(sum / 10);
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }
    return dummyHead.next;
}