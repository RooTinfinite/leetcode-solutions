class Solution {

    String expression;
    int idx;

    public List<String> braceExpansionII(String expression) {
        this.expression = expression;
        this.idx = 0;
        Set<String> ret = expr();
        return new ArrayList<String>(ret);
    }

    // item -> letter | { expr }
    private Set<String> item() {
        Set<String> ret = new TreeSet<String>();
        if (expression.charAt(idx) == '{') {
            idx++;
            ret = expr();
        } else {
            StringBuilder sb = new StringBuilder();
            sb.append(expression.charAt(idx));
            ret.add(sb.toString());
        }
        idx++;
        return ret;
    }

    // term -> item | item term
    private Set<String> term() {
        // Initialize an empty set and take its Cartesian product with subsequent results
        Set<String> ret = new TreeSet<String>() {
            {
                add("");
            }
        };
        // An item starts with { or a lowercase letter; continue matching only when this condition is met
        while (
            idx < expression.length() &&
            (expression.charAt(idx) == '{' ||
                Character.isLetter(expression.charAt(idx)))
        ) {
            Set<String> sub = item();
            Set<String> tmp = new TreeSet<String>();
            for (String left : ret) {
                for (String right : sub) {
                    tmp.add(left + right);
                }
            }
            ret = tmp;
        }
        return ret;
    }

    // expr -> term | term, expr
    private Set<String> expr() {
        Set<String> ret = new TreeSet<String>();
        while (true) {
            // Take the union with the result of term()
            ret.addAll(term());
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < expression.length() && expression.charAt(idx) == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return ret;
    }
}