def num_identical_pairs(a)
  ans = 0
  cnt = Hash.new(0)
  
  a.each do |x|
    ans += cnt[x]
    cnt[x] += 1
  end
  
  ans
end