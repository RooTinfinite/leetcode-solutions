/**
 * @param {string[]} folder
 * @return {string[]}
 */
const removeSubfolders = function(folder) {
    // Sort the folders lexicographically so parent folders come before their subfolders
    folder.sort();
    
    // Initialize result array with the first folder
    const ans = [folder[0]];
    
    // Iterate through remaining folders starting from index 1
    for (let i = 1; i < folder.length; i++) {
        // Get the last added folder path and add a trailing slash
        const lastFolder = ans[ans.length - 1] + '/';
        
        // Check if current folder starts with lastFolder
        // If it doesn't start with lastFolder, then it's not a subfolder
        if (!folder[i].startsWith(lastFolder)) {
            ans.push(folder[i]);
        }
    }
    
    return ans;
};