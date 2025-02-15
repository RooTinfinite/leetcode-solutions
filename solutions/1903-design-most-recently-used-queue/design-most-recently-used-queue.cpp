class MRUQueue {
private:
    vector<int> queue;

public:
    MRUQueue(int n) {
        // Initialize the queue with numbers from 1 to n
        for (int number = 1; number <= n; ++number) {
            queue.push_back(number);
        }
    }

    int fetch(int k) {
        // Get the k-th element (1-indexed)
        int value = queue[k - 1];
        // Remove the element from its current position in the queue
        queue.erase(queue.begin() + k - 1);
        // Append the element to the end of the queue
        queue.push_back(value);
        return value;
    }
};