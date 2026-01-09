var subtreeWithAllDeepest = function(root) {
    if (!root) return null;

    const parent = new Map();
    const queue = [];
    queue.push(root);
    parent.set(root, null);

    let lastLevel = [];

    // BFS traversal
    while (queue.length > 0) {
        const size = queue.length;
        lastLevel = [];

        for (let i = 0; i < size; i++) {
            const node = queue.shift();
            lastLevel.push(node);

            if (node.left) {
                parent.set(node.left, node);
                queue.push(node.left);
            }
            if (node.right) {
                parent.set(node.right, node);
                queue.push(node.right);
            }
        }
    }

    let deepest = new Set(lastLevel);

    // Move upward until only one node remains
    while (deepest.size > 1) {
        const next = new Set();
        for (const node of deepest) {
            next.add(parent.get(node));
        }
        deepest = next;
    }

    return deepest.values().next().value;
};