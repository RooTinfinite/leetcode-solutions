class Solution {
    public String largestWordCount(String[] messages, String[] senders) {
        int n = senders.length;
        Map<String, Integer> user = new HashMap<>();
        for(int i=0; i<n; i++) {
            String sender = senders[i];
            int count = messages[i].split(" ").length;
            user.put(sender,user.getOrDefault(sender,0)+count);
        }
        String maxUser = "";
        int max = 0;
        for(Map.Entry<String,Integer> map : user.entrySet()) {
            String sender = map.getKey();
            int count = map.getValue();
            if(count > max || (count==max && sender.compareTo(maxUser) > 0)) {
                max = count;
                maxUser = sender;
            }
        }
        return maxUser;
    }
}