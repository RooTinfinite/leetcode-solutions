/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	first := -1

	last := -1

	minDistance := int(^uint(0) >> 1)

	position := 1

	prev := head

	curr := head.Next

	for curr != nil && curr.Next != nil {
		isCritical := (curr.Val > prev.Val && curr.Val > curr.Next.Val) ||
			(curr.Val < prev.Val && curr.Val < curr.Next.Val)

		if isCritical {
			if first == -1 {
				first = position
			} else {
				distance := position - last

				if distance < minDistance {
					minDistance = distance
				}
			}

			last = position
		}

		prev = curr

		curr = curr.Next

		position++
	}

	if first == -1 || first == last {
		return []int{-1, -1}
	}

	maxDistance := last - first

	return []int{minDistance, maxDistance}
}