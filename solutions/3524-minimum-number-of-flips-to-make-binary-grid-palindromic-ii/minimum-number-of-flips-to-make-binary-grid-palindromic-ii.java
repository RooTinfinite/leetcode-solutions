class Solution {

    public int minFlips(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;

        int rh = rows/2;
        int ch = cols/2;

        int flips = 0;

        for( int row = 0; row < rh ; row++ ){
            for( int col = 0; col < ch ; col++ ){
                int zeros = 0;
                int ones = 0;

                if(grid[row][col] == 1){
                    ones++;
                }else{
                    zeros++;
                }

                if(grid[row][cols - 1 - col] == 1){
                    ones++;
                }else{
                    zeros++;
                }

                if(grid[rows - 1 - row][col] == 1){
                    ones++;
                }else{
                    zeros++;
                }

                if(grid[rows - 1 - row][cols - 1 - col] == 1){
                    ones++;
                }else{
                    zeros++;
                }

                if((ones > 0) && (zeros > 0)){
                    flips = flips + Math.min(ones , zeros);
                }
            }
        }

        boolean rowEven = (rows % 2 == 0) ? true : false;
        boolean colEven = (cols % 2 == 0) ? true : false;

        if(rowEven && colEven){
            return flips;
        }

        int tempFlips = 0;
        int ones = 0;

            if(rowEven == false){
                // odd 

                for(int col = 0; col < ch ; col++ ){
                    if(grid[rh][col] != grid[rh][cols - 1 - col]){
                        tempFlips++;
                    }else{
                        if(grid[rh][col] == 1){
                            ones = ( ones + 2 ) % 4;
                        }
                    }
                }
            }
            
            if(colEven == false){

                for(int row = 0; row < rh ; row++ ){
                    if(grid[row][ch] != grid[rows - 1 - row][ch]){
                        tempFlips++;
                    }else{
                        if(grid[row][ch] == 1){
                            ones = (ones + 2) % 4;
                        }
                    }
                }
            }

            if(tempFlips == 0){
                tempFlips = ones;
            }

            if( rowEven == false && colEven == false ){
                if(grid[rh][ch] == 1){
                    flips++;
                }
            }

        flips += tempFlips;

        return flips;
}}