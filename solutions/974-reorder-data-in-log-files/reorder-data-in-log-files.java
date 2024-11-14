class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] log1Array = log1.split(" ", 2);
            String[] log2Array = log2.split(" ", 2);
            boolean isDigit1 = Character.isDigit(log1Array[1].charAt(0));
            boolean isDigit2 = Character.isDigit(log2Array[1].charAt(0));
            
            if(isDigit1 && isDigit2) { 
                return 0;
            } else if(isDigit1 && !isDigit2) { 
                return 1;
            } else if(!isDigit1 && isDigit2) { 
                return -1;
            }
            int compare = log1Array[1].compareTo(log2Array[1]);
            
            return compare == 0 ? log1Array[0].compareTo(log2Array[0]) : compare;
        });
        return logs;
    }
}