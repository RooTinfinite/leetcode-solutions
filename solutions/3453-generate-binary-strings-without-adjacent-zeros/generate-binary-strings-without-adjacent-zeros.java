class Solution {
    public List<String> validStrings(int n) {
        StringBuilder s=new StringBuilder();
        for(int i=0;i<n;i++) s.append("1");
        List<String> list=new ArrayList<>();
        generate(0,s,list);
        return list;
    }
    void generate(int i, StringBuilder s, List<String> list) {
        if(i>=s.length()) {
            list.add(s.toString());
            return;
        }
        generate(i+1,s,list);
        s.setCharAt(i,'0');
        generate(i+2,s,list);
        s.setCharAt(i,'1');

    }
}