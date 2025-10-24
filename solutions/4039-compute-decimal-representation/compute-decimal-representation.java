class Solution {
    public int[] decimalRepresentation(int n) {

        List <Integer> res = new ArrayList<>();

        int i=1;
        while(n>0)
        {
            int rem = n%10;
            if(rem!=0)
            {
                res.add(i*rem);
            }
            n=n/10;
            i=i*10;
        }
        int [] arr = new int[res.size()];
        for(int j=0;j<res.size();j++)
        {
            arr[res.size()-j-1] = res.get(j);
        }

        return arr;
    }
}