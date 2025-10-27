type State = {
    q0: number;
    q1: number;
    q2: number;
    qd: number;
};

class StateMachine {
    // Store current state value.
    private currentState: number;
    // Store result formed and it's sign.
    private result: number;
    private sign: number;

    readonly State: State;
    private readonly INT_MAX: number;
    private readonly INT_MIN: number;

    constructor() {
        this.State = { q0: 1, q1: 2, q2: 3, qd: 4 };
        this.INT_MAX = Math.pow(2, 31) - 1;
        this.INT_MIN = -Math.pow(2, 31);

        this.currentState = this.State.q0;
        this.result = 0;
        this.sign = 1;
    }

    // Transition to state q1.
    private toStateQ1(ch: string): void {
        this.sign = ch === "-" ? -1 : 1;
        this.currentState = this.State.q1;
    }

    // Transition to state q2.
    private toStateQ2(digit: number): void {
        this.currentState = this.State.q2;
        this.appendDigit(digit);
    }

    // Transition to dead state qd.
    private toStateQd(): void {
        this.currentState = this.State.qd;
    }

    // Append digit to result, if out of range return clamped value.
    private appendDigit(digit: number): void {
        if (
            this.result > Math.floor(this.INT_MAX / 10) ||
            (this.result === Math.floor(this.INT_MAX / 10) &&
                digit > this.INT_MAX % 10)
        ) {
            if (this.sign === 1) {
                // If sign is 1, clamp result to INT_MAX.
                this.result = this.INT_MAX;
            } else {
                // If sign is -1, clamp result to INT_MIN.
                this.result = this.INT_MIN;
                this.sign = 1;
            }

            // When the 32-bit int range is exceeded, a dead state is reached.
            this.toStateQd();
        } else {
            // Append current digit to the result.
            this.result = this.result * 10 + digit;
        }
    }

    // Change state based on current input character.
    public transition(ch: string): void {
        if (this.currentState === this.State.q0) {
            // Beginning state of the string (or some whitespaces are skipped).
            if (ch === " ") {
                // Current character is a whitespace.
                // We stay in the same state.
                return;
            } else if (ch === "-" || ch === "+") {
                // Current character is a sign.
                this.toStateQ1(ch);
            } else if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(parseInt(ch));
            } else {
                // Current character is not a space/sign/digit.
                // Reached a dead state.
                this.toStateQd();
            }
        } else if (
            this.currentState === this.State.q1 ||
            this.currentState === this.State.q2
        ) {
            // Previous character was a sign or digit.
            if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(parseInt(ch));
            } else {
                // Current character is not a digit.
                // Reached a dead state.
                this.toStateQd();
            }
        }
    }

    // Return the final result formed with its sign.
    public getInteger(): number {
        return this.sign * this.result;
    }

    // Get current state.
    public getState(): number {
        return this.currentState;
    }
}

function myAtoi(s: string): number {
    let Q = new StateMachine();

    for (let i = 0; i < s.length && Q.getState() !== Q.State.qd; ++i) {
        Q.transition(s[i]);
    }

    return Q.getInteger();
}