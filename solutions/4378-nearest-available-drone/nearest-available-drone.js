var nearestDrone = function(drones, t) {
    let minDist = Infinity;
    let idx = -1;

    for (let i = 0; i < drones.length; i++) {
        const dist =
            Math.abs(t[0] - drones[i][0]) +
            Math.abs(t[1] - drones[i][1]);

        if (dist <= drones[i][2] && minDist > dist) {
            minDist = dist;
            idx = i;
        }
    }

    return idx;
};