function minimumEffort(tasks) {
    tasks.sort((a, b) => b[1] - b[0] - (a[1] - a[0]));
    let ans = 0;
    let remain = 0;
    for (const task of tasks) {
        if (remain <= task[1]) {
            ans += task[1] - remain;
        }
        remain = Math.max(task[1] - task[0], remain - task[0]);
    }
    return ans;
}