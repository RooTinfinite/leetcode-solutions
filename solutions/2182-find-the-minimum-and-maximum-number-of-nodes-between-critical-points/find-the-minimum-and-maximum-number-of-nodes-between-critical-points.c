/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int capacity = 100000;
    int* nums = (int*)malloc(capacity * sizeof(int));
    int n = 0;

    while (head) {
        nums[n++] = head->val;
        head = head->next;
    }

    int* points = (int*)malloc(n * sizeof(int));
    int m = 0;

    for (int i = 1; i < n - 1; i++) {
        if (
            (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ||
            (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
        ) {
            points[m++] = i;
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    if (m < 2) {
        result[0] = -1;
        result[1] = -1;

        free(nums);
        free(points);

        return result;
    }

    int minDist = INT_MAX;
    int maxDist = points[m - 1] - points[0];

    for (int i = 1; i < m; i++) {
        int dist = points[i] - points[i - 1];

        if (dist < minDist) {
            minDist = dist;
        }
    }

    result[0] = minDist;
    result[1] = maxDist;

    free(nums);
    free(points);

    return result;
}