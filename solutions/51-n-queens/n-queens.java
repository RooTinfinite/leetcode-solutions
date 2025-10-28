class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans=new ArrayList<>();
		char [][]board=new char[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(board[i],'.');
        }
		print(board,0,n,ans);
        return ans;
	}
	public static void print(char[][] board,int row,int tq,List<List<String>> ans) {
		if(tq==0) {
            List<String> sol=new ArrayList<>();
            for(char[] a:board){
                sol.add(new String(a));
            }
            ans.add(sol);
			return;
		}
		for(int col=0;col<board[0].length;col++) {
			if(isItSafe(board,row,col)) {
				board[row][col]='Q';
				print(board,row+1,tq-1,ans);
				board[row][col]='.';
			}
		}
	}
	public static boolean isItSafe(char[][] board,int row,int col) {
		//up
		int r=row;
		while(r>=0) {
			if(board[r][col]=='Q') {
				 return false;
			 }
			r--;
		}
		 //right diagonal
		 r=row;
		 int c=col;
		 while(c<board[0].length && r>=0) {
			 if(board[r][c]=='Q') {
				 return false;
			 }
			 r--;
			 c++;
		 }
		 //left diagonal
		 r=row;
		 c=col;
		 while(c>=0 && r>=0) {
			 if(board[r][c]=='Q') {
				 return false;
			 }
			 r--;
			 c--;
		 }
		 return true;
	}
	

}