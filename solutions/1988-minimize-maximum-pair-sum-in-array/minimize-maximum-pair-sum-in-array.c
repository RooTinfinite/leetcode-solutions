#pragma GCC optimize("O3, unroll-loops")

int minPairSum(int* nums, int n){
    int freq[100001]={0};
    int l=100000, r=1;

    for(int i=0; i<n; i++){
        int x=nums[i];
        freq[x]++;
        if (l>x) l=x;
        if (r<x) r=x;
    }
    int maxP=0, rN=0, lN=0, k=n>>1;

    for(int pairN=1; pairN<=k; pairN++){
        while (lN < pairN) lN+=freq[l++];
    
        while (rN < pairN) rN+=freq[r--];
        int sum=l+r;
        if (sum>maxP) maxP=sum;
    }
    return maxP;
}