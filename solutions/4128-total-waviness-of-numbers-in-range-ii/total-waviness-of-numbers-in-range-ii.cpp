long long DP[16][16][3][10][2];
int EXACT;
int L;
int D[16];

long long REC(int POS, int LAST_DIGIT, int RELATION_STATUS, int WAVINESS, int FLAG){
    if(POS == L){
        if(FLAG == 0){
            EXACT = WAVINESS;
        }
        return WAVINESS;
    }
    if(DP[POS][WAVINESS][RELATION_STATUS][LAST_DIGIT][FLAG] != -1){
        return DP[POS][WAVINESS][RELATION_STATUS][LAST_DIGIT][FLAG];
    }
    long long sum = 0;
    for(int d = 0; d <= 9; d ++){
        if(d == 0 && POS == 0) continue;
        if(FLAG == 0 && D[POS] < d) continue;

        int NEW_FLAG = FLAG;
        if(D[POS] > d) NEW_FLAG = 1;

        int NEW_WAVINESS = WAVINESS;

        if(RELATION_STATUS == 0 && LAST_DIGIT > d){
            NEW_WAVINESS ++;
        }
        if(RELATION_STATUS == 1 && LAST_DIGIT < d){
            NEW_WAVINESS ++;
        }
        int NEW_RELATION_STATUS = 2;
        if(POS >= 1){
            if(LAST_DIGIT < d) NEW_RELATION_STATUS = 0;
            if(LAST_DIGIT > d) NEW_RELATION_STATUS = 1;
        }
        sum += REC(POS + 1, d, NEW_RELATION_STATUS, NEW_WAVINESS, NEW_FLAG);
    }
    DP[POS][WAVINESS][RELATION_STATUS][LAST_DIGIT][FLAG] = sum;
    return DP[POS][WAVINESS][RELATION_STATUS][LAST_DIGIT][FLAG];
}

void add_to_D(long long x){
    memset(DP, -1, sizeof(DP));
    L = 0;
    while(x > 0){
        D[L ++] = x % 10;
        x /= 10;
    }
    reverse(D, D + L);
}

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long p10 = 100;
        long long cnt[16];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 3; i <= 15; i ++){
            p10 *= 10;
            add_to_D(p10 - 1);
            cnt[i] = REC(0, 0, 2, 0, 0);
        }

        add_to_D(num1);
        long long s1 = REC(0, 0, 2, 0, 0);
        int e1 = EXACT;
        for(int i = 0; i < L; i ++){
            s1 += cnt[i];
        }

        add_to_D(num2);
        long long s2 = REC(0, 0, 2, 0, 0);
        int e2 = EXACT;
        for(int i = 0; i < L; i ++){
            s2 += cnt[i];
        }
        return s2 - s1 + e1;
    }
};