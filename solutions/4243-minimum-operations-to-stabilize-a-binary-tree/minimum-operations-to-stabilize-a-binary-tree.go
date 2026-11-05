type stabilizeHeap struct {
	left, right *stabilizeHeap
	key, lazy   int
	rank        int
}

func stabilizeShift(h *stabilizeHeap, delta int) {
	if h != nil {
		h.key += delta
		h.lazy += delta
	}
}

func stabilizePush(h *stabilizeHeap) {
	if h.lazy != 0 {
		stabilizeShift(h.left, h.lazy)
		stabilizeShift(h.right, h.lazy)
		h.lazy = 0
	}
}

func stabilizeMeld(a, b *stabilizeHeap, maxHeap bool) *stabilizeHeap {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}
	if (maxHeap && a.key < b.key) || (!maxHeap && a.key > b.key) {
		a, b = b, a
	}
	stabilizePush(a)
	a.right = stabilizeMeld(a.right, b, maxHeap)

	leftRank, rightRank := 0, 0
	if a.left != nil {
		leftRank = a.left.rank
	}
	if a.right != nil {
		rightRank = a.right.rank
	}
	if leftRank < rightRank {
		a.left, a.right = a.right, a.left
	}
	a.rank = 1
	if a.right != nil {
		a.rank += a.right.rank
	}
	return a
}

func stabilizePop(h *stabilizeHeap, maxHeap bool) *stabilizeHeap {
	stabilizePush(h)
	result := stabilizeMeld(h.left, h.right, maxHeap)
	h.left = nil
	h.right = nil
	h.rank = 1
	return result
}

type stabilizeState struct {
	left, right *stabilizeHeap
	cost        int64
}

func stabilizeSolve(node *TreeNode) stabilizeState {
	if node == nil {
		return stabilizeState{}
	}

	a := stabilizeSolve(node.Left)
	b := stabilizeSolve(node.Right)

	stabilizeShift(a.left, -1)
	stabilizeShift(a.right, 1)
	stabilizeShift(b.left, -1)
	stabilizeShift(b.right, 1)

	state := stabilizeState{
		left:  stabilizeMeld(a.left, b.left, true),
		right: stabilizeMeld(a.right, b.right, false),
		cost:  a.cost + b.cost,
	}

	pair := new(struct {
		left, right stabilizeHeap
	})
	pair.left.key = node.Val
	pair.left.rank = 1
	pair.right.key = node.Val
	pair.right.rank = 1

	state.left = stabilizeMeld(state.left, &pair.left, true)
	state.right = stabilizeMeld(state.right, &pair.right, false)

	for state.left.key > state.right.key {
		l, r := state.left, state.right
		state.cost += int64(l.key - r.key)
		state.left = stabilizePop(l, true)
		state.right = stabilizePop(r, false)
		state.left = stabilizeMeld(state.left, r, true)
		state.right = stabilizeMeld(state.right, l, false)
	}

	return state
}

func stabilizeBinaryTree(root *TreeNode) int64 {
	return stabilizeSolve(root).cost
}