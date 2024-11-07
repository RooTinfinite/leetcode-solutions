class Solution {
    func romanToInt(_ s: String) -> Int {
        let roman: [Character: Int] = [
            "I": 1, "V": 5, "X": 10,
            "L": 50, "C": 100, "D": 500, "M": 1000
        ]
        
        let chars = Array(s)
        let n = chars.count
        var result = roman[chars[n-1]]!
        
        for i in stride(from: n-2, through: 0, by: -1) {
            if roman[chars[i]]! < roman[chars[i+1]]! {
                result -= roman[chars[i]]!
            } else {
                result += roman[chars[i]]!
            }
        }
        
        return result
    }
}