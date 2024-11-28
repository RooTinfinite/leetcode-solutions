class Solution{
public:
    long long int global=0;
    long long int b[500000];
    void merge(vector <int> &arr, int l, int mid, int r)
    {
        int i=l;
        int j=mid+1;
        int k=l;
        
        while(i<=mid && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                b[k]=arr[i];
                k++;
                i++;
            }
            else
            {
                b[k]=arr[j];
                k++;
                j++;
                global+=(mid+1-i);
            }
        }
        if(i>mid)
         {
             while(j<=r)
             {
                 b[k]=arr[j];
                 k++;
                 j++;
             }
         }
         else if(j>r)
         {
             while(i<=mid)
             {
                 b[k]=arr[i];
                 k++;
                 i++;
             }
         }
         
         for(int p=l; p<k; p++)
         {
             arr[p]=b[p];
         }
    }
    void mergesort(vector <int> &arr, int l, int r)
    {
        int mid=(l+r)/2;
        if(l<r)
        {
            mergesort(arr, l, mid);
            mergesort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
    
    bool isIdealPermutation(vector<int>& nums) 
    {        
        int local=0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i + 1])
                local++;
        }
        
        mergesort(nums, 0, nums.size()-1); 
        cout<<global<<" "<<local<<endl;
        
        return local==global;
    }
};