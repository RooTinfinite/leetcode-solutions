// Added using AI
var survivedRobotsHealths = function(positions, healths, directions) {
    const n = positions.length;
    const order = Array.from({length: n}, (_, i) => i);
    order.sort((a, b) => positions[a] - positions[b]);

    const dead = new Array(n).fill(false);
    const st = [];

    for (const i of order) {
        if (directions[i] === 'R') {
            st.push(i);
        } else {
            while (st.length && directions[st[st.length-1]] === 'R') {
                const top = st[st.length-1];
                if (healths[top] > healths[i]) {
                    healths[top]--; dead[i] = true; break;
                } else if (healths[top] < healths[i]) {
                    healths[i]--; dead[top] = true; st.pop();
                } else {
                    dead[i] = dead[top] = true; st.pop(); break;
                }
            }
            if (!dead[i]) st.push(i);
        }
    }

    return healths.filter((_, i) => !dead[i]);
};