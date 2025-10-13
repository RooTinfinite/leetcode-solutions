class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("electronics", 0);
        map.put("grocery", 1);
        map.put("pharmacy", 2);
        map.put("restaurant", 3);
        HashMap<String, String> map2 = new HashMap<>();
        PriorityQueue<String> q = new PriorityQueue<>(new Comparator<String>(){
            public int compare(String s1, String s2){
                if(map2.get(s1).equals(map2.get(s2))){
                    return s1.compareTo(s2);
                }
                return Integer.compare(map.get(map2.get(s1)),map.get(map2.get(s2)));
            }
        });
        List<String> ans = new ArrayList<>();
        for(int i = 0; i<code.length; i++){
            if(isActive[i] && map.containsKey(businessLine[i])){
                boolean t = true;
                if(code[i].length() == 0) continue;
                for(char ch : code[i].toCharArray()){
                    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') t = true;
                    else {
                        t = false; break;
                    }
                }
                if(t){
                    map2.put(code[i]+Integer.toString(i+100), businessLine[i]);
                    q.add(code[i]+Integer.toString(i+100));
                }
            }
        }
        while(!q.isEmpty()) {
            String ss = q.poll();
            ans.add(ss.substring(0, ss.length()-3));
        }
        return ans;
    }
}