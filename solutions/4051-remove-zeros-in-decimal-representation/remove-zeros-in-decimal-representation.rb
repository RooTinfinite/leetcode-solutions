def remove_zeros(n)
  result = n.to_s.gsub("0", "")
  result.to_i
end