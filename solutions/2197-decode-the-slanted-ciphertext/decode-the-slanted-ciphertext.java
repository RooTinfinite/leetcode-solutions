class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        if(encodedText.length()<=1) return encodedText;
        int col=encodedText.length()/rows;
        char[][] mat=new char[rows][col];
        int eIndex=0;
        for(int i=0;i<rows;i++){

            for(int j=0;j<col;j++){
                mat[i][j]=encodedText.charAt(eIndex++);

            }
        }
        // display(mat);
        // String res="";
        StringBuilder res = new StringBuilder();

        for(int j=0;j<col;j++){
            int t=j;

            for(int i=0;i<rows;i++){
                if(i==rows || t==col) break;
                res.append(mat[i][t++]);
            }
        }
        // int x =0;
        // for(int k=res.length()-1;k>=0;k--){
        //     if(res.charAt(k)> 96 && res.charAt(k)<123) {
        //         x=k;
        //         break;
        //     }

        // }

          return res.toString().replaceAll("\\s+$", "");
    }
    public void display(char[][] arr){
        
        for(int i=0;i<arr.length;i++){

            for(int j=0;j<arr[0].length;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();

        }
    }
}