def find_champion(n, edges)
    incoming = Array.new(n, 0)
    
    edges.each do |src, dst|
        incoming[dst] += 1
    end
    
    champions = []
    incoming.each_with_index do |count, i|
        champions << i if count == 0
    end
    
    champions.length > 1 ? -1 : champions[0]
end