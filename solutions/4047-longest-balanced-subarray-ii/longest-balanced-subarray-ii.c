typedef struct ListNode ListNode;

typedef struct {
    ListNode* head;
    int size;
} List;

typedef struct {
    int key;
    List* val;
    UT_hash_handle hh;
} HashItem;

List* listCreate() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void listPush(List* list, int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void listPop(List* list) {
    if (list->head == NULL) return;
    ListNode* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

int listAt(List* list, int index) {
    ListNode* cur = list->head;
    for (int i = 0; i < index && cur != NULL; i++) {
        cur = cur->next;
    }
    return cur ? cur->val : -1;
}

void listReverse(List* list) {
    ListNode* prev = NULL;
    ListNode* cur = list->head;
    ListNode* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list->head = prev;
}

void listFree(List* list) {
    while (list->head != NULL) {
        listPop(list);
    }
    free(list);
}

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, List* val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

List* hashGetItem(HashItem** obj, int key) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        List* newList = listCreate();
        hashAddItem(obj, key, newList);
        return newList;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        listFree(curr->val);
        free(curr);
    }
}

void hashIterate(HashItem** obj, void (*callback)(HashItem* item)) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) { callback(curr); }
}

typedef struct {
    int toAdd;
} LazyTag;

void lazyTagAdd(LazyTag* tag, LazyTag* other) { tag->toAdd += other->toAdd; }

bool lazyTagHasTag(LazyTag* tag) { return tag->toAdd != 0; }

void lazyTagClear(LazyTag* tag) { tag->toAdd = 0; }

typedef struct {
    int minValue;
    int maxValue;
    LazyTag lazyTag;
} SegmentTreeNode;

typedef struct {
    int n;
    SegmentTreeNode* tree;
} SegmentTree;

void segmentTreeApplyTag(SegmentTree* seg, int i, LazyTag* tag) {
    seg->tree[i].minValue += tag->toAdd;
    seg->tree[i].maxValue += tag->toAdd;
    lazyTagAdd(&seg->tree[i].lazyTag, tag);
}

void segmentTreePushdown(SegmentTree* seg, int i) {
    if (lazyTagHasTag(&seg->tree[i].lazyTag)) {
        LazyTag tag = {seg->tree[i].lazyTag.toAdd};
        segmentTreeApplyTag(seg, i << 1, &tag);
        segmentTreeApplyTag(seg, (i << 1) | 1, &tag);
        lazyTagClear(&seg->tree[i].lazyTag);
    }
}

void segmentTreePushup(SegmentTree* seg, int i) {
    seg->tree[i].minValue =
        fmin(seg->tree[i << 1].minValue, seg->tree[(i << 1) | 1].minValue);
    seg->tree[i].maxValue =
        fmax(seg->tree[i << 1].maxValue, seg->tree[(i << 1) | 1].maxValue);
}

void segmentTreeBuild(SegmentTree* seg, int* data, int l, int r, int i) {
    if (l == r) {
        seg->tree[i].minValue = seg->tree[i].maxValue = data[l - 1];
        return;
    }

    int mid = l + ((r - l) >> 1);
    segmentTreeBuild(seg, data, l, mid, i << 1);
    segmentTreeBuild(seg, data, mid + 1, r, (i << 1) | 1);
    segmentTreePushup(seg, i);
}

void segmentTreeUpdate(SegmentTree* seg, int targetL, int targetR, LazyTag* tag,
                       int l, int r, int i) {
    if (targetL <= l && r <= targetR) {
        segmentTreeApplyTag(seg, i, tag);
        return;
    }

    segmentTreePushdown(seg, i);
    int mid = l + ((r - l) >> 1);
    if (targetL <= mid) {
        segmentTreeUpdate(seg, targetL, targetR, tag, l, mid, i << 1);
    }
    if (targetR > mid) {
        segmentTreeUpdate(seg, targetL, targetR, tag, mid + 1, r, (i << 1) | 1);
    }
    segmentTreePushup(seg, i);
}

int segmentTreeFind(SegmentTree* seg, int targetL, int targetR, int val, int l,
                    int r, int i) {
    if (seg->tree[i].minValue > val || seg->tree[i].maxValue < val) {
        return -1;
    }
    if (l == r) {
        return l;
    }

    segmentTreePushdown(seg, i);
    int mid = l + ((r - l) >> 1);
    if (targetR >= mid + 1) {
        int res = segmentTreeFind(seg, targetL, targetR, val, mid + 1, r,
                                  (i << 1) | 1);
        if (res != -1) {
            return res;
        }
    }
    if (targetL <= mid) {
        return segmentTreeFind(seg, targetL, targetR, val, l, mid, i << 1);
    }

    return -1;
}

SegmentTree* segmentTreeCreate(int* data, int n) {
    SegmentTree* seg = (SegmentTree*)malloc(sizeof(SegmentTree));
    seg->n = n;
    seg->tree = (SegmentTreeNode*)calloc(n * 4 + 1, sizeof(SegmentTreeNode));
    segmentTreeBuild(seg, data, 1, n, 1);
    return seg;
}

void segmentTreeAdd(SegmentTree* seg, int l, int r, int val) {
    LazyTag tag = {val};
    segmentTreeUpdate(seg, l, r, &tag, 1, seg->n, 1);
}

int segmentTreeFindLast(SegmentTree* seg, int start, int val) {
    if (start > seg->n) {
        return -1;
    }
    return segmentTreeFind(seg, start, seg->n, val, 1, seg->n, 1);
}

void segmentTreeFree(SegmentTree* seg) {
    free(seg->tree);
    free(seg);
}

int sgn(int x) { return (x % 2 == 0) ? 1 : -1; }

void reverseList(HashItem* item) { listReverse(item->val); }

int longestBalanced(int* nums, int numsSize) {
    HashItem* occurrences = NULL;
    int len = 0;
    int* prefixSum = (int*)calloc(numsSize, sizeof(int));

    prefixSum[0] = sgn(nums[0]);
    List* list0 = hashGetItem(&occurrences, nums[0]);
    listPush(list0, 1);
    for (int i = 1; i < numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1];
        List* occ = hashGetItem(&occurrences, nums[i]);
        if (occ->size == 0) {
            prefixSum[i] += sgn(nums[i]);
        }
        listPush(occ, i + 1);
    }

    hashIterate(&occurrences, reverseList);
    SegmentTree* seg = segmentTreeCreate(prefixSum, numsSize);
    for (int i = 0; i < numsSize; i++) {
        int findResult = segmentTreeFindLast(seg, i + len, 0);
        int newLen = findResult - i;
        if (newLen > len) {
            len = newLen;
        }

        int nextPos = numsSize + 1;
        List* occ = hashGetItem(&occurrences, nums[i]);
        listPop(occ);
        if (occ->size > 0) {
            nextPos = listAt(occ, 0);
        }
        segmentTreeAdd(seg, i + 1, nextPos - 1, -sgn(nums[i]));
    }

    segmentTreeFree(seg);
    free(prefixSum);
    hashFree(&occurrences);

    return len;
}