// TypeScript Solution
function permuteUnique(nums: number[]): number[][] {
    let results: number[][] = [];
    let counter: { [key: number]: number } = {};
    for (let num of nums) {
        if (!(num in counter)) counter[num] = 0;
        counter[num]++;
    }
    const backtrack = (comb: number[], N: number) => {
        if (comb.length == N) {
            results.push([...comb]);
            return;
        }
        for (let num in counter) {
            if (counter[num] == 0) continue;
            comb.push(parseInt(num));
            counter[num]--;
            backtrack(comb, N);
            comb.pop();
            counter[num]++;
        }
    };
    backtrack([], nums.length);
    return results;
}