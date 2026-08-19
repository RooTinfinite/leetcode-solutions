class Solution:
    def nearestDrone(self, drones: list[list[int]], target: list[int]) -> int:
        tx, ty = target
        return min(
            (
                (d, i) for i, (x, y, r) in enumerate(drones)
                if (d := abs(x - tx) + abs(y - ty)) <= r
            ),
            default=(0, -1)
        )[1]