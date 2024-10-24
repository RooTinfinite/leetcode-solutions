function maxUniqueSplit(s: string): number {
  let res = 1
  let strings = new Set()
  function search(s: string) {
    if (!strings.has(s)) {
      strings.add(s)
      res = Math.max(res, strings.size)
      strings.delete(s)
    }
    for (let i = 1; i < s.length; i++) {
      const sub = s.substring(0, i)
      if (strings.has(sub)) continue
      strings.add(sub)
      search(s.substring(i))
      strings.delete(sub)
    }
  }
  search(s)
  return res
};