  // JavaScript

function maxUniqueSplit(s) {
  // Initialize the result to 1 (minimum possible split)
  let res = 1;
  // Create a Set to store unique substrings
  let strings = new Set();

  // Define a recursive search function
  function search(s) {
    // If the current string is not in the Set
    if (!strings.has(s)) {
      // Add it to the Set
      strings.add(s);
      // Update the result with the maximum of current result and Set size
      res = Math.max(res, strings.size);
      // Remove the string from the Set (backtracking)
      strings.delete(s);
    }

    // Iterate through all possible split positions
    for (let i = 1; i < s.length; i++) {
      // Get the substring from start to current position
      const sub = s.substring(0, i);
      // If this substring is already in the Set, skip this iteration
      if (strings.has(sub)) continue;
      // Add the substring to the Set
      strings.add(sub);
      // Recursively search the remaining part of the string
      search(s.substring(i));
      // Remove the substring from the Set (backtracking)
      strings.delete(sub);
    }
  }

  // Start the search with the entire input string
  search(s);
  // Return the maximum number of unique substrings found
  return res;
}