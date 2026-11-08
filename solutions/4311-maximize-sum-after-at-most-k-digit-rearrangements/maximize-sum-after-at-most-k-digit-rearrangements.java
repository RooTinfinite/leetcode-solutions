class Solution {
    public long maximizeSum(int[] nums, int k) {
      long sum = 0;
      for(int i=0;i<nums.length;i++) {
        sum = sum + nums[i];
      }
      TreeMap<Integer,List<Integer>> tm = new TreeMap<>(Collections.reverseOrder());
      long max = Long.MIN_VALUE;
      for(int i=0;i<nums.length;i++) {
         String value = ""+nums[i];
         Integer val[] = new Integer[value.length()];
         for(int j=0;j<val.length;j++) {
            val[j] = Integer.parseInt(value.charAt(j)+"");
         }
         Arrays.sort(val, Collections.reverseOrder());
         String res = "";
         for(int j=0;j<val.length;j++) {
            res = res + val[j];
         }
         int newval = Integer.parseInt(res);
         if(tm.containsKey(newval-nums[i])) {
           List<Integer> li = tm.get(newval-nums[i]);
           li.add(nums[i]);
           tm.put(newval-nums[i], li);
         }
         else {
           List<Integer> li = new ArrayList<>();
           li.add(nums[i]);
           tm.put(newval-nums[i], li);
         }
      }
      int count = 0;
       long summ = 0;
      for(Map.Entry<Integer,List<Integer>> entry : tm.entrySet()) {
        int key = entry.getKey();
        List<Integer> li = entry.getValue();
        for(int i=0;i<li.size();i++) {
          summ = summ + key;
          count++;
          if(count>=k) {
            break;
          }
        }
        if(count>=k) {
            break;
        }
      }
      return sum+summ;  
    }
}