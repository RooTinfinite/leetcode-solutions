public class Solution {
    private string expression;
    private int idx;

    // item -> letter | { expr }
    private HashSet<string> Item() {
        HashSet<string> ret = new HashSet<string>();
        if (expression[idx] == '{') {
            idx++;
            ret = Expr();
        } else {
            ret = new HashSet<string> { expression[idx].ToString() };
        }
        idx++;
        return ret;
    }

    // term -> item | item term
    private HashSet<string> Term() {
        // Initialize an empty set and take its Cartesian product with
        // subsequent results
        HashSet<string> ret = new HashSet<string> { "" };
        // An item starts with { or a lowercase letter; continue matching only
        // when this condition is met
        while (idx < expression.Length &&
               (expression[idx] == '{' || char.IsLetter(expression[idx]))) {
            var sub = Item();
            HashSet<string> tmp = new HashSet<string>();
            foreach (var left in ret) {
                foreach (var right in sub) {
                    tmp.Add(left + right);
                }
            }
            ret = tmp;
        }
        return ret;
    }

    // expr -> term | term, expr
    private HashSet<string> Expr() {
        HashSet<string> ret = new HashSet<string>();
        while (true) {
            // Take the union with the result of term()
            ret.UnionWith(Term());
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < expression.Length && expression[idx] == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return ret;
    }

    public IList<string> BraceExpansionII(string expression) {
        this.expression = expression;
        this.idx = 0;
        var ret = Expr();
        var result = new List<string>(ret);
        result.Sort();
        return result;
    }
}