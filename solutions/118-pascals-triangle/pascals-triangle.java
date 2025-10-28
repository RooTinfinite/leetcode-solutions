class Solution {
    public List<List<Integer>> generate(int numRows) {
        // bada daba
        List<List<Integer>> result=new ArrayList<>();

        
        for(int i=0;i<numRows;i++){
            List<Integer> row=new ArrayList<>();
            for(int j=0;j<=i;j++){
                // mark start value and end value as 1
                if(j==0||j==i) row.add(1);
                else{
                    int val=result.get(i-1).get(j)+result.get(i-1).get(j-1);
                    row.add(val);
                }
            }
            result.add(row);
        }
        return result;
        
    }
}