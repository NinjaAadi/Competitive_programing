package Graphs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class TopSort {
     static ArrayList<Integer> topologicalSortUsingBFS(ArrayList<ArrayList<Integer>> adj) {
        
        ArrayList<Integer> topSortNodes = new ArrayList<>();
        int size = adj.size();
        int [] indeg = new int[size];
        Arrays.fill(indeg,0);
        for(ArrayList<Integer> adjacentNodes : adj){
            for(Integer adjacentNode : adjacentNodes){
                indeg[adjacentNode]++;
            }
        }
        Queue<Integer>m_queue = new LinkedList<>();
        
        for(int i = 0;i<size;i++){
            if(indeg[i] == 0) m_queue.add(i);
        }
        while(!m_queue.isEmpty()){
            int top = m_queue.poll();
            topSortNodes.add(top);
            
            for(Integer adjacentNode : adj.get(top)){
                indeg[adjacentNode]--;
                if(indeg[adjacentNode] == 0) m_queue.add(adjacentNode);
            }
        }
        
        
        return topSortNodes;
        // O(V + E)
    }
     static void dfs(int node, ArrayList<ArrayList<Integer>> adj,Stack<Integer> topSort,boolean [] visited){
        if(visited[node]) return;
        visited[node] = true;
        for(Integer adjNodes : adj.get(node)){
            dfs(adjNodes,adj,topSort,visited);
        }
        topSort.push(node);
    }
    static ArrayList<Integer> topologicalSortUsingDFS(ArrayList<ArrayList<Integer>> adj) {
        Stack<Integer> topSort = new Stack<>();
        boolean [] visited = new boolean[adj.size()];
        for(int i = 0;i<adj.size();i++){
            dfs(i,adj,topSort,visited);
        }
        ArrayList<Integer>topologicalSortItems = new ArrayList<>(topSort);
        Collections.reverse(topologicalSortItems);
        return topologicalSortItems;
        //TC O(V + E)
    }

    public static void main(String[] args){

    }
}
