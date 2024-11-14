/*
// Definition for a Node.
class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
};
*/
class Solution {
private:
    // HashMap which holds old nodes as keys and new nodes as its values.
    unordered_map<Node*, Node*> visitedHash;

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        // If we have already processed the current node, then we simply return
        // the cloned version of it.
        if (this->visitedHash.find(head) != this->visitedHash.end()) {
            return this->visitedHash[head];
        }
        // Create a new node with the value same as old node. (i.e. copy the
        // node)
        Node* node = new Node(head->val, NULL, NULL);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this
        // would help us avoid them.
        this->visitedHash[head] = node;
        // Recursively copy the remaining linked list starting once from the
        // next pointer and then from the random pointer. Thus we have two
        // independent recursive calls. Finally we update the next and random
        // pointers for the new node created.
        node->next = this->copyRandomList(head->next);
        node->random = this->copyRandomList(head->random);
        return node;
    }
};