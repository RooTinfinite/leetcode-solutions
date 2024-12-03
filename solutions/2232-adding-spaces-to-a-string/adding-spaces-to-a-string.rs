impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut result = vec![0u8; s.len() + spaces.len()];
        let mut write_pos = 0;
        let mut read_pos = 0;
        let s_bytes = s.as_bytes();
        
        for space_pos in spaces {
            while read_pos < space_pos as usize {
                result[write_pos] = s_bytes[read_pos];
                write_pos += 1;
                read_pos += 1;
            }
            result[write_pos] = b' ';
            write_pos += 1;
        }
        
        while read_pos < s.len() {
            result[write_pos] = s_bytes[read_pos];
            write_pos += 1;
            read_pos += 1;
        }
        
        String::from_utf8(result).unwrap()
    }
}