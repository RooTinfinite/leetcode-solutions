class Solution {
    public long numberOfPairs(int[] arr1, int[] arr2, int k) {

        HashMap<Integer,Long> hp = new HashMap<>();
        for(var a : arr2) hp.put(a*k,hp.getOrDefault(a*k,(long)0)+(long)1);

        long ans = 0;

        for(var a : arr1){
            int n = (int)Math.sqrt(a);
            for(int i=1; i<=n; i++){
                if(a%i==0){
                    int x = a/i;
                    if(x!=i && hp.containsKey(x)) ans = ans+hp.get(x);
                    if(hp.containsKey(i)) ans = ans+hp.get(i);
                }
            }
        }
        return ans;
    }
}