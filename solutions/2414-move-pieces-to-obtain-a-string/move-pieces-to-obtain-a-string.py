class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Queue to store characters and indices from both strings
        start_queue = []
        target_queue = []

        # Record non-underscore characters and their indices
        for i in range(len(start)):
            if start[i] != "_":
                start_queue.append((start[i], i))
            if target[i] != "_":
                target_queue.append((target[i], i))

        # If number of pieces don't match, return false
        if len(start_queue) != len(target_queue):
            return False

        # Compare each piece's type and position
        while not len(start_queue) == 0:
            start_char, start_index = start_queue.pop(0)
            target_char, target_index = target_queue.pop(0)

            # Check character match and movement rules
            if (
                start_char != target_char
                or (start_char == "L" and start_index < target_index)
                or (start_char == "R" and start_index > target_index)
            ):
                return False

        return True