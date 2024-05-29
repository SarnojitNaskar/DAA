#include<stdio.h>
#include<conio.h>
#define max 5

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

int main(){
	int visited[max] = {0};
	int adj[max][max], i, j;
	int ch, size;
	printf("\n---- Main Menu ----\n");
	printf("1. Enter the values of the graph :\n");
	printf("2. BFS Traversal\n");
	printf("3. DFS Traversal\n");
	printf("4. Exit\n");
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
				printf("Thank you");
				break;
			default:
				printf("Invalid Input\n");
		}
	}while(ch!=4);
	return 0;
}

