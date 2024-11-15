class Solution(object):
    def flatten(self, head):
        # Initialize the current reference and stack of saved next pointers
        curr, tempStack = head, [];
        while curr:
            if curr.child:
                # If the current node is a parent
                if curr.next:
                    # Save the current node's old next pointer for future reattachment
                    tempStack.append(curr.next);
                # Current <-> Current.child
                #   \-> None
                curr.next, curr.child.prev, curr.child = curr.child, curr, None;
            if not curr.next and len(tempStack):
                # If the current node is a child without a next pointer
                temp = tempStack.pop();
                # Current <-> Temp
                temp.prev, curr.next = curr, temp;
            curr = curr.next;
        return head;