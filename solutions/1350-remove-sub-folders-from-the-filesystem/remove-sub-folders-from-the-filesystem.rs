impl Solution {
    pub fn remove_subfolders(folder: Vec<String>) -> Vec<String> {
        // Create a mutable copy of the input vector for sorting
        let mut folders = folder;
        folders.sort();
        
        // Initialize result vector with the first folder
        let mut ans = vec![folders[0].clone()];
        
        // Iterate through remaining folders starting from index 1
        for i in 1..folders.len() {
            // Get the last added folder path and add a trailing slash
            let last_folder = ans.last().unwrap().clone() + "/";
            
            // Check if current folder starts with last_folder
            // If it doesn't start with last_folder, then it's not a subfolder
            if !folders[i].starts_with(&last_folder) {
                ans.push(folders[i].clone());
            }
        }
        
        ans
    }
}