class Solution { // Author:- kaiHiwatari
public:
    string trafficSignal(int timer) {
        if (timer > 30 && timer <= 90) return "Red";
        else if (timer == 30) return "Orange";
        else if (timer == 0) return "Green";
        else return "Invalid";
    }
};