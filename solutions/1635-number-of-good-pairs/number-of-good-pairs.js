function numIdenticalPairs(A) {
    let ans = 0;
    const cnt = {};
    
    for (let x of A) {
        ans += cnt[x] || 0;
        cnt[x] = (cnt[x] || 0) + 1;
    }
    
    return ans;
}
