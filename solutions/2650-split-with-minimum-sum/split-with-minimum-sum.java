class Solution {
    public int splitNum(int num) {
        
          
          int num1=num;
          int length=0;
         while(num1>0){
           num1=num1/10;
           length++;
         }

         int arr[]=new int[length];
         int j=0;
        while(num>0){
            int i=num%10;
            arr[j]=i;
            j++;
            num=num/10;
        }

           Arrays.sort(arr);

         
           for (int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
           }

            int num2=0;
          int num3=0;
        for(int i=0;i<arr.length;i++){
             if(i%2==0){
             int q=arr[i];
             num2=num2+q;
             num2=num2*10;
             }else{
               int  z=arr[i];
                num3=num3+z;
                num3=num3*10;
             }
        }
            num2=num2/10;
           
            num3=num3/10;
        
            return num2+num3;
    }
}