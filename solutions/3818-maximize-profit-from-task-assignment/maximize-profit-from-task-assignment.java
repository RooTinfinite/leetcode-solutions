import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Solution {

    public long maxProfit(int[] workers, int[][] tasks) {
        Map<Integer, PriorityQueue<Integer>> skillToProfits = createMapSkillToProfits(tasks);
        return calculateMaxProfit(workers, skillToProfits);
    }

    private long calculateMaxProfit(int[] workers, Map<Integer, PriorityQueue<Integer>> skillToProfits) {
        long maxProfit = 0;
        for (int skill : workers) {
            if (!skillToProfits.containsKey(skill)) {
                continue;
            }
            maxProfit += skillToProfits.get(skill).poll();
            if (skillToProfits.get(skill).isEmpty()) {
                skillToProfits.remove(skill);
            }
        }

        int maxUnusedProfit = 0;
        for (int skill : skillToProfits.keySet()) {
            maxUnusedProfit = Math.max(maxUnusedProfit, skillToProfits.get(skill).poll());
        }

        maxProfit += maxUnusedProfit;
        return maxProfit;
    }

    private Map<Integer, PriorityQueue<Integer>> createMapSkillToProfits(int[][] tasks) {
        Map<Integer, PriorityQueue<Integer>> skillToProfits = new HashMap<>();
        for (int[] task : tasks) {
            int skill = task[0];
            int profit = task[1];

            skillToProfits.putIfAbsent(skill, new PriorityQueue<>((xProfit, yProfit) -> yProfit - xProfit));
            skillToProfits.get(skill).add(profit);
        }

        return skillToProfits;
    }
}