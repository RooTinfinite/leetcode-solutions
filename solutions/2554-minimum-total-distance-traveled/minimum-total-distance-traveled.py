class Solution:
    def minimumTotalDistance(
        self, robots: List[int], factories: List[List[int]]
    ) -> int:
        # Sort robots and factories by position
        robots.sort()
        factories.sort()

        # Flatten factory positions according to their capacities
        factory_positions = []
        for factory in factories:
            for i in range(factory[1]):
                factory_positions.append(factory[0])

        robot_count = len(robots)
        factory_count = len(factory_positions)
        next_dist = [0 for _ in range(factory_count + 1)]
        current = [0 for _ in range(factory_count + 1)]

        current[factory_count] = 1e12

        # Fill DP table using two rows for optimization
        for i in range(robot_count - 1, -1, -1):
            for j in range(factory_count - 1, -1, -1):
                # Assign current robot to current factory
                assign = (
                    abs(robots[i] - factory_positions[j]) + next_dist[j + 1]
                )

                # Skip current factory for this robot
                skip = current[j + 1]
                # Take the minimum option
                current[j] = min(assign, skip)

            # Move to next robot
            next_dist = current[:]

        # Return minimum distance starting from the first robot
        return current[0]