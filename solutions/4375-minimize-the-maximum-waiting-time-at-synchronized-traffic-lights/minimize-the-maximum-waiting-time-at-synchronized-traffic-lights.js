var minPenalty = function(period, lights, arrivalTime) {
    let maxLight = -Infinity;
    let maxAns = -Infinity;

    for (const light of lights) {
        maxLight = Math.max(maxLight, light);
    }

    for (const at of arrivalTime) {
        const currentTime = at % period;

        if (currentTime >= maxLight) {
            maxAns = Math.max(
                maxAns,
                period - currentTime
            );
        }
    }

    return maxAns === -Infinity ? 0 : maxAns;
};