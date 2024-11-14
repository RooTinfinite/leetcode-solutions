function averageOfLevels(root) {
    if(!root) return [];
    let resAverages = new Array();
    let queue = new Array(); // required for tree traversal
    queue.push(root);

    while(queue.length) {
        const next = []; // keeps track of nodes from each level
        let sum = 0;
        for(const node of queue) {
            sum += node.val;
            if(node.left) next.push(node.left);
            if(node.right) next.push(node.right);
        }
        const avg = sum / queue.length;
        resAverages.push(avg);
        // queue has nodes from the next level
        queue = next;
    }
    return resAverages;
};