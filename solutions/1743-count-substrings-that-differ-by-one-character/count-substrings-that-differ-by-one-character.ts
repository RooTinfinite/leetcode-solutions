function countSubstrings(s: string, t: string): number {
  const substrings = getSubstrings(s);
  const tSubstringsByLength = getSubstringsByLength(t);
  const cache = new Map<string, number>();
  let result = 0;
  for (let i = 0; i < substrings.length; i++) {
    if (cache.has(substrings[i])) {
      result += cache.get(substrings[i])!;
      continue;
    }
    const tSubstrings = tSubstringsByLength.get(substrings[i].length) ?? [];
    const count = getDifferByOneCount(substrings[i], tSubstrings);
    cache.set(substrings[i], count);
    result += count;
  }
  return result;
}

function getDifferByOneCount(substring: string, substrings: string[]) {
  let result = 0;
  for (let i = 0; i < substrings.length; i++) {
    let differ = 0;
    for (let j = 0; j < substring.length; j++) {
      if (differ > 1) {
        break;
      }
      if (substring[j] !== substrings[i][j]) {
        differ++;
      }
      if (j === substring.length - 1 && differ === 1) {
        result++;
      }
    }
  }
  return result;
}

function getSubstrings(s: string): string[] {
  const substrings: string[] = [];
  for (let count = 1; count <= s.length; count++) {
    for (let start = 0; start < s.length; start++) {
      if (start + count > s.length) {
        continue;
      }
      const substr = s.slice(start, start + count);
      substrings.push(substr);
    }
  }
  return substrings;
}

function getSubstringsByLength(s: string): Map<number, string[]> {
  const substringsMap = new Map<number, string[]>();
  for (let count = 1; count <= s.length; count++) {
    for (let start = 0; start < s.length; start++) {
      if (!substringsMap.has(count)) {
        substringsMap.set(count, []);
      }
      if (start + count > s.length) {
        continue;
      }
      const substr = s.slice(start, start + count);
      substringsMap.get(count)!.push(substr);
    }
  }
  return substringsMap;
}