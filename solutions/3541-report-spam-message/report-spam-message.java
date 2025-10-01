class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        HashSet<String> set = new HashSet<>();
        for(int i=0;i<bannedWords.length;i++){
            set.add(bannedWords[i]);
        }
        int c = 0;
        for(int i=0;i<message.length;i++){
            if(set.contains(message[i])){
                c++;
            }
        }
        if(c>1){
            return true;
        }
        return false;
    }
}