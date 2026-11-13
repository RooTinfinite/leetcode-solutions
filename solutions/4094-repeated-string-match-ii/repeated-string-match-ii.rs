impl Solution {
    pub fn repeated_string_match(a: String, b: String, x: i32, y: i32) -> bool {
        let a: &[u8] = a.as_bytes();
		let b: &[u8] = b.as_bytes();

		let (x, y) = (x as usize, y as usize);

		let (m, n) = (a.len(), b.len());

		if m * x < n * y { return false;}

		let mut memo: Vec<Vec<usize>> = vec![vec![m; n];m];

		for st in 0..m {
			let mut i = st;
			let mut j = 0;
			let mut d: usize = 0;
			loop {
				if a[i] != b[j] { break;}
				if memo[i][j] == st {
					let a_rem = m * x - st - d;
					let b_rem = n * y - d;
					if a_rem >= b_rem {
						return true;
					} else {
						break;
					}
				}
				memo[i][j] = st;
				i = (i +  1) % m;
				j = (j + 1) % n;
				d += 1;
				if d + st > m * x { break;}
				if d == n * y {return true;}
			}
		}

		false
    }
}