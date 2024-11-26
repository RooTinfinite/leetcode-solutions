def find_champion(n, edges)
    is_undefeated = Array.new(n, true)
    
    edges.each do |winner, loser|
        is_undefeated[loser] = false
    end
    
    champion = -1
    champion_count = 0
    
    n.times do |team|
        if is_undefeated[team]
            champion = team
            champion_count += 1
        end
    end
    
    champion_count == 1 ? champion : -1
end