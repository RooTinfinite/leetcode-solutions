class Solution {
    public String reorderSpaces(String text) {
        int n = text.length();
        int spaces = 0;
        // int i = 0;
        for(int i=0;i<n;i++)
        {
            char ch = text.charAt(i);
            if(ch==' ') spaces++;
        }
        //we have total length and total space count till now 
        //now next step is to find the cnt of words in text 
        ArrayList<String> list = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        text = text+" ";
        int j=0;
        while(j<text.length()){
            while(text.charAt(j)!=' '){
                sb.append(text.charAt(j));
                j++;
            }
            if(sb.toString().length()>0){
            list.add(sb.toString());
            sb.setLength(0);}  // clears the contents of the StringBuilder
            j++;
        }
    int words=list.size();//total number of words in the text
    if(words!=1){
    int spaces_between = spaces/(words-1);
    int k = spaces_between;
    int extra  = spaces%(words-1);
    sb.setLength(0);  // clears the contents of the StringBuilder
    for(int i =0;i<list.size();i++){
        String str = list.get(i);
        sb.append(str);
        if(i!=list.size()-1){
            spaces_between=k;
        while(spaces_between-->0){
            sb.append(" ");}
        }else{
            while(extra-->0){
                sb.append(" ");
            }
        }
    }
    return sb.toString();
    }else{
        sb.setLength(0);  // clears the contents of the StringBuilder
        sb.append(list.get(0));
        while(spaces-->0){
            sb.append(" ");
        }
        return sb.toString();
    }
    }
}