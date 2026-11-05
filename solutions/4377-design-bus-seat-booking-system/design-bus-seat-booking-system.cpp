class BusBooking {
    unordered_map<string, int> bookings;  // seat -> cost at the moment it was booked
    int total = 0;

public:
    BusBooking(int n) {}

    void toggle(string seat) {
        if (auto it = bookings.find(seat); it != bookings.end()) {
            total -= it->second;  // free it: only its own cost leaves
            bookings.erase(it);
            return;
        }
        string middle = (seat[0] == 'A' ? "B" : seat[0] == 'D' ? "C" : "") + seat.substr(1);  // window -> its middle seat; for B/C just the row, never a key
        bookings[seat] = bookings.contains(middle) ? 3 : 1;
        total += bookings[seat];
    }

    int getTotalTime() { return total; }

    int getMinTime() { return bookings.size(); }  // windows first, then middles: every seat costs 1
};