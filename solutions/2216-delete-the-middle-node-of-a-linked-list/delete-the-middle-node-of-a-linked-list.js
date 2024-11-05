// Time complexity: O(n)
// Space complexity: O(1)
var deleteMiddle = function(head) {
    // Initialize slow and fast pointers to reach middle of linked list...
    let slow = fast = head;
    // Find the middle and previous of middle...
    let prev = null;
    // To store previous of slow pointer...
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    // Delete the middle node...
    if (!prev) return null;
    prev.next = slow.next;
    return head;
};