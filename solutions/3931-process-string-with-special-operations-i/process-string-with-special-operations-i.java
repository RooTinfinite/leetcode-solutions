class Solution {
    public String processStr(String s) {
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()){
            if(c >= 'a' && c <= 'z')
                sb.append(c);

            if(c == '*'){
                if(sb.length() != 0){
                    sb.deleteCharAt(sb.length() - 1);
                }
            }

            if(c == '#'){
                String temp = sb.toString();
                sb.append(temp);
            }
            
             if(c == '%'){
                 sb.reverse();
             }
        }
        return sb.toString();
    }
}