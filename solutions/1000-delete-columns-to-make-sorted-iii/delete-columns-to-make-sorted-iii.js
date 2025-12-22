/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
  const n = strs[0].length;
  const m = strs.length;
  const dp = new Array(n).fill(1);

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < i; j++) {
      let ok = true;
      for (let r = 0; r < m; r++) {
        if (strs[r].charCodeAt(j) > strs[r].charCodeAt(i)) { ok = false; break; }
      }
      if (ok) dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }

  let mx = 0;
  for (const v of dp) mx = Math.max(mx, v);
  return n - mx;
};