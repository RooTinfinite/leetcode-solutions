int elevatorRequests(int n, int* requests, int requestsSize) {
    int total = 0;
    int curr = 0;
    
    for (int i = 0; i < requestsSize; i++) {
        total += abs(curr - requests[i]);
        curr = requests[i];
    }
    
    return total;
}