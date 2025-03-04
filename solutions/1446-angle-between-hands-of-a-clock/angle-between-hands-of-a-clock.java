class Solution {
    public double angleClock(int hour, int minutes) {
        double degree1 = minutes*6; //degreePerMinute = 6
        if (hour == 12) hour = 0;
        double degree2 = minutes/2.d + hour*30; //degreePerHour = 30;

        if (degree1 > degree2) {
            return angle(degree1,degree2);
        }
        return angle(degree2,degree1);
    }

    private double angle(double degree1, double degree2){
        degree1 -= degree2;
        degree2 = 0;
        if (degree1 < 180) {
            return degree1;
        } else {
            return 360 - degree1;
        }
    }
}