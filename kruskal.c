#include<stdio.h>
#include<conio.h>
#define max 6
#define INF 99999

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
	printf("\n---- MAIN MENU ----\n");
	printf("1. Enter the values of the graph :\n");
	printf("2. Kruskal's Algorithm\n");
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
				printf("Kruskal's Algorithm\n");
				kruskal_min_key(adj);
				break;
			case 3:
				printf("Thank you");
				break;
			default:
				printf("Invalid Input\n");
		}
	}while(ch!=3);
	return 0;
}

