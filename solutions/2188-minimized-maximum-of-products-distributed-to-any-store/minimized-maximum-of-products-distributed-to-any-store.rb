def minimized_maximum(n, quantities)
    def can_distribute(x, quantities, n)
        stores = 0
        quantities.each do |q|
            stores += (q.to_f / x).ceil
        end
        stores <= n
    end
    
    left = 1
    right = quantities.max
    result = 0
    
    while left <= right
        x = (left + right) / 2
        if can_distribute(x, quantities, n)
            result = x
            right = x - 1
        else
            left = x + 1
        end
    end
    
    result
end