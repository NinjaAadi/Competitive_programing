package Graphs;

public class CycleDetection {
    public boolean isCyclePresentInDirectedGraph(int node, int [] leftChild,int [] rightChild, int [] visited){
        if(node == -1) return false;
        if(visited[node] != 0){
            if(visited[node] == 1) return true;
            else if(visited[node] == 3) return true;
            else return false;
        }
        System.out.println(node);
        visited[node] = 1;

        boolean isCycle =  isCyclePresentInDirectedGraph(leftChild[node],leftChild,rightChild,visited) || 
                           isCyclePresentInDirectedGraph(rightChild[node],leftChild,rightChild,visited);
        if(isCycle) visited[node] = 3;
        else visited[node] = 2;
        return isCycle;
    }
    public static void main(String args[]){

    }
}
