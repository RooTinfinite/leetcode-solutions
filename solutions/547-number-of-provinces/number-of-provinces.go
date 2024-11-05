type UF struct {
	p      []int
	height []int
}

func NewUF(n int) *UF {
	uf := UF{}
	uf.p = make([]int, n)
	uf.height = make([]int, n)
	for i := 0; i < n; i++ {
		uf.p[i] = i
		uf.height[i] = 1
	}
	return &uf
}

func (uf *UF) find(u int) int {
	if uf.p[u] == u {
		return u
	}
	return uf.find(uf.p[u])
}

func (uf *UF) merge(root1, root2 int) {
	if root1 == root2 {
		return
	}
	if uf.height[root1] < uf.height[root2] {
		root1, root2 = root2, root1
	}
	uf.p[root2] = root1
	uf.height[root1] = max(uf.height[root1], 1+uf.height[root2])
}

func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)
	uf := NewUF(n)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if isConnected[i][j] == 1 {
				root1 := uf.find(i)
				root2 := uf.find(j)
				uf.merge(root1, root2)
			}
		}
	}
	
	components := make(map[int]bool)
	for i := 0; i < n; i++ {
		components[uf.find(i)] = true
	}
	
	return len(components)
}