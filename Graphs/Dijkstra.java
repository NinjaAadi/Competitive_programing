package Graphs;
import java.util.*;



public class Dijkstra{
    private static class Pair{

        public int weight;
        public int node;
        Pair(int weight, int node){
            this.weight = weight;
            this.node = node;
        }
    }
    static class ShortestPathComparator implements Comparator<Pair>{
        

        @Override
        public int compare(Pair o1, Pair o2) {
            if(o1.weight < o2.weight) return -1;
            else if(o2.weight < o1.weight) return 1;
            else return 0;
        }
        
    }
    public static void main(String[] args){
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        int size = 5;
        // Initialize graph with empty adjacency lists
        for (int i = 0; i < size; i++) {
            graph.add(new ArrayList<>());
        }

        // Add edges (for example: (0 -> 1 with weight 10), (0 -> 2 with weight 5), etc.)
        graph.get(0).add(new Pair(10, 1)); // 0 -> 1 (weight 10)
        graph.get(0).add(new Pair(5, 2));  // 0 -> 2 (weight 5)
        graph.get(1).add(new Pair(1, 2));  // 1 -> 2 (weight 1)
        graph.get(2).add(new Pair(2, 3));  // 2 -> 3 (weight 2)
        graph.get(3).add(new Pair(3, 4));  // 3 -> 4 (weight 3)
        int src = 0;
        
        ArrayList<Integer> shortestDist = new ArrayList<>(Collections.nCopies(size,Integer.MAX_VALUE));
        ArrayList<Boolean> visited = new ArrayList<>(Collections.nCopies(size, false));
        shortestDist.set(src, 0);

        PriorityQueue<Pair> priorityQueue = new PriorityQueue<>(new ShortestPathComparator());
        priorityQueue.add(new Pair(0, src));


        while (!priorityQueue.isEmpty()) {
            Pair top = priorityQueue.poll();
            int node = top.node;
            int weight = top.weight;
            if(visited.get(node)) continue;
            visited.set(node, true); 
            

            for(Pair child : graph.get(node)){
                int childNode= child.node;
                int childWeight = child.weight;
                if(childWeight + weight < shortestDist.get(childNode)){
                    shortestDist.set(childNode,childWeight + weight);
                    priorityQueue.add(new Pair(childWeight + weight,childNode));
                }
            }
        }
        for(int i = 0;i<size;i++){
            System.out.println("Shortest path from " + src + " is " + shortestDist.get(i));
        }
    }
}
/*
 *  Each V is processed once as it is marked as visited
 *  For each V we are doing insertion which takes V*log(V) time an for E edges we are inserting which takes E*log(v)
 *  It is important to note that we are doing insertion for each edge only once
 *  Therefore, TC = O((E+V)log(v))
 */
