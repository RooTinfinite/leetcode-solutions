class Solution {
    public static int countVowelSubstrings(String word) {
        
    	int n = word.length();
    	int count = 0;
    	
    	for (int i = 0; i < n; i++) {
			
    		Set<Character> hs = new HashSet<Character>();
    		
    		for (int j = i; j < n; j++) {
				
    			char ch =  word.charAt(j);
    			
    			if(isVowel(ch)) {
    				hs.add(ch);
    				
    				if(hs.size()==5) {
    					count++;
    				}
    				
    			}else {
    				break;
    			}
    			
    			
			}
    		
		}
    	
    	return count;

    	
    }
	
	private static boolean isVowel(char ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
	}
}