class Solution {

    // Function to return a list representing the path from the root node
    // to the current node.
    private List<String> fetchPathForRegion(
        String currNode,
        Map<String, String> childParentMap
    ) {
        List<String> path = new ArrayList<>();
        // Start by adding the current node to the path.
        path.add(currNode);

        // Traverse upwards through the tree by finding the parent of the
        // current node. Continue until the root node is reached.
        while (childParentMap.containsKey(currNode)) {
            String parentNode = childParentMap.get(currNode);
            path.add(parentNode);
            currNode = parentNode;
        }
        // Reverse the path so that it starts from the root and
        // ends at the given current node.
        Collections.reverse(path);
        return path;
    }

    public String findSmallestRegion(
        List<List<String>> regions,
        String region1,
        String region2
    ) {
        // Map to store (child -> parent) relationships for each region.
        Map<String, String> childParentMap = new HashMap<>();

        // Populate the 'childParentMap' using the provided 'regions' list.
        for (List<String> regionArray : regions) {
            String parentNode = regionArray.get(0);
            for (int i = 1; i < regionArray.size(); i++) {
                childParentMap.put(regionArray.get(i), parentNode);
            }
        }

        // Store the paths from the root node to 'region1' and 'region2'
        // nodes in their respective lists.
        List<String> path1 = fetchPathForRegion(region1, childParentMap);
        List<String> path2 = fetchPathForRegion(region2, childParentMap);

        int i = 0, j = 0;
        String lowestCommonAncestor = "";
        // Traverse both paths simultaneously until the paths diverge.
        // The last common node is the lowest common ancestor.
        while (
            i < path1.size() &&
            j < path2.size() &&
            path1.get(i).equals(path2.get(j))
        ) {
            lowestCommonAncestor = path1.get(i);
            i++;
            j++;
        }

        // Return the lowest common ancestor of 'region1' and 'region2'.
        return lowestCommonAncestor;
    }
}