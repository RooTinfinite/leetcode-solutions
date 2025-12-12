function countMentions(numberOfUsers: number, events: string[][]): number[] {
    events.sort((a: string[], b: string[]): number => {
        const timeA: number = parseInt(a[1]);
        const timeB: number = parseInt(b[1]);
        if (timeA !== timeB) {
            return timeA - timeB;
        }
        return (b[0] === "MESSAGE" ? 0 : 1) - (a[0] === "MESSAGE" ? 0 : 1);
    });

    const count: number[] = new Array(numberOfUsers).fill(0);
    const nextOnlineTime: number[] = new Array(numberOfUsers).fill(0);

    for (const event of events) {
        const curTime: number = parseInt(event[1]);
        const type: string = event[0];

        if (type === "MESSAGE") {
            const target: string = event[2];
            if (target === "ALL") {
                for (let i = 0; i < numberOfUsers; i++) {
                    count[i]++;
                }
            } else if (target === "HERE") {
                for (let i = 0; i < numberOfUsers; i++) {
                    if (nextOnlineTime[i] <= curTime) {
                        count[i]++;
                    }
                }
            } else {
                const users: string[] = target.split(" ");
                for (const user of users) {
                    const idx: number = parseInt(user.substring(2));
                    count[idx]++;
                }
            }
        } else {
            const idx: number = parseInt(event[2]);
            nextOnlineTime[idx] = curTime + 60;
        }
    }

    return count;
}