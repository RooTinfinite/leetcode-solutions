var minimumAbsDifference = function(arr) {
    // Sort the original array
    arr.sort((x, y) => x - y);
    let answer = [];

    // Initialize minimum difference as a huge integer in order not 
    // to miss the absolute difference of the first pair. 
    let minPairDiff = Infinity;

    // Traverse the sorted array and calcalute the minimum absolute difference.
    for (let i = 0; i < arr.length - 1; ++i) {
        minPairDiff = Math.min(minPairDiff, arr[i + 1] - arr[i]);
    }

    // Traverse the sorted array and check every pair again, if 
    // the absolute difference equals the minimum difference, 
    // add this pair to the answer list.
    for (let i = 0; i < arr.length - 1; ++i) {
        if (arr[i + 1] - arr[i] == minPairDiff) {
            answer.push([arr[i], arr[i + 1]]);
        }
    }

    return answer;
};