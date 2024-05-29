#include<stdio.h>
#include<conio.h>
#define max 6
#define INF 99999

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

int main(){
	int visited[max] = {0};
	int adj[max][max], i, j;
	int ch, size;
	printf("\n---- MAIN MENU ----\n");
	printf("1. Enter the values of the graph :\n");
	printf("2. Prim's Algorithm\n");
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
				printf("Prim's Algorithm\n");
				prim_min_key(adj);
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

