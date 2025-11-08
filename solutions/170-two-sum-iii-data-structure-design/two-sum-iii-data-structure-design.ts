class TwoSum {
    num_counts: { [key: number]: number };

    constructor() {
        this.num_counts = {};
    }

    add(number: number): void {
        if (number in this.num_counts) this.num_counts[number]++;
        else this.num_counts[number] = 1;
    }

    find(value: number): boolean {
        for (let num in this.num_counts) {
            const complement = value - Number(num);
            if (complement != Number(num)) {
                if (complement in this.num_counts) return true;
            } else {
                if (this.num_counts[Number(num)] > 1) return true;
            }
        }
        return false;
    }
}