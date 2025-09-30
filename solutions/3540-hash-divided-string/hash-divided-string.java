class Solution {
    public String stringHash(String s, int k) {
        HashMap<Character,Integer> hm = new HashMap<>();
        HashMap<Integer,Character> hm1=new HashMap<>();
        String ns="abcdefghijklmnopqrstuvwxyz";
        for(int cc=0;cc<26;cc++){
            Character c=ns.charAt(cc);
            hm.put(c,cc);
            hm1.put(cc,c);
        }
        String out=new String();
        int n=s.length(),i;
        for(i=0;i<n;i+=k){
            int t=0;
            for(int j=i;j<i+k;j++){
                t+=hm.get(s.charAt(j));
            }
            out+=hm1.get(t%26);
        }
        return  out;
    }
}