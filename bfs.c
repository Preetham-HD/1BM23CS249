#include<stdio.h>
#include<stdlib.h>

void bfs(int adj[10][10],int n,int src){
    int q[10];
    int front=0,rear=-1;
    int visited[10]={0};
    int node;
    printf("the node visited from %d is:",src);
    q[++rear]=src;
    visited[src]=1;
    printf("%d->",src);
    while(front<=rear){
        int u=q[front++];
        for(int v=0;v<n;v++){
            if(adj[u][v]==1){
                if(visited[v]==0){
                    printf(" %d ->",v);
                    visited[v]=1;
                    q[++rear]=v;
                }
            }
        }
    }
    printf("\n");
}
void main(){
    int n;
    int adj[10][10];
    int src;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(src=0;src<n;src++){
        bfs(adj,n,src);
    }
}

/*
output:
enter the no of nodes:3
enter the adjacency matrix:0
1
1
1
0
1
1
1
0
the node visited from 0 is:0-> 1 -> 2 ->
the node visited from 1 is:1-> 0 -> 2 ->
the node visited from 2 is:2-> 0 -> 1 ->
*/
