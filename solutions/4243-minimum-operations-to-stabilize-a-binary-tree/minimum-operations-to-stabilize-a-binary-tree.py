from heapq import heappush, heapreplace


class Solution:
    def stabilizeBinaryTree(self, root: TreeNode | None) -> int:
        if root is None:
            return 0

        stack = [(root, False)]
        results = []

        while stack:
            node, visited = stack.pop()

            if not visited:
                stack.append((node, True))
                if node.right is not None:
                    stack.append((node.right, False))
                if node.left is not None:
                    stack.append((node.left, False))
                continue

            right = results.pop() if node.right is not None else None
            left = results.pop() if node.left is not None else None

            if left is None:
                left, right = right, None

            if left is None:
                lower, upper = [], []
                lower_offset = upper_offset = cost = 0
            else:
                if right is not None and len(left[0]) < len(right[0]):
                    left, right = right, left

                lower, upper, lower_offset, upper_offset, cost = left

                # Allow a child's value to differ from its parent's by one.
                lower_offset -= 1
                upper_offset += 1

                if right is not None:
                    other_lower, other_upper, other_lo, other_hi, other_cost = right
                    other_lo -= 1
                    other_hi += 1
                    cost += other_cost

                    for entry in other_lower:
                        value = other_lo - entry
                        if upper and upper[0] + upper_offset < value:
                            boundary = upper[0] + upper_offset
                            cost += value - boundary
                            heapreplace(upper, value - upper_offset)
                            heappush(lower, lower_offset - boundary)
                        else:
                            heappush(lower, lower_offset - value)

                    for entry in other_upper:
                        value = entry + other_hi
                        if lower and lower_offset - lower[0] > value:
                            boundary = lower_offset - lower[0]
                            cost += boundary - value
                            heapreplace(lower, lower_offset - value)
                            heappush(upper, boundary - upper_offset)
                        else:
                            heappush(upper, value - upper_offset)

            value = node.val

            # Add the two hinges forming abs(x - value).
            if upper and upper[0] + upper_offset < value:
                boundary = upper[0] + upper_offset
                cost += value - boundary
                heapreplace(upper, value - upper_offset)
                heappush(lower, lower_offset - boundary)
            else:
                heappush(lower, lower_offset - value)

            if lower_offset - lower[0] > value:
                boundary = lower_offset - lower[0]
                cost += boundary - value
                heapreplace(lower, lower_offset - value)
                heappush(upper, boundary - upper_offset)
            else:
                heappush(upper, value - upper_offset)

            results.append((lower, upper, lower_offset, upper_offset, cost))

        return results[0][4]