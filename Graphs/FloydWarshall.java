package Graphs;

public class FloydWarshall {
    public static void main(String args[]){
        int [][] mat = new int[10][10];
        int v = 10;
        for(int mid = 0;mid <v;mid++){
            for(int start = 0;start<v;start++){
                for(int end = 0;end<v;end++){
                    if(mat[start][mid]!=-1 && mat[mid][end]!=-1){
                        mat[start][end] = Math.min(mat[start][end],mat[start][mid] + mat[mid][end]);
                    }
                }
            }
        }
        
    }
}
