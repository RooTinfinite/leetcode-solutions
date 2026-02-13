/**
 * @param {string} s
 * @return {number}
 */
var longestBalanced = function (s) {
  const n = s.length;
  let ans = 0;
  for (let i = 0; i < n; ) {
    const start = i++;
    while (i < n && s[i] === s[i - 1]) 
        i++;
    ans = Math.max(ans, i - start);
  }

  ans = Math.max(ans, twoChars(s, 'a', 'b'));
  ans = Math.max(ans, twoChars(s, 'a', 'c'));
  ans = Math.max(ans, twoChars(s, 'b', 'c'));

  const pos = new Map();
  pos.set(key(0, 0), -1);

  let ca = 0, cb = 0, cc = 0;
  for (let i = 0; i < n; i++) {
    const ch = s[i];
    if (ch === 'a') 
        ca++;
    else if (ch === 'b') 
        cb++;
    else if (ch === 'c') 
        cc++;
    const d1 = ca - cb;
    const d2 = cb - cc;
    const k = key(d1, d2);

    if (pos.has(k)) 
        ans = Math.max(ans, i - pos.get(k));
    else pos.set(k, i);
  }

  return ans;
};

function twoChars(s, x, y) {
  const n = s.length;
  let best = 0;

  const first = new Int32Array(2 * n + 1);
  first.fill(2147483647); 

  const touched = new Int32Array(2 * n + 1);
  let touchedSz = 0;

  let i = 0;
  while (i < n) {
    const segStart = i;

    first[n] = segStart - 1;
    touched[touchedSz++] = n;

    let d = 0;
    while (i < n && (s[i] === x || s[i] === y)) {
      d += (s[i] === x) ? 1 : -1;
      const idx = d + n;

      if (first[idx] !== 2147483647) 
        best = Math.max(best, i - first[idx]);
      else {
        first[idx] = i;
        touched[touchedSz++] = idx;
      }
      i++;
    }

    for (let k = 0; k < touchedSz; k++) 
        first[touched[k]] = 2147483647;
    touchedSz = 0;

    i++;
  }

  return best;
}

function key(d1, d2) {
  return d1 + "," + d2;
}