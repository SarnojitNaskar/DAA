#include<stdio.h>
#include<conio.h>
#define max 5
#define INF 9999999

//int max;

void bfs(int adj[][max], int visited[], int start){
	int queue[max], rear=-1, front=-1, i, k;
	for(k=0;k<max;k++)
		visited[k]=0;
		
	queue[++rear]=start;
	++front;
	visited[start]=1;
	
	while(rear>=front){	//queue is empty
		start=queue[front++];
		printf("%c\t", start+65);
		
		for(i=0;i<max;i++){	//add neighbours
			if(adj[start][i] && visited[i] == 0){
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}

void dfs(int adj[][max], int visited[], int start){
	int stack[max], top=-1, i, k;
	for(k=0;k<max;k++)
		visited[k]=0;
		
	stack[++top]=start;
	visited[start]=1;
	
	while(top!=-1){	//stack is empty
		start=stack[top--];
		printf("%c\t", start+65);
		
		for(i=0;i<max;i++){	//add neighbours
			if(adj[start][i] && visited[i] == 0){
				stack[++top]=i;
				visited[i]=1;
				break;
			}
		}
	}
}

int prim_min_key(int adj[][max]){
	int no_edge;
	int selected[max];
	int total_cost=0;
	memset(selected, 0, sizeof(selected));
	no_edge = 0;
	selected[0] = 1;
	int x;
	int y;
	printf("Edge  : Weight\n");
  	while (no_edge<max-1) {
    	int min = INF;
    	x = 0;
    	y = 0;
		int i, j;
    	for(i=0; i<max; i++){
    		if(selected[i]){
        		for(j=0; j<max; j++){
        			if(!selected[j] && adj[i][j]){
            			if(min > adj[i][j]){
            				min = adj[i][j];
            				x = i;
            				y = j;
            			}
          			}
        		}
      		}
    	}
    	printf("%c - %c :   %d\n", x+'A', y+'A', adj[x][y]);
    	total_cost += adj[x][y];
    	selected[y] = 1;
    	no_edge++;
	}
	printf("Total Cost of the Minimum Spanning Tree : %d\n", total_cost);
}

int find(int parent[], int i) {
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

void kruskal_min_key(int adj[][max]) {
    int parent[max];
    int total_cost = 0;
    int edge_count, i, j;
    memset(parent, -1, sizeof(parent));
    printf("Edge  : Weight\n");
    for(edge_count=0; edge_count<max-1; edge_count++){
        int min=INF;
        int u=-1, v=-1;
        for(i=0; i<max; i++){
            for(j=0; j<max; j++){
                if(adj[i][j] && adj[i][j] < min){
                    int x = find(parent, i);
                    int y = find(parent, j);
                    if(x != y){
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(u!=-1 && v!=-1){
            int x = find(parent, u);
            int y = find(parent, v);
            parent[y] = x;
            printf("%c - %c :   %d\n", u+'A', v+'A', adj[u][v]);
            total_cost += adj[u][v];
        }
    }
    printf("Total Cost of the Minimum Spanning Tree: %d\n", total_cost);
}

int main(){
	int visited[max] = {0};
	int adj[max][max], i, j;
	int ch, size;
//	printf("Enter the size of the graph : ");
//	scanf("%d", &max);
	printf("\n---- MAIN MENU ----\n");
	printf("1. Enter the values of the graph :\n");
	printf("2. BFS Traversal\n");
	printf("3. DFS Traversal\n");
	printf("4. Prim's Algorithm\n");
	printf("5. Kruskal's Algorithm\n");
	printf("6. Exit\n");
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
				printf("BFS Traversal : ");
				bfs(adj, visited, 0);
				printf("\n");
				break;
			case 3:
				printf("DFS Traversal : ");
				dfs(adj, visited, 0);
				printf("\n");
				break;
			case 4:
				printf("Prim's Algorithm\n");
				prim_min_key(adj);
				break;
			case 5:
				printf("Kruskal's Algorithm\n");
				kruskal_min_key(adj);
				break;
			case 6:
				printf("Thank you");
				break;
			default:
				printf("Invalid Input\n");
		}
	}while(ch!=6);
	return 0;
}

