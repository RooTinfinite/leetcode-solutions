var assignTasks = function (servers, tasks) {
    // Busy servers: store [completion time, server index]
    const busy = new MinPriorityQueue({
        compare: (a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            return a[1] - b[1];
        },
    });

    // Idle servers: store [weight, index]
    const idle = new MinPriorityQueue({
        compare: (a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            return a[1] - b[1];
        },
    });

    for (let i = 0; i < servers.length; i++) {
        idle.enqueue([servers[i], i]);
    }
    let currentTime = 0;
    const ans = [];

    // Move servers with t<=ts from priority queue busy to priority queue idle one by one
    const release = () => {
        while (!busy.isEmpty() && busy.front()[0] <= currentTime) {
            const [, idx] = busy.dequeue();
            idle.enqueue([servers[idx], idx]);
        }
    };

    for (let i = 0; i < tasks.length; i++) {
        currentTime = Math.max(currentTime, i);
        release();
        if (idle.isEmpty()) {
            currentTime = busy.front()[0];
            release();
        }

        const [, idx] = idle.dequeue();
        ans.push(idx);
        busy.enqueue([currentTime + tasks[i], idx]);
    }

    return ans;
};