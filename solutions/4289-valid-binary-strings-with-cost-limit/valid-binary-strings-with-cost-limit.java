class Solution {
    ArrayList<String> res;
    public List<String> generateValidStrings(int n, int k) {
        res = new ArrayList<>();
        bt("",k,n);
        return res;
    }
    private void bt(String str,int k,int n){
        if(n == 0){
            if(n == 0 && k >= 0){
                res.add(str);
            }
            return;
        }
        int len = str.length();
        if(str.isEmpty() || str.charAt(len - 1) != '1'){
            bt(str + "1",k - len,n - 1);
        }
        bt(str + "0",k,n - 1);
    }
}