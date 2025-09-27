class Solution {
    int max = -1;
    HashMap<Integer, Integer> hm = new HashMap<>();
    public int mostFrequentPrime(int[][] mat) {
        for(int i = 0; i<mat.length; i++) {
            for(int j = 0; j<mat[0].length; j++) {
                util1(mat, i, j+1, mat[i][j]);
                util2(mat, i+1, j+1, mat[i][j]);
                util3(mat, i+1, j, mat[i][j]);
                util4(mat, i+1, j-1, mat[i][j]);
                util5(mat, i, j-1, mat[i][j]);
                util6(mat, i-1, j-1, mat[i][j]);
                util7(mat, i-1, j, mat[i][j]);
                util8(mat, i-1, j+1, mat[i][j]);
            }
        }
        int res = -1, freq = 0;
        for(Map.Entry<Integer, Integer> e : hm.entrySet()) {
            // System.out.println(e.getKey() +" -> "+ e.getValue());
            if(e.getValue() > freq) {
                res = e.getKey();
                freq = e.getValue();
            } else if(e.getValue() == freq) {
                res = Math.max(e.getKey(), res);
            }
        }
        return res;
    }
    private void util1(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util1(arr, i, j+1, num);
    }
    private void util2(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util2(arr, i+1, j+1, num);
    }
    private void util3(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util3(arr, i+1, j, num);
    }
    private void util4(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util4(arr, i+1, j-1, num);
    }
    private void util5(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util5(arr, i, j-1, num);
    }
    private void util6(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util6(arr, i-1, j-1, num);
    }
    private void util7(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util7(arr, i-1, j, num);
    }
    private void util8(int arr[][], int i, int j, int num) {
        if(i >= arr.length || i < 0 || j >= arr[0].length || j < 0) return;
        num = num*10 + arr[i][j];
        if(isPrime(num)){ 
            hm.put(num, hm.getOrDefault(num, 0)+1);
            max = Math.max(max, hm.get(num));
        }
        util8(arr, i-1, j+1, num);
    }
    public boolean isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= Math.sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
}