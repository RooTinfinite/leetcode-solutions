import java.util.*;

class EventManager {

    private PriorityQueue<int[]> pq;
    private Map<Integer, Integer> active;

    public EventManager(int[][] events) {
        pq = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0])
                return b[0] - a[0];      // Higher priority first
            return a[1] - b[1];          // Smaller eventId first
        });

        active = new HashMap<>();

        for (int[] e : events) {
            int eventId = e[0];
            int priority = e[1];

            pq.offer(new int[]{priority, eventId});
            active.put(eventId, priority);
        }
    }

    public void updatePriority(int eventId, int newPriority) {
        active.put(eventId, newPriority);
        pq.offer(new int[]{newPriority, eventId});
    }

    public int pollHighest() {
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int priority = top[0];
            int eventId = top[1];

            if (active.containsKey(eventId) && active.get(eventId) == priority) {
                active.remove(eventId);
                return eventId;
            }
        }

        return -1;
    }
}