def remove_subfolders(folder)
    # Sort the folders lexicographically so parent folders come before their subfolders
    folder.sort!
    
    # Initialize result array with the first folder
    ans = [folder[0]]
    
    # Iterate through remaining folders starting from index 1
    (1...folder.length).each do |i|
        # Get the last added folder path and add a trailing slash
        last_folder = ans[-1] + "/"
        
        # Check if current folder starts with last_folder
        # If it doesn't start with last_folder, then it's not a subfolder
        if !folder[i].start_with?(last_folder)
            ans << folder[i]
        end
    end
    
    ans
end