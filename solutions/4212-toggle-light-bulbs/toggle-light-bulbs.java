class Solution {
    public List<Integer> toggleLightBulbs(List<Integer> bulbs) {
        boolean[] on = new boolean[101];
        for(int b : bulbs) on[b] = !on[b];
        List<Integer> ans = new ArrayList<>();
        for(int i = 1; i < 101; ++i)
            if(on[i]) ans.add(i);
        return ans;
    }
}