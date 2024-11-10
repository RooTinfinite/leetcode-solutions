// TypeScript

function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    for (let j = 0, i = m; j < n; j++, i++) {
        nums1[i] = nums2[j];
    }
    nums1.sort((a, b) => a - b);
}