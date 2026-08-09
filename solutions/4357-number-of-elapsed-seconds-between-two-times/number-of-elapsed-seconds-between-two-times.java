class Solution {
    public int secondsBetweenTimes(String startTime, String endTime) {
        return seconds(endTime.split(":")) - seconds(startTime.split(":"));
    }

    private int seconds(String[] str) {
        int cnt = 0;
        cnt += Integer.parseInt(str[0]) * 60 * 60;
        cnt += Integer.parseInt(str[1]) * 60;
        cnt += Integer.parseInt(str[2]);
        return cnt;
    }
}