class Solution {
public:
    // Function to handle AND operation
    bool andd(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            // If we're not inside parentheses and encounter a comma
            if(active == 0 && exp[j]==','){
                // Evaluate the sub-expression, return false if it's false
                if(!parseBoolExpr(subexp)) return false;
                subexp = ""; // Reset sub-expression
                j++;
                continue;
            }
            // Keep track of nested parentheses
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++]; // Build sub-expression
        }
        // Evaluate the last sub-expression
        if(!parseBoolExpr(subexp)) return false;
        // If all sub-expressions are true, return true
        return true;
    }

    // Function to handle OR operation
    bool orr(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            // If we're not inside parentheses and encounter a comma
            if(active==0 && exp[j]==','){
                // Evaluate the sub-expression, return true if it's true
                if(parseBoolExpr(subexp)) return true;
                subexp = ""; // Reset sub-expression
                j++;
                continue;
            }
            // Keep track of nested parentheses
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++]; // Build sub-expression
        }
        // Evaluate the last sub-expression
        if(parseBoolExpr(subexp)) return true;
        // If all sub-expressions are false, return false
        return false;
    }

    // Main function to parse boolean expressions
    bool parseBoolExpr(string exp) {
        int n = exp.length();
        // Base case: single character 't' or 'f'
        if(n==1) return (exp[0]=='t');
        // Handle NOT operation
        if(exp[0] == '!') return !parseBoolExpr(exp.substr(2, n-3));
        // Handle AND operation
        if(exp[0] == '&') return andd(exp.substr(2, n-3));
        // Handle OR operation
        if(exp[0] == '|') return orr(exp.substr(2, n-3));
        // Default case (should not reach here if input is valid)
        return false;
    }
};