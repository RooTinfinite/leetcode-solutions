def maximum_beauty(items, queries)
    # Step 1: Sort items by price
    items.sort_by! { |item| item[0] }
    
    # Step 2: Extract prices and beauties
    prices = items.map { |item| item[0] }
    beauties = items.map { |item| item[1] }
    
    # Step 3: Create running maximum beauty array
    max_beauties = [0]
    current_max = 0
    beauties.each do |beauty|
        current_max = [current_max, beauty].max
        max_beauties << current_max
    end
    
    # Step 4: Find maximum beauty for each query price using binary search
    queries.map do |query|
        left = 0
        right = prices.length
        while left < right
            mid = (left + right) / 2
            if prices[mid] <= query
                left = mid + 1
            else
                right = mid
            end
        end
        max_beauties[left]
    end
end