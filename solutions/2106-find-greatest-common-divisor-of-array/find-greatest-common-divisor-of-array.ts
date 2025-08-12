function findGCD(nums: number[]): number {
  let mn = nums[0], mx = nums[0];
  for (const x of nums) {
    if (x < mn) mn = x;
    if (x > mx) mx = x;
  }
  let a = mn, b = mx;
  while (b !== 0) {
    const t = a % b;
    a = b;
    b = t;
  }
  return a;
}