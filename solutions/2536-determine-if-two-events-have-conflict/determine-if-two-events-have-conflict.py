class Solution:
    def haveConflict(self, event_1, event_2) -> bool:
        def get_hour_and_minute(hh_mm):
            hour, minute = hh_mm.split(':')
            hour = int(hour)
            minute = int(minute)

            return (hour, minute)
        
        if (get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_1[1]) <= get_hour_and_minute(event_2[1])):
            return True
        elif (get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_1[1]) < get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_2[1])):
            return False
        elif (get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_2[1]) < get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_1[1])):
            return False
        elif (get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_1[1]) <= get_hour_and_minute(event_2[1])):
            return True
        elif (get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_2[1]) <= get_hour_and_minute(event_1[1])):
            return True
        elif (get_hour_and_minute(event_1[0]) <= get_hour_and_minute(event_2[0]) <= get_hour_and_minute(event_2[1]) <= get_hour_and_minute(event_1[1])):
            return True