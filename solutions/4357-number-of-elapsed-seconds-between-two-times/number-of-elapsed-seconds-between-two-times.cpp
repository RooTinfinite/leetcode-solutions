#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tos(string s){
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,2));
        int se=stoi(s.substr(6,2));
        return h*3600+m*60+se;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return tos(endTime)-tos(startTime);
    }
};