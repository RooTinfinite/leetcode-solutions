use itertools::Itertools;
impl Solution {
    pub fn find_latest_time(s: String) -> String {
        let v:(char, char, char, char) = s.chars().filter(|x| *x != ':').collect_tuple().unwrap();
        let mut rslt = String::new();
        match (v.0, v.1) {
            ('?', '?') => rslt.push_str("11"),
            ('?', '0'|'1') => {rslt.push('1');rslt.push(v.1);},
            ('?', _) => {rslt.push('0');rslt.push(v.1);},
            ('0', '?') => rslt.push_str("09"),
            ('1', '?') => rslt.push_str("11"),
            (_, _) => {rslt.push(v.0);rslt.push(v.1);},
        }
        rslt.push(':');
        match (v.2, v.3) {
            ('?', '?') => rslt.push_str("59"),
            ('?', _) => {rslt.push('5');rslt.push(v.3);},
            (_, '?') => {rslt.push(v.2);rslt.push('9');},
            (_, _) => {rslt.push(v.2);rslt.push(v.3);},
        }
        rslt
    }
}