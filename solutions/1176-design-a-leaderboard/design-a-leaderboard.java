class Leaderboard {

    private HashMap<Integer, Integer> scores;
    
    public Leaderboard() {
      
        // Since this is a single threaded application and we don't need synchronized access, a 
        // HashMap is a good choice of data structure as compared to a Hashtable. Read more here:
        // https://stackoverflow.com/questions/40471/what-are-the-differences-between-a-hashmap-and-a-hashtable-in-java 
        this.scores = new HashMap<Integer, Integer>();
    }
    
    public void addScore(int playerId, int score) {
        
        if (!this.scores.containsKey(playerId)) {
            this.scores.put(playerId, 0);
        }
        
        this.scores.put(playerId, this.scores.get(playerId) + score);
    }
    
    public int top(int K) {
        
        List<Integer> values = new ArrayList<Integer>(this.scores.values());
        Collections.sort(values, Collections.reverseOrder());
        
        int total = 0;
        for (int i = 0; i < K; i++) {
            total += values.get(i);            
        }
        
        return total;
    }
    
    public void reset(int playerId) {
        this.scores.put(playerId, 0);
    }
}