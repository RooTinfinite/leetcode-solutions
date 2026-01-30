use std::collections::HashMap;

const INF: i32 = i32::MAX / 2;

struct TrieNode {
    child: [Option<Box<TrieNode>>; 26],
    id: i32,
}

impl TrieNode {
    fn new() -> Self {
        Self {
            child: Default::default(),
            id: -1,
        }
    }
    
    fn add(node: &mut Box<TrieNode>, word: &str, index: &mut i32) -> i32 {
        let mut current = node;
        for ch in word.chars() {
            let i = (ch as u8 - b'a') as usize;
            if current.child[i].is_none() {
                current.child[i] = Some(Box::new(TrieNode::new()));
            }
            current = current.child[i].as_mut().unwrap();
        }
        if current.id == -1 {
            *index += 1;
            current.id = *index;
        }
        current.id
    }
}

impl Solution {
    pub fn minimum_cost(source: String, target: String, original: Vec<String>, changed: Vec<String>, cost: Vec<i32>) -> i64 {
        let n = source.len();
        let m = original.len();
        let mut root = Box::new(TrieNode::new());
        
        let mut p = -1;
        let node_count = m * 2;
        let mut g = vec![vec![INF; node_count]; node_count];
        for i in 0..node_count {
            g[i][i] = 0;
        }
        
        for i in 0..m {
            let x = TrieNode::add(&mut root, &original[i], &mut p);
            let y = TrieNode::add(&mut root, &changed[i], &mut p);
            g[x as usize][y as usize] = g[x as usize][y as usize].min(cost[i]);
        }
        
        let size = (p + 1) as usize;
        for k in 0..size {
            for i in 0..size {
                for j in 0..size {
                    g[i][j] = g[i][j].min(g[i][k] + g[k][j]);
                }
            }
        }
        
        let mut f = vec![-1i64; n];
        let source_chars: Vec<char> = source.chars().collect();
        let target_chars: Vec<char> = target.chars().collect();
        for j in 0..n {
            if j > 0 && f[j - 1] == -1 { 
                continue; 
            }
            let base = if j == 0 { 0 } else { f[j - 1] };
            if source_chars[j] == target_chars[j] {
                if f[j] == -1 || base < f[j] {
                    f[j] = base;
                }
            }
            
            let mut u = &root;
            let mut v = &root;
            for i in j..n {
                let u_idx = (source_chars[i] as u8 - b'a') as usize;
                let v_idx = (target_chars[i] as u8 - b'a') as usize;
                
                u = match u.child[u_idx].as_ref() {
                    Some(node) => node,
                    None => break,
                };
                v = match v.child[v_idx].as_ref() {
                    Some(node) => node,
                    None => break,
                };
                
                if u.id != -1 && v.id != -1 && g[u.id as usize][v.id as usize] != INF {
                    let new_val = base + g[u.id as usize][v.id as usize] as i64;
                    if f[i] == -1 || new_val < f[i] {
                        f[i] = new_val;
                    }
                }
            }
        }
        
        f[n - 1]
    }
}