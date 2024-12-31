package Graphs;

import java.util.Arrays;

public class BellmanFord {
    static int[] bellmanFord(int V, int[][] edges, int src) {
        int [] dist = new int[V];

        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[src] = 0;
        for(int i = 1;i<=V-1;i++){
            for(int j = 0;j<edges.length;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for(int j = 0;j<edges.length;j++){
            int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[u]!=Integer.MAX_VALUE && dist[u] + w < dist[v]){
                    Arrays.fill(dist,-1);
                    return dist;
                }
        }
        for(int i = 0;i<V;i++){
            if(dist[i] == Integer.MAX_VALUE) dist[i] = 100000000;
        }
        return dist;
    }
    public static void main(String[] args){

    }
}
/*
 * 
 * TC: O(V*E) 
 */