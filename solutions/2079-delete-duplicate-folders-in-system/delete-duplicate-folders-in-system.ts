function deleteDuplicateFolder(paths: string[][]): string[][] {
    class Trie {
        serial: string = ""; // current node structure's serialized representation
        children: Map<string, Trie> = new Map(); // current node's child nodes
    }

    const root = new Trie(); // root node

    // build a trie tree
    for (const path of paths) {
        let cur = root;
        for (const node of path) {
            if (!cur.children.has(node)) {
                cur.children.set(node, new Trie());
            }
            cur = cur.children.get(node)!;
        }
    }

    const freq = new Map<string, number>(); // hash table records the occurrence times of each serialized representation
    // post-order traversal based on depth-first search, calculate the serialized representation of each node structure
    function construct(node: Trie) {
        if (node.children.size === 0) return; // if it is a leaf node, no operation is needed.

        const v: string[] = [];
        for (const [folder, child] of node.children) {
            construct(child);
            v.push(`${folder}(${child.serial})`);
        }

        v.sort();
        node.serial = v.join("");
        freq.set(node.serial, (freq.get(node.serial) || 0) + 1);
    }
    construct(root);
    const ans: string[][] = [];
    const path: string[] = [];

    // operate the trie, delete duplicate folders
    function operate(node: Trie) {
        if ((freq.get(node.serial) || 0) > 1) return; // if the serialization representation appears more than once, it needs to be deleted

        if (path.length > 0) {
            ans.push([...path]);
        }

        for (const [folder, child] of node.children) {
            path.push(folder);
            operate(child);
            path.pop();
        }
    }
    operate(root);
    return ans;
}