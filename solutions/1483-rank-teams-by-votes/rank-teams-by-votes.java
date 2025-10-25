class Solution {
    static class Element{
        char name;
        int[] voteCounts;

        Element(int size,char name){
            this.name = name;
            voteCounts = new int[size];
        }
    }
    List<Element> voteContainer = new ArrayList<>();
    HashMap<Character,Integer> charToIndexMap = new HashMap<>();

    public String rankTeams(String[] votes){

        for (int i = 0; i < votes[0].length(); i++){
            char c = votes[0].charAt(i);
            Element e = new Element(votes[0].length(),c);
            charToIndexMap.put(votes[0].charAt(i),voteContainer.size());
            voteContainer.add(e);
        }

        for (int i = 0; i < votes.length; i++){
            for (int j = 0; j < votes[0].length(); j++){
                Character c = votes[i].charAt(j);
                int voteIdx = j;

                Integer indexOfChar = charToIndexMap.get(c);
                Integer currentVoteCount = voteContainer.get(indexOfChar).voteCounts[voteIdx];
                voteContainer.get(indexOfChar).voteCounts[voteIdx] = currentVoteCount+1;
            }
        }




        //problem boils down to sorting a list of Element
        voteContainer.sort((a,b) -> {
            for (int i = 0; i < a.voteCounts.length; i++){
                if (!Objects.equals(a.voteCounts[i], b.voteCounts[i])){
                    return Integer.compare(b.voteCounts[i],a.voteCounts[i]);
                }
            }
            return Character.compare(a.name,b.name);
        });

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < voteContainer.size(); i++){
            sb.append(voteContainer.get(i).name);
        }

        return sb.toString();


    }
}