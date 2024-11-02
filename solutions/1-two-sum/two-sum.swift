class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var ht = [Int: Int]()
        
        for (i, num) in nums.enumerated() {
            if let j = ht[target - num] {
                return [j, i]
            }
            
            ht[num] = i
        }
        
        return []
    }
}