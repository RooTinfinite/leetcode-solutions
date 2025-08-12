def min_time_to_type(word)
  ans = word.length
  cur = 1
  word.each_byte do |b|
    pos = b - 96
    diff = (pos - cur).abs
    ans += [diff, 26 - diff].min
    cur = pos
  end
  ans
end