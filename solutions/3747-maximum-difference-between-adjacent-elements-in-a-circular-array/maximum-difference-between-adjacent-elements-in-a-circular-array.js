const maxAdjacentDistance = (nums, p = nums.at(-1)) =>
    nums.reduce((max, v) => Math.max(max, Math.abs(p - v), (p = v) - v), 0);