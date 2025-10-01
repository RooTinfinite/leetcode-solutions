class Solution {
    public List<String> stringSequence(String target) {
        List<String> res = new ArrayList<>();
        res.add("a");
        while (!res.get(res.size() - 1).equals(target)) {
            String last = res.get(res.size() - 1);
            if (last.charAt(last.length() - 1) != target.charAt(last.length() - 1)) {
                last = last.substring(0, last.length() - 1) + (char) (last.charAt(last.length() - 1) + 1);
            } else {
                last += "a";
            }
            res.add(last);
        }
        return res;
    }
}