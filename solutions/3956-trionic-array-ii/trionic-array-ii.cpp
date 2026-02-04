class Solution {
private:
    void reset(long long &n1){
        n1 = LLONG_MIN;
    }
    void reset(long long &n1,long long &n2,long long &n3){
        reset(n1);
        reset(n2);
        reset(n3);
    }

public:
    long long maxSumTrionic(vector<int>& nums) {

        // initialization
        int n = nums.size();
        vector<long long> sumEndingAt(n); // carries max continous sum endoing at index i (either increasing or decreasing)
        sumEndingAt[0] =  nums[0];
        int state=0; // 0 -> neutal, 1 -> increasing, -1 -> decreaing

        long long lastMaxPosSum = LLONG_MIN; // LLLONG_MIN means not set yet
        long long lastNegSum = LLONG_MIN; // LLLONG_MIN means not set yet
        long long curContPosSum = LLONG_MIN; // LLLONG_MIN means not set yet

        long long maxTripleSum = LLONG_MIN; // LLLONG_MIN means not set yet


        // loop through all array entries (1...n-1)
        // calculate sumEndingAt[i]
        // update lastMaxPosSum, lastNegSum, curContPosSum
        

        for(int i=1;i<n;i++){
            if(state==0){
                if(nums[i]<=nums[i-1]){
                    sumEndingAt[i]=nums[i];
                }
                else{
                    sumEndingAt[i]=(long long)nums[i] + (long long)nums[i-1];
                    state = 1;
                    curContPosSum = sumEndingAt[i];
                }
            }
            else if(state==1){
                if(nums[i]==nums[i-1]){
                    reset(lastMaxPosSum,lastNegSum,curContPosSum);
                    sumEndingAt[i]=nums[i];
                    state = 0;
                }
                else if(nums[i]<nums[i-1]){
                    lastMaxPosSum = sumEndingAt[i-1];
                    lastNegSum = nums[i];
                    reset(curContPosSum);
                    sumEndingAt[i]=nums[i];
                    state = -1;
                }
                else{
                    sumEndingAt[i]= (long long)nums[i]+ max((long long)nums[i-1],sumEndingAt[i-1]);
                    curContPosSum += nums[i];

                    if(lastMaxPosSum!=LLONG_MIN){
                        // we have trionic array found ending at i
                        long long curTripleSum = lastMaxPosSum + lastNegSum + curContPosSum;
                        if( curTripleSum > maxTripleSum) maxTripleSum = curTripleSum;

                    }
                }
            }
            else{
                if(nums[i]==nums[i-1]){
                    reset(curContPosSum);
                    sumEndingAt[i]=nums[i];
                    state = 0;
                }
                else if(nums[i] < nums[i-1]){
                    sumEndingAt[i] = sumEndingAt[i-1]+(long long)nums[i];
                    lastNegSum = sumEndingAt[i] ;
                }
                else{
                    sumEndingAt[i]=(long long)nums[i]+(long long)nums[i-1];
                    curContPosSum = nums[i];

                    long long curTripleSum = lastMaxPosSum + lastNegSum + curContPosSum;
                    if( curTripleSum > maxTripleSum) maxTripleSum = curTripleSum;
                    state = 1;
                }

            }
        }

        return maxTripleSum;
    }
};