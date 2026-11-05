class BusBooking:
    def __init__(self, n: int):
        self.bookings = {}  # seat -> cost at the moment it was booked
        self.total = 0

    def toggle(self, seat: str) -> None:
        if seat in self.bookings:
            self.total -= self.bookings.pop(seat)  # free it: only its own cost leaves
            return
        middle = {"A": "B", "D": "C"}.get(seat[0], "") + seat[1:]  # window -> its middle seat; for B/C this is just the row, never a key
        self.bookings[seat] = 3 if middle in self.bookings else 1
        self.total += self.bookings[seat]

    def getTotalTime(self) -> int:
        return self.total

    def getMinTime(self) -> int:
        return len(self.bookings)  # windows first, then middles: every seat costs 1