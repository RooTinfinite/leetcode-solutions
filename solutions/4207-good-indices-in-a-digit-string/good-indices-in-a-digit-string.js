/**
 * @param {string} s
 * @return {number[]}
 */
var goodIndices = function (s) {
  const ans = [];
  const n = s.length;

  for (let i = n - 1; i >= 0; i--) {
    const len = String(i).length;
    const j = +s.slice(i - len + 1, i + 1);
    if (j === i) ans.push(i);
  }

  return ans.reverse();
};