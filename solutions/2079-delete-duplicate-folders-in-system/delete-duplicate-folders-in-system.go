type Trie struct {
	serial   string           // current node structure's serialized representation
	children map[string]*Trie // current node's child nodes
}

func deleteDuplicateFolder(paths [][]string) [][]string {
	root := &Trie{children: make(map[string]*Trie)} // root node
	// build a trie tree
	for _, path := range paths {
		cur := root
		for _, node := range path {
			if _, ok := cur.children[node]; !ok {
				cur.children[node] = &Trie{children: make(map[string]*Trie)}
			}
			cur = cur.children[node]
		}
	}

	freq := make(map[string]int) // hash table records the occurrence times of each serialized representation
	// post-order traversal based on depth-first search, calculate the serialized representation of each node structure
	var construct func(*Trie)
	construct = func(node *Trie) {
		if len(node.children) == 0 {
			return // if it is a leaf node, no operation is needed.
		}
		v := make([]string, 0, len(node.children))
		for folder, child := range node.children {
			construct(child)
			v = append(v, folder+"("+child.serial+")")
		}
		sort.Strings(v)
		node.serial = strings.Join(v, "")
		freq[node.serial]++
	}
	construct(root)
	ans := make([][]string, 0)
	path := make([]string, 0)
	// operate the trie, delete duplicate folders
	var operate func(*Trie)
	operate = func(node *Trie) {
		if freq[node.serial] > 1 {
			return // if the serialization representation appears more than once, it needs to be deleted
		}

		if len(path) > 0 {
			tmp := make([]string, len(path))
			copy(tmp, path)
			ans = append(ans, tmp)
		}

		for folder, child := range node.children {
			path = append(path, folder)
			operate(child)
			path = path[:len(path)-1]
		}
	}
	operate(root)

	return ans
}