class Solution {


    String word="";
    public int maxLen(int n, int[][] edges, String label) {

//making the graph
        ArrayList<ArrayList<Integer>> graph=new ArrayList<>();
        for(int i=0;i<n;i++) graph.add(new ArrayList<Integer>());
        for(int i=0;i<edges.length;i++){

            graph.get(edges[i][1]).add(edges[i][0]);
            graph.get(edges[i][0]).add(edges[i][1]);
        }

//our bit mask to store visited or not
        int vis=0;

//memoization array
        int[][][] map=new int[(1<<n)][n][n];

        word=label;
        int len=1;

        //even length case
        //for every vertex
        for(int i=0;i<n;i++){

            //for every vertex that has an edge to ith vertex
            for(int j:graph.get(i)){

                if(i==j) continue;

                if(label.charAt(i)!=label.charAt(j)) continue;

                len=Math.max(len,dfs(graph,i,j,vis,map));
            }
            
        }

        //odd length case
        for(int i=0;i<n;i++){

            //since ith vertex is at center marking it as visited
            vis=(vis|(1<<i));

            for(int j:graph.get(i)){

                for(int k:graph.get(i)){

                    if(k==j) continue;
                    if(label.charAt(k)!=label.charAt(j)) continue;

                    len=Math.max(len,1+dfs(graph,k,j,vis,map));

                }
            }
            
            vis=(vis^(1<<i));
            
        }

    

        return len;

    }


public int dfs(ArrayList<ArrayList<Integer>> graph,int u,int v,int vis,int[][][] map){

        if(map[vis][u][v]!=0) return map[vis][u][v]; 

        //marking visited
        vis=(vis|(1<<v));
        vis=(vis|(1<<u));

        int ans=0;

        //all the connected vertex to u
        for(int i:graph.get(u)){

            //all the connected vertex to v
            for(int j:graph.get(v)){

                if(i==j) continue;

                //checking whether vertices has been visited or not
                if((vis&(1<<i)) > 0 || (vis&(1<<j))>0 ) continue;

                //not considering whose labels don't match
                if(word.charAt(i)!=word.charAt(j)) continue;

                ans=Math.max(ans,dfs(graph,i,j,vis,map));
            }
        }

        //marking unvisited
        vis=(vis^(1<<v));
        vis=(vis^(1<<u));

        map[vis][u][v]=ans+2;
        return ans+2;
    }

}