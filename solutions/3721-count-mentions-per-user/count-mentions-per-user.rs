impl Solution {
    pub fn count_mentions(n: i32, mut events: Vec<Vec<String>>) -> Vec<i32> {
        let n = n as usize;
        events.sort_by(|a, b| {
            let ta = a[1].parse::<i32>().unwrap();
            let tb = b[1].parse::<i32>().unwrap();

            ta.cmp(&tb).then_with(|| {
                (a[0] != "OFFLINE").cmp(&(b[0] != "OFFLINE"))
            })
        });

        let mut count = vec![0; n];
        let mut next_online = vec![0; n];

        for e in events {
            let cur = e[1].parse::<i32>().unwrap();

            match e[0].as_str() {
                "MESSAGE" => match e[2].as_str() {
                    "ALL" => count.iter_mut().for_each(|x| *x += 1),
                    "HERE" => {
                        for i in 0..n {
                            if next_online[i] <= cur {
                                count[i] += 1;
                            }
                        }
                    }
                    other => {
                        for id in other.split_whitespace() {
                            let idx: usize = id[2..].parse().unwrap();
                            count[idx] += 1;
                        }
                    }
                },
                _ => {
                    let id: usize = e[2].parse().unwrap();
                    next_online[id] = cur + 60;
                }
            }
        }

        count
    }
}