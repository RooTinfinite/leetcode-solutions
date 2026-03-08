class LogSystem {
  constructor() {
    this.logs = [];
    this.indices = {
      Year: 4,
      Month: 7,
      Day: 10,
      Hour: 13,
      Minute: 16,
      Second: 19,
    };
  }

  put(id, timestamp) {
    this.logs.push({ id, timestamp });
  }

  retrieve(start, end, granularity) {
    const endIndex = this.indices[granularity];
    const startVal = start.slice(0, endIndex);
    const endVal = end.slice(0, endIndex);

    return this.logs
      .filter((log) => {
        const currVal = log.timestamp.slice(0, endIndex);
        return currVal >= startVal && currVal <= endVal;
      })
      .map((log) => log.id);
  }
}