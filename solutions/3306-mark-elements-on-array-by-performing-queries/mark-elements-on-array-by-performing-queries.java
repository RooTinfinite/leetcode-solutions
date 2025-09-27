class Solution {    

    public long[] unmarkedSumArray(int[] arr, int[][] query) {
        
        Queue<pair> pq=new PriorityQueue<>((a,b) ->{
            if(a.val==b.val)                 // if value is equal sort on basic of index
                return a.idx-b.idx;
            return a.val-b.val;        //else, sort on the basic of value(i.e smaller come first)
        });
        
        long tsum=0l;     // stroing total sum.
        for(int i=0;i<arr.length;i++){
            pq.add(new pair(arr[i], i));
            tsum+=arr[i];
        }
        
        int [] visited=new int[arr.length];   // marking visited index
        long[] ans=new long[query.length];
        int i=0;
        for(int a[] : query){
            
            int idx=a[0];      // geting index form query
            int k=a[1];        // total number of element marked in array correspondece to index.
            if(visited[idx]==0){//abhi tak visited nahi hua hai hence visited karo and tsum se substract karo
                tsum -= arr[idx];
                visited[idx]=1;     // marked visited index so that not take part it again .
            }
            while(!pq.isEmpty() && k!=0){    // yaha par k smallest ko remove karwa rahe hai.
                
                pair p=pq.poll();
                if(visited[p.idx]==0){ // jo visited nahi hai usko bas pick karenge 
                    visited[p.idx]=1;
                    tsum-=arr[p.idx];
                    k--;
                }
            }
            ans[i++]=tsum;
        }
        return ans;
    }
}
class pair{
    
    int val;  // storing value
    int idx;  // storing index of that value.
    pair(int val,int idx){
        this.val=val;
        this.idx=idx;
    }
}