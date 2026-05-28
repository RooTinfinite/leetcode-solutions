struct TrieNode {
    children: [Option<Box<TrieNode>>; 26],
    min_len: usize,
    idx: usize,
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            children: Default::default(),
            min_len: usize::MAX,
            idx: usize::MAX,
        }
    }
}

struct Trie {
    root: TrieNode,
}

impl Trie {
    fn new() -> Self {
        Trie {
            root: TrieNode::new(),
        }
    }

    fn insert(&mut self, s: &str, idx: usize) {
        let len = s.len();
        let mut node = &mut self.root;

        if len < node.min_len {
            node.min_len = len;
            node.idx = idx;
        }

        for ch in s.chars() {
            let c = (ch as usize) - ('a' as usize);
            if node.children[c].is_none() {
                node.children[c] = Some(Box::new(TrieNode::new()));
            }
            node = node.children[c].as_mut().unwrap();
            
            if len < node.min_len {
                node.min_len = len;
                node.idx = idx;
            }
        }
    }

    fn query(&self, s: &str) -> usize {
        let mut node = &self.root;

        for ch in s.chars() {
            let c = (ch as usize) - ('a' as usize);
            match &node.children[c] {
                Some(next) => node = &**next,
                None => break,
            }
        }

        node.idx
    }
}
impl Solution {
    pub fn string_indices(words_container: Vec<String>, words_query: Vec<String>) -> Vec<i32> {
        let mut trie = Trie::new();

        for (i, word) in words_container.iter().enumerate() {
            let reversed: String = word.chars().rev().collect();
            trie.insert(&reversed, i);
        }

        let mut res = Vec::with_capacity(words_query.len());
        for query in words_query.iter() {
            let reversed: String = query.chars().rev().collect();
            res.push(trie.query(&reversed) as i32);
        }

        res
    }
}