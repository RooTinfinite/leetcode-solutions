var braceExpansionII = function (expression) {
    let idx = 0;
    const n = expression.length;

    // Check whether it is a letter
    const isLetter = (c) => {
        return c >= "a" && c <= "z";
    };

    // item -> letter | { expr }
    const item = () => {
        let ret = new Set();
        if (expression[idx] === "{") {
            idx++;
            ret = expr();
        } else {
            ret = new Set([expression[idx]]);
        }
        idx++;
        return ret;
    };

    // term -> item | item term
    const term = () => {
        // Initialize an empty set and take its Cartesian product with subsequent results
        let ret = new Set([""]);
        // An item starts with { or a lowercase letter; continue matching only when this condition is met
        while (
            idx < n &&
            (expression[idx] === "{" || isLetter(expression[idx]))
        ) {
            const sub = item();
            const tmp = new Set();
            for (const left of ret) {
                for (const right of sub) {
                    tmp.add(left + right);
                }
            }
            ret = tmp;
        }
        return ret;
    };

    // expr -> term | term, expr
    const expr = () => {
        const ret = new Set();
        while (true) {
            // Take the union with the result of term()
            for (const item of term()) {
                ret.add(item);
            }
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < n && expression[idx] === ",") {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return ret;
    };

    const result = Array.from(expr());
    return result.sort();
};