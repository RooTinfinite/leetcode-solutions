class ExamTracker {
public:
    vector<int> t;
    vector<long long> x;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        t.push_back(time);
        long long c=(x.empty()?0:x.back())+score;
        x.push_back(c);
    }
    int solve(vector<int> &t, int tar){
        int i=0,j=t.size();
        while(i<j){
            int mid=i+(j-i)/2;
            if(t[mid]<=tar){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i-1;
    }
    
    long long totalScore(int sT, int eT) {
        int r=solve(t,eT);
        int l=solve(t,sT-1);
        if(r<0) return 0;
        return x[r]-(l>=0 ? x[l]:0);
    }
};