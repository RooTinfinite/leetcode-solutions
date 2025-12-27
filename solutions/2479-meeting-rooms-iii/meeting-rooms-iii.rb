def most_booked(n, meetings)
    room_availability_time = Array.new(n, 0)
    meeting_count = Array.new(n, 0)

    meetings.sort_by! { |start, _| start }

    meetings.each do |start, end_time|
      min_room_availability_time = Float::INFINITY
      min_available_time_room = 0
      found_unused_room = false

      (0...n).each do |i|
        if room_availability_time[i] <= start
          found_unused_room = true
          meeting_count[i] += 1
          room_availability_time[i] = end_time
          break
        end

        if min_room_availability_time > room_availability_time[i]
          min_room_availability_time = room_availability_time[i]
          min_available_time_room = i
        end
      end

      unless found_unused_room
        room_availability_time[min_available_time_room] += end_time - start
        meeting_count[min_available_time_room] += 1
      end
    end

    meeting_count.index(meeting_count.max)
end