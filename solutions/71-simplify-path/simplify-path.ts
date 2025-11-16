function simplifyPath(path: string): string {
    // Initialize a stack
    let stack: string[] = [];
    // Split the input string on "/" as the delimiter
    // and process each portion one by one
    for (let portion of path.split("/")) {
        // If the current component is a "..", then
        // we pop an entry from the stack if it's non-empty
        if (portion === "..") {
            if (stack.length) {
                stack.pop();
            }
        } else if (portion === "." || !portion) {
            // A no-op for a "." or an empty string
            continue;
        } else {
            // Finally, a legitimate directory name, so we add it
            // to our stack
            stack.push(portion);
        }
    }
    // Stich together all the directory names together
    return "/" + stack.join("/");
}