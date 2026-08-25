struct Data {
    struct TreeNode *p;
    struct TreeNode *q;
};
typedef struct Node {
    struct Data data;
    struct Node *next;
} Node;
typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;
void enqueue(Queue *q, struct TreeNode *p, struct TreeNode *qVal) {
    if (!q->head) {
        q->head = q->tail = malloc(sizeof(Node));
        q->head->data.p = p;
        q->head->data.q = qVal;
        q->head->next = NULL;
    } else {
        q->tail->next = malloc(sizeof(Node));
        q->tail = q->tail->next;
        q->tail->data.p = p;
        q->tail->data.q = qVal;
        q->tail->next = NULL;
    }
}
void dequeue(Queue *q, struct TreeNode **p, struct TreeNode **qVal) {
    if (q->head) {
        Node *node = q->head;
        *p = node->data.p;
        *qVal = node->data.q;
        q->head = q->head->next;
        free(node);
    }
}
bool is_empty(Queue *q) { return q->head == NULL; }
bool check(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return true;
}
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    Queue deq = {NULL, NULL};
    ;
    enqueue(&deq, p, q);
    while (!is_empty(&deq)) {
        struct TreeNode *pVal, *qVal;
        dequeue(&deq, &pVal, &qVal);
        if (!check(pVal, qVal)) return false;
        if (pVal) {
            enqueue(&deq, pVal->left, qVal->left);
            enqueue(&deq, pVal->right, qVal->right);
        }
    }
    return true;
}