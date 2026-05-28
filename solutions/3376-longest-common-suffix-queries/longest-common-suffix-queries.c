#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int minLen;
    int idx;
} TrieNode;

TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->minLen = INT_MAX;
    node->idx = INT_MAX;
    return node;
}

void insert(TrieNode* root, const char* s, int idx) {
    int len = strlen(s);
    TrieNode* node = root;

    if (len < node->minLen) {
        node->minLen = len;
        node->idx = idx;
    }

    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (node->children[c] == NULL) {
            node->children[c] = createTrieNode();
        }
        node = node->children[c];
        if (len < node->minLen) {
            node->minLen = len;
            node->idx = idx;
        }
    }
}

int query(TrieNode* root, const char* s) {
    TrieNode* node = root;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (node->children[c] != NULL) {
            node = node->children[c];
        } else {
            break;
        }
    }

    return node->idx;
}

void freeTrie(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}

int* stringIndices(char** wordsContainer, int containerSize, char** wordsQuery,
                   int querySize, int* returnSize) {
    TrieNode* root = createTrieNode();
    for (int i = 0; i < containerSize; i++) {
        reverseString(wordsContainer[i]);
        insert(root, wordsContainer[i], i);
    }

    int* res = (int*)malloc(querySize * sizeof(int));
    for (int i = 0; i < querySize; i++) {
        reverseString(wordsQuery[i]);
        res[i] = query(root, wordsQuery[i]);
    }

    *returnSize = querySize;
    freeTrie(root);

    return res;
}