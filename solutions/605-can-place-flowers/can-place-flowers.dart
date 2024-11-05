class Solution {
  bool canPlaceFlowers(List<int> f, int n) {
      for(int i=0; i< f.length && n>0; i++){
          if(f[i]==0 && (i==0 || f[i-1]==0)&& (i==f.length-1 || f[i+1]==0)){
              n--;
              i++;
          }
      }
      return n==0 ;
  }
}