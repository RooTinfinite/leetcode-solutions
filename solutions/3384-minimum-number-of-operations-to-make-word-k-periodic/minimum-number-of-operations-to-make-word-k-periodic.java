class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        HashMap<String,Integer> hm=new HashMap<>();
        int i=0;
        while(i<word.length()){
            hm.put(word.substring(i,i+k),hm.getOrDefault(word.substring(i,i+k),0)+1);
            i+=k;
        }
        int maxOccur=0;
        for(String st : hm.keySet()){
            maxOccur=Math.max(hm.get(st),maxOccur);
        }
        return (word.length()/k)-maxOccur;
    }
}