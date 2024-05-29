#include<stdio.h>
#define max 7
#define INF 99999

void dijkstra(int adj[max][max], int n, int start){
    int cost[max][max], dist[max], pred[max];
    int visited[max], cnt, min, next, i, j;
    int total_cost = 0;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(adj[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=adj[i][j];
    
    for(i=0;i<n;i++){
        dist[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }
    
    dist[start]=0;
    visited[start]=1;
    cnt=1;
    
    while(cnt<n){
        min=INF;
        for(i=0;i<n;i++){
            if(dist[i]<min && !visited[i]){
                min=dist[i];
                next=i;
            }
        }
        visited[next]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(min+cost[next][i] < dist[i]){
                    dist[i]=min+cost[next][i];
                    pred[i]=next;
                }
        cnt++;
    }
    for(i=0;i<n;i++)
        if(i!=start){
            printf("\nDistance from source to %c : %d", i+'A', dist[i]);
        }
    for(i=0;i<n;i++)
        if(total_cost<dist[i]){
            total_cost = dist[i];
        }
    printf("\nTotal Cost of the Minimum Spanning Tree : %d\n", total_cost);
}

int main(){
    int adj[max][max], i, j, n=max, u;
    int ch;
    printf("\n---- MAIN MENU ----\n");
    printf("1. Enter the values of the graph\n");
    printf("2. Dijkstra's Algorithm\n");
    printf("3. Exit\n");
    do{
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the Adjacency Matrix : \n");
                for(i=0;i<max;i++)
                    for(j=0;j<max;j++)
                        scanf("%d", &adj[i][j]);
                break;
            case 2:
                printf("Enter the starting node (0 to %d): ", max - 1);
                scanf("%d", &u);
                if(u < 0 || u >= max) {
                    printf("Invalid starting node. Please enter a number between 0 and %d.\n", max - 1);
                    break;
                }
                dijkstra(adj, n, u);
                break;
            case 3:
                printf("Thank you");
                break;
            default:
                printf("Invalid Input\n");
        }
    } while(ch!=3);
    return 0;
}

