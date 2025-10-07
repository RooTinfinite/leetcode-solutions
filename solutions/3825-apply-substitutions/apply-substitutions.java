class Solution {
    public String applySubstitutions(List<List<String>> replacements, String text) {
        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < replacements.size(); i++) {
            List<String> replacement = replacements.get(i);
            map.put("%" + replacement.get(0) + "%", replacement.get(1));
        }

        boolean changed = true;

        while (changed) {
            changed = false;
            for (Map.Entry<String, String> m : map.entrySet()) {
                if(text.contains(m.getKey())){
                    text = text.replace(m.getKey(), m.getValue());
                    changed = true;
                }
            }
        }

        return text;
    }
}