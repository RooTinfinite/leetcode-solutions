def kth_factor(n, k)
    count = 0
    for i in 1..n do
        if n % i == 0
            count+=1
            if count == k
                return i
            end
        end
    end
    return -1
end