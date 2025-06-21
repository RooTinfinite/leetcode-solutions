class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        int n = arr1.size(); 
        int m = arr2.size();
        int count = 0;
        for(int i = 0;i < n;i++){
            
            int start = 0;
            int end = m -1;
            
            while(start <= end){
               
             int mid = start + (end - start)/2;
             int sum = abs(arr1[i] - arr2[mid]); // sum
             if(sum <= d){
                count++;
                break;
             }
            if(arr2[mid]  < arr1[i]){
                start = mid +1;
            }
            else{  
                end = mid -1;
            }
             

            }
        }

       return (n - count);  // return the value
    }
};

