class Solution {
    public int maxStudentsOnBench(int[][] students) {
        Map<Integer, Set<Integer>> map = new HashMap<>();

        for (int[] student : students) {
            int bench_id = student[1];
            int student_id = student[0];
            map.putIfAbsent(bench_id, new HashSet<>());
            map.get(bench_id).add(student_id);
        }
        int max_bench_id = 0;
        for (Set<Integer> max : map.values()) {
            max_bench_id = Math.max(max_bench_id, max.size());
        }
        return max_bench_id;
    }
}