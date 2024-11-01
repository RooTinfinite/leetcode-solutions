# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
    result = []
    find_combinations(0, target, candidates, [], result)
    result
end

def find_combinations(index, target, candidates, current, result)
    # Base case: if target becomes 0, we found a valid combination
    if target == 0
        result << current.clone
        return
    end
    
    # Try all possible numbers from current index
    (index...candidates.length).each do |i|
        # Only proceed if current number doesn't exceed target
        if candidates[i] <= target
            # Include current number in combination
            current << candidates[i]
            
            # Recursive call with same index i (allowing reuse)
            find_combinations(i, target - candidates[i], candidates, current, result)
            
            # Backtrack: remove the last added number
            current.pop
        end
    end
end