class Solution:
    def scoreValidator(self, events: list[str]) -> list[int]:
        counter = 0
        total = 0

        for event in events:
            if event in {"0", "1", "2", "3", "4", "6"}:
                total += int(event)
            elif event == "W":
                counter += 1
                if counter == 10:
                    break
            elif event == "WD":
                total += 1
            elif event == "NB":
                total += 1
        
        return [total, counter]