class Solution {
    public String removeSubstring(String s, int k) {
        List<Integer> openCounts = new ArrayList<>();
        List<Integer> closeCounts = new ArrayList<>();
        int currentOpen = 0;
        int currentClose = 0;
        StringBuilder charStack = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            charStack.append(c);
            
            if (c == '(') {
                if (currentClose != 0) {
                    closeCounts.add(currentClose);
                    openCounts.add(currentOpen);
                    currentClose = 0;
                    currentOpen = 1;
                } else {
                    currentOpen++;
                }
            } else if (c == ')') {
                currentClose++;
            }
            
            while (true) {
                if (currentClose == k && currentOpen > k) {
                    for (int i = 0; i < 2 * k; i++) {
                        charStack.deleteCharAt(charStack.length() - 1);
                    }
                    currentOpen -= k;
                    currentClose -= k;
                } else if (currentClose == k && currentOpen == k) {
                    for (int i = 0; i < 2 * k; i++) {
                        charStack.deleteCharAt(charStack.length() - 1);
                    }
                    currentOpen -= k;
                    currentClose -= k;
                    if (charStack.length() > 0) {
                        char lastChar = charStack.charAt(charStack.length() - 1);
                        if (lastChar == '(') {
                            currentOpen = openCounts.remove(openCounts.size() - 1);
                        } else {
                            currentOpen = openCounts.remove(openCounts.size() - 1);
                            currentClose = closeCounts.remove(closeCounts.size() - 1);
                        }
                    }
                } else {
                    break;
                }
            }
        }
        
        return charStack.toString();
    }
}