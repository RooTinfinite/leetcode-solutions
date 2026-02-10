int longestBalanced(int* nums, int numsSize) {
    int ans  = 0;
    for(int i=0;i<numsSize;i++){
        int *map  =calloc(1e5+1,sizeof(int));
        int odd = 0, even = 0;
        if(ans>=(numsSize-i+1)) break;
        for(int j=i;j<numsSize;j++){
            if(map[nums[j]]==0){
                if((nums[j]&1)==1) odd++;
                else even++;
            }
            map[nums[j]]=1;
            if(even==odd) ans = fmax(j-i+1,ans);
        }
        free(map);

    }
    return ans;
}