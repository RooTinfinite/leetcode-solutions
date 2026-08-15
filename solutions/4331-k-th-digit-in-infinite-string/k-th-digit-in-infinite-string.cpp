class Solution {
public:
    int kthDigit(long long k){
        if(k<=9)return k;
        vector<long long>v;
        v.push_back(0);
        long long p=1,sum=0;
        for(int i=1;i<=16;i++){
            sum+=9*p*i; // digits contributed by all i-digit numbers
            v.push_back(sum);
            p*=10;
        }
        v.push_back(sum);
        int idx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>=k){
                idx=i; // target lies in the idx-digit group
                break;
            }
        }
        k-=v[idx-1]; // remove previous digit groups
        k--; // convert to 0-based indexing
        long long num=k/idx,d=k%idx;
        long long b=1;
        for(int i=0;i<idx-1;i++)b*=10; // first idx-digit number
        long long val=b+num;
        long long bb=val/10; // block number
        if(bb%2){
            val=bb*10+(9-(val%10)); // odd blocks are reversed
        }
        string res=to_string(val);
        return res[d]-'0'; // return required digit
    }
};