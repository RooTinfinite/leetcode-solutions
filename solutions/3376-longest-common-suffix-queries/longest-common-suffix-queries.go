func stringIndices(wordsContainer []string, wordsQuery []string) []int {
	trie := NewTrie()
	for i, word := range wordsContainer {
		reversed := reverseString(word)
		trie.Insert(reversed, i)
	}

	res := make([]int, len(wordsQuery))
	for i, query := range wordsQuery {
		reversed := reverseString(query)
		res[i] = trie.Query(reversed)
	}

	return res
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

type TrieNode struct {
	children [26]*TrieNode
	minLen   int
	idx      int
}

func NewTrieNode() *TrieNode {
	return &TrieNode{
		children: [26]*TrieNode{},
		minLen:   math.MaxInt32,
		idx:      math.MaxInt32,
	}
}

type Trie struct {
	root *TrieNode
}

func NewTrie() *Trie {
	return &Trie{root: NewTrieNode()}
}

func (t *Trie) Insert(s string, idx int) {
	length := len(s)
	node := t.root

	if length < node.minLen {
		node.minLen = length
		node.idx = idx
	}

	for i := 0; i < length; i++ {
		c := s[i] - 'a'
		if node.children[c] == nil {
			node.children[c] = NewTrieNode()
		}
		node = node.children[c]

		if length < node.minLen {
			node.minLen = length
			node.idx = idx
		}
	}
}

func (t *Trie) Query(s string) int {
	node := t.root

	for i := 0; i < len(s); i++ {
		c := s[i] - 'a'
		if node.children[c] != nil {
			node = node.children[c]
		} else {
			break
		}
	}

	return node.idx
}