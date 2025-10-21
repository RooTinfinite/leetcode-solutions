class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long maxnum=*max_element(nums.begin(), nums.end()); //get largest element
        long long bits=0; //num of bits in that element
        while((1<<bits)<=maxnum){
            bits++;
        }
        int num_of_mask=1<<bits; //how many possible masks are there (if bits=3, then 8 masks)

        vector<int>best_mask(num_of_mask,0);//largest number corresponding to each mask
        for(int v:nums){
            best_mask[v]=max(best_mask[v],v);
        }

        //if best_mask[010]=5, then best_mask[110]=5 as 010 is subset of 110 (010 & 110= 010)
        for(int b=0;b<bits;b++){
            for(int mask=0 ;mask<num_of_mask; mask++){
                if(mask & (1<<b)){ //if bit b of a mask is set
                    best_mask[mask]=max(best_mask[mask], best_mask[mask ^ (1<<b)]); //taking xor will make that bit unset so that we get a subset of mask
                }
            }
        }
        long long ans=0;
        long long allmask=num_of_mask-1; //111
        for(long long v:nums){
            long long complement=allmask^v; //gives all mask that donot overlap with v

            if(best_mask[complement]>0 and best_mask[complement]!=v){
                ans=max(ans, v* best_mask[complement]);
            }
        }
        return ans;
    }
};