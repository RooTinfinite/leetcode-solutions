typedef long long int lld;
class Solution {
public:
    const static int MAXB=34;
    const long long FULL = (1LL << 31) - 1;
    vector<lld> B={};
    void buildB(vector<int>& candi, lld& maskedval) {
        B=vector<lld>(MAXB,0ll);
        for (int& v:candi) {
            lld vv=(lld)v & maskedval;
            for (int i=MAXB-1; i>=0; i--) {
                if ((vv>>i)&1) {
                    if (B[i]==0ll) {B[i]=vv; break;}
                    vv^=B[i];
                }
            }
        }
    }
    long long maximizeXorAndXor(vector<int>& nums) {
        int len=nums.size(); int maxmk=(1<<len)-1;
        lld res=0ll; lld tmp; lld maxXOR;
        lld allXOR=0ll; lld allXORInv;
        for (int i=0; i<=maxmk; i++) {
            vector<int> candi={};
            tmp=-1; allXOR=0ll;
            for (int j=0; j<len; j++) {
                if ((1<<j)&i) {
                    if (tmp==-1) {tmp=(lld)nums[j];}
                    else {tmp&=(lld)nums[j];}
                }
                else {
                    candi.push_back(nums[j]);
                    allXOR^=(lld)nums[j];
                }
            }
            if (tmp==-1) tmp=0ll;
            allXORInv=(~allXOR) & FULL;
            maxXOR=0ll;
            buildB(candi, allXORInv);
            for (int j=MAXB-1; j>=0; j--) {
                if (std::abs((maxXOR^B[j])&allXORInv) >
                    std::abs(maxXOR&allXORInv)
                ) { maxXOR^=B[j];}
            }
            res=std::max(res,tmp+allXOR+2ll*(maxXOR & allXORInv));
        }
        return res;
    }
};