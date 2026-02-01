class HitCounter {
private:
    
    int total;
    queue<pair<int, int> > hits;
    
public:
    
    /** Initialize your data structure here. */
    HitCounter() {
        this->total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (this->hits.empty() || this->hits.back().first != timestamp) {
            // Insert the new timestamp with count = 1
            this->hits.push({timestamp, 1});
        } else {
            // Update the count of latest timestamp by incrementing the count by 1
            this->hits.back().second++;
        }
        this->total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!this->hits.empty()) {
            int diff = timestamp - this->hits.front().first;
            if (diff >= 300) {
                // Decrement total by the count of the oldest timestamp
                this->total -= this->hits.front().second;
                this->hits.pop();
            }
            else break;
        }
        return this->total;
    }
};