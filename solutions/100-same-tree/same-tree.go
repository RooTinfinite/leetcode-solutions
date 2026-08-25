func check(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    if p == nil || q == nil {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    return true
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
    type NodePair struct {
        p *TreeNode
        q *TreeNode
    }
    deq := []NodePair{{p, q}}
    for len(deq) > 0 {
        var pair NodePair
        pair, deq = deq[0], deq[1:]
        p = pair.p
        q = pair.q
        if !check(p, q) {
            return false
        }
        if p != nil {
            deq = append(deq, NodePair{p.Left, q.Left})
            deq = append(deq, NodePair{p.Right, q.Right})
        }
    }
    return true
}