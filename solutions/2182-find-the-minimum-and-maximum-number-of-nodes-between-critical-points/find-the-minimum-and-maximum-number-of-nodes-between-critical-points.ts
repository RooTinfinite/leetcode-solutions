/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    const nums: number[] = [];

    while (head) {
        nums.push(head.val);
        head = head.next;
    }

    const points: number[] = [];
    const n: number = nums.length;

    for (let i = 1; i < n - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            points.push(i);
        } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            points.push(i);
        }
    }

    const m: number = points.length;

    if (m < 2) {
        return [-1, -1];
    }

    let minDist: number = Infinity;
    const maxDist: number = points[m - 1] - points[0];

    for (let i = 1; i < m; i++) {
        minDist = Math.min(minDist, points[i] - points[i - 1]);
    }

    return [minDist, maxDist];
};