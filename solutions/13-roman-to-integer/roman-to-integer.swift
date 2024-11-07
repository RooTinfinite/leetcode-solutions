class Solution {
    static func calcScale(_ c: Character?, _ a1: Character, _ a2: Character) -> Int {
        guard let c = c else { return 1 }
        return (c == a1 || c == a2) ? -1 : 1
    }
    
    func romanToInt(_ s: String) -> Int {
        var result = 0
        let chars = Array(s)
        
        for n in 0..<chars.count {
            let nextChar = n + 1 < chars.count ? chars[n + 1] : nil
            
            switch chars[n] {
            case "M": result += 1000
            case "D": result += 500
            case "C": result += 100 * Solution.calcScale(nextChar, "M", "D")
            case "L": result += 50
            case "X": result += 10 * Solution.calcScale(nextChar, "C", "L")
            case "V": result += 5
            case "I": result += 1 * Solution.calcScale(nextChar, "X", "V")
            default: break
            }
        }
        return result
    }
}