class Solution {
    func removeSubfolders(_ folder: [String]) -> [String] {
        // Sort the folders lexicographically so parent folders come before their subfolders
        let sortedFolders = folder.sorted()
        
        // Initialize result array with the first folder
        var ans = [sortedFolders[0]]
        
        // Iterate through remaining folders starting from index 1
        for i in 1..<sortedFolders.count {
            // Get the last added folder path and add a trailing slash
            let lastFolder = ans.last! + "/"
            
            // Check if current folder starts with lastFolder
            // If it doesn't start with lastFolder, then it's not a subfolder
            if !sortedFolders[i].hasPrefix(lastFolder) {
                ans.append(sortedFolders[i])
            }
        }
        
        return ans
    }
}