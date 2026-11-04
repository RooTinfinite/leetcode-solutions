typedef struct AVLNode {
    int value, count, height;
    struct AVLNode *left, *right;
} AVLNode;

typedef struct {
    AVLNode* root;
    int size;
    long long sum;
} MultiSet;

static int nodeHeight(AVLNode* node) { return node == NULL ? 0 : node->height; }

static void updateHeight(AVLNode* node) {
    int left = nodeHeight(node->left);
    int right = nodeHeight(node->right);
    node->height = 1 + (left > right ? left : right);
}

static AVLNode* rotateRight(AVLNode* root) {
    AVLNode* next = root->left;
    root->left = next->right;
    next->right = root;
    updateHeight(root);
    updateHeight(next);
    return next;
}

static AVLNode* rotateLeft(AVLNode* root) {
    AVLNode* next = root->right;
    root->right = next->left;
    next->left = root;
    updateHeight(root);
    updateHeight(next);
    return next;
}

static AVLNode* rebalance(AVLNode* root) {
    if (root == NULL) {
        return NULL;
    }
    updateHeight(root);
    int diff = nodeHeight(root->left) - nodeHeight(root->right);
    if (diff > 1) {
        if (nodeHeight(root->left->left) < nodeHeight(root->left->right)) {
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    if (diff < -1) {
        if (nodeHeight(root->right->right) < nodeHeight(root->right->left)) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }
    return root;
}

static AVLNode* insertNode(AVLNode* root, int value) {
    if (root == NULL) {
        AVLNode* node = malloc(sizeof(AVLNode));
        *node = (AVLNode){value, 1, 1, NULL, NULL};
        return node;
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        ++root->count;
        return root;
    }
    return rebalance(root);
}

static AVLNode* eraseNode(AVLNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->left = eraseNode(root->left, value);
    } else if (value > root->value) {
        root->right = eraseNode(root->right, value);
    } else {
        if (root->count > 1) {
            --root->count;
            return root;
        }
        if (root->left == NULL || root->right == NULL) {
            AVLNode* child = root->left != NULL ? root->left : root->right;
            free(root);
            return child;
        }
        AVLNode* next = root->right;
        while (next->left != NULL) {
            next = next->left;
        }
        root->value = next->value;
        root->count = next->count;
        next->count = 1;
        root->right = eraseNode(root->right, next->value);
    }
    return rebalance(root);
}

static bool contains(MultiSet* set, int value) {
    AVLNode* node = set->root;
    while (node != NULL) {
        if (value == node->value) {
            return true;
        }
        node = value < node->value ? node->left : node->right;
    }
    return false;
}

static int minValue(MultiSet* set) {
    AVLNode* node = set->root;
    while (node->left != NULL) {
        node = node->left;
    }
    return node->value;
}

static int maxValue(MultiSet* set) {
    AVLNode* node = set->root;
    while (node->right != NULL) {
        node = node->right;
    }
    return node->value;
}

static void addValue(MultiSet* set, int value) {
    set->root = insertNode(set->root, value);
    ++set->size;
    set->sum += value;
}

static void removeValue(MultiSet* set, int value) {
    set->root = eraseNode(set->root, value);
    --set->size;
    set->sum -= value;
}

static void freeTree(AVLNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

static long long* getCosts(int* nums, int n, int x) {
    long long* ops = calloc(n, sizeof(long long));
    MultiSet left = {0}, right = {0};

    for (int i = 0; i < n; ++i) {
        int value = nums[i];
        if (left.size == 0 || value <= maxValue(&left)) {
            addValue(&left, value);
        } else {
            addValue(&right, value);
        }
        if (i >= x) {
            value = nums[i - x];
            if (contains(&left, value)) {
                removeValue(&left, value);
            } else {
                removeValue(&right, value);
            }
        }
        if (left.size > right.size + 1) {
            value = maxValue(&left);
            removeValue(&left, value);
            addValue(&right, value);
        } else if (left.size < right.size) {
            value = minValue(&right);
            removeValue(&right, value);
            addValue(&left, value);
        }
        if (i >= x - 1) {
            long long mid = maxValue(&left);
            ops[i] = mid * left.size - left.sum + right.sum - mid * right.size;
        }
    }
    freeTree(left.root);
    freeTree(right.root);
    return ops;
}

long long minOperations(int* nums, int numsSize, int x, int k) {
    int n = numsSize;
    long long* ops = getCosts(nums, n, x);
    long long* pre = calloc(n + 1, sizeof(long long));
    long long* cur = malloc(sizeof(long long) * (n + 1));

    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i <= n; ++i) {
            cur[i] = LLONG_MAX;
        }
        for (int i = j * x; i <= n; ++i) {
            long long cost = pre[i - x] + ops[i - 1];
            cur[i] = cur[i - 1] < cost ? cur[i - 1] : cost;
        }
        long long* temp = pre;
        pre = cur;
        cur = temp;
    }
    long long answer = pre[n];
    free(ops);
    free(pre);
    free(cur);
    return answer;
}