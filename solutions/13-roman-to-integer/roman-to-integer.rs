impl Solution {
    fn calc_scale(c: Option<char>, a1: char, a2: char) -> i32 {
        match c {
            Some(ch) if ch == a1 || ch == a2 => -1,
            _ => 1,
        }
    }

    pub fn roman_to_int(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let mut result = 0;

        for n in 0..chars.len() {
            let next_char = chars.get(n + 1).copied();
            
            match chars[n] {
                'M' => result += 1000,
                'D' => result += 500,
                'C' => result += 100 * Self::calc_scale(next_char, 'M', 'D'),
                'L' => result += 50,
                'X' => result += 10 * Self::calc_scale(next_char, 'C', 'L'),
                'V' => result += 5,
                'I' => result += 1 * Self::calc_scale(next_char, 'X', 'V'),
                _ => (),
            }
        }
        result
    }
}