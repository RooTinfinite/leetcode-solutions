const minDeletions = (s: string): number => {
  const charCounter: { [char: string]: number } = {};
  for (const char of s) charCounter[char] = (charCounter[char] ?? 0) + 1;
  const counts = Object.values(charCounter).sort((a, b) => b - a);
  let minDeletions = 0;
  for (let i = 1; i < counts.length; i++) {
    if (counts[i] < counts[i - 1]) continue;
    const deletions = Math.min(counts[i], counts[i] - counts[i - 1] + 1);
    counts[i] -= deletions;
    minDeletions += deletions;
  }
  return minDeletions;
};