/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    // Dummy node acts as the prevNode for the head node
    // of the list and hence stores pointer to the head node.
    dummy := &ListNode{-1, nil}
    dummy.Next = head
    prevNode := dummy
    for head != nil && head.Next != nil {
        // Nodes to be swapped
        firstNode := head
        secondNode := head.Next
        // Swapping
        prevNode.Next = secondNode
        firstNode.Next = secondNode.Next
        secondNode.Next = firstNode
        // Reinitializing the head and prevNode for next swap
        prevNode = firstNode
        head = firstNode.Next // jump
    }
    // Return the new head node.
    return dummy.Next
}