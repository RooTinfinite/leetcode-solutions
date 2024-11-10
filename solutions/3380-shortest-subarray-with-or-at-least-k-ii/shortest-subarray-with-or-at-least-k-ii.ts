//TypeScript

function minimumSubarrayLength(nums: number[], k: number): number {
    let ans = Infinity;
    let s = 0;
    let left = 0;
    const cnt = new Array(32).fill(0);
    
    for (let right = 0; right < nums.length; right++) {
        let num = nums[right];
        s |= num;
        let i = 0;
        let temp = num;
        while (temp > 0) {
            cnt[i] += temp % 2;
            temp = Math.floor(temp / 2);
            i++;
        }
        
        while (s >= k && left <= right) {
            ans = Math.min(right - left + 1, ans);
            temp = nums[left];
            i = 0;
            while (temp > 0) {
                if (temp % 2) {
                    cnt[i]--;
                    if (cnt[i] === 0) {
                        s ^= 1 << i;
                    }
                }
                temp = Math.floor(temp / 2);
                i++;
            }
            left++;
        }
    }
    return ans === Infinity ? -1 : ans;
}