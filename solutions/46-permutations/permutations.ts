function permute(nums: number[]): number[][] {
    let ans: number[][] = [];
    function backtrack(curr: number[]) {
        if (curr.length === nums.length) {
            ans.push([...curr]);
            return;
        }
        for (let num of nums) {
            if (!curr.includes(num)) {
                curr.push(num);
                backtrack(curr);
                curr.pop();
            }
        }
    }
    backtrack([]);
    return ans;
}