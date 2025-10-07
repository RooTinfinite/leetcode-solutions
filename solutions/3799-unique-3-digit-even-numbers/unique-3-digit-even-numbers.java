class Solution {
    public int totalNumbers(int[] a) {
    int s1=0;
    Set<Integer> set=new HashSet<>();
      for(int i=0;i<a.length;i++)
        for(int j=0;j<a.length;j++)
            for(int k=0;k<a.length;k++)
            {
                if(i!=j&&j!=k&&i!=k)
                s1=a[i]*100+a[j]*10+a[k];
                if(s1>=100&&s1%2==0)
                    set.add(s1);
            }  
            System.out.println(set);
            return set.size();
    }
}