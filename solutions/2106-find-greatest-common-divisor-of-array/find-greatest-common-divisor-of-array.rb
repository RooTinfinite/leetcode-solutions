def find_gcd(nums)
  mn = nums[0]
  mx = nums[0]
  nums.each do |x|
    mn = x if x < mn
    mx = x if x > mx
  end
  a = mn
  b = mx
  while b != 0
    a, b = b, a % b
  end
  a
end