class Solution {
    public boolean squareIsWhite(String coordinates) {
      
      HashMap<Character,Integer> hm=new HashMap<>();
      hm.put('a',1);
      hm.put('b',2);
      hm.put('c',3);
      hm.put('d',4);
      hm.put('e',5);
      hm.put('f',6);
      hm.put('g',7);
      hm.put('h',8);
    char key=coordinates.charAt(0);
     int r=Character.getNumericValue(coordinates.charAt(1));
    int temp=hm.get(key);
      if((r+temp)%2==0){
        return false;

      }
      return true;
    }
}