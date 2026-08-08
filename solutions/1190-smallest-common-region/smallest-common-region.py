class Solution:
    # Function to return a list representing the path from the root node
    # to the current node.
    def fetch_path_for_region(self, curr_node, child_parent_map):
        path = []
        # Start by adding the current node to the path.
        path.append(curr_node)

        # Traverse upwards through the tree by finding the parent of the
        # current node. Continue until the root node is reached.
        while curr_node in child_parent_map:
            parent_node = child_parent_map[curr_node]
            path.append(parent_node)
            curr_node = parent_node

        # Reverse the path so that it starts from the root and
        # ends at the given current node.
        path.reverse()
        return path

    def findSmallestRegion(
        self, regions: List[List[str]], region1: str, region2: str
    ) -> str:
        # Dictionary to store (child -> parent) relationships for each region.
        child_parent_map = {}

        # Populate the 'child_parent_map' using the provided 'regions' list.
        for region_array in regions:
            parent_node = region_array[0]
            for i in range(1, len(region_array)):
                child_parent_map[region_array[i]] = parent_node

        # Store the paths from the root node to 'region1' and 'region2'
        # nodes in their respective lists.
        path1 = self.fetch_path_for_region(region1, child_parent_map)
        path2 = self.fetch_path_for_region(region2, child_parent_map)

        i, j = 0, 0
        lowest_common_ancestor = ""
        # Traverse both paths simultaneously until the paths diverge.
        # The last common node is the lowest common ancestor.
        while i < len(path1) and j < len(path2) and path1[i] == path2[j]:
            lowest_common_ancestor = path1[i]
            i += 1
            j += 1

        # Return the lowest common ancestor of 'region1' and 'region2'.
        return lowest_common_ancestor