func braceExpansionII(expression string) []string {
	idx := 0
	expr := expression

	isLetter := func(c byte) bool {
		return c >= 'a' && c <= 'z'
	}

	// item -> letter | { expr }
	var item func() map[string]bool
	var term func() map[string]bool
	var exprFunc func() map[string]bool

	item = func() map[string]bool {
		ret := make(map[string]bool)
		if expr[idx] == '{' {
			idx++
			ret = exprFunc()
		} else {
			ret[string(expr[idx])] = true
		}
		idx++
		return ret
	}

	// term -> item | item term
	term = func() map[string]bool {
		// Initialize an empty set and take its Cartesian product with
		// subsequent results
		ret := map[string]bool{"": true}
		// An item starts with { or a lowercase letter; continue matching only
		// when this condition is met
		for idx < len(expr) && (expr[idx] == '{' || isLetter(expr[idx])) {
			sub := item()
			tmp := make(map[string]bool)
			for left := range ret {
				for right := range sub {
					tmp[left+right] = true
				}
			}
			ret = tmp
		}
		return ret
	}

	// expr -> term | term, expr
	exprFunc = func() map[string]bool {
		ret := make(map[string]bool)
		for {
			// Take the union with the result of term()
			for k := range term() {
				ret[k] = true
			}
			// Continue if a comma is matched; otherwise, stop matching
			if idx < len(expr) && expr[idx] == ',' {
				idx++
				continue
			}
			break
		}
		return ret
	}

	retMap := exprFunc()
	result := make([]string, 0, len(retMap))
	for k := range retMap {
		result = append(result, k)
	}
	sort.Strings(result)
	return result
}