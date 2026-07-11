class Solution {
    public int[] scoreValidator(String[] events) {
        int score=0;
        int counter=0;
       for(String str:events){
           if(str.equals("W")){
               counter++;
                if(counter>=10){
            break;
        }
           }
           else{
               if(str.length()==2){
                   score++;
               }
               else{
                   score+=Integer.parseInt(str);
               }
           }
       }
        return new int[]{score,counter};
    }
}