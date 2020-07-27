#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int n = 0;
int graph[20][20];

void display_graph()
{
	int i, j;
	printf("The adjacent matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void insert_vertex()
{
	int i;
	n = n + 1;
	printf("Inserting new vertex in the graph: \n");
	for(i=1; i<=n; i++)
	{
		graph[i][n] = 0;
		graph[n][i] = 0;
	}
	
	display_graph();
}

void delete_vertex()
{
	n = n - 1;
	printf("Last vertex deleted\n");
	display_graph();
}

void insert_edge()
{
	int s, d;
	int flag = 0;
	printf("Inserting edge in the graph: \n");
	do
	{
		printf("Enter the source: ");
		scanf("%d", &s);
		
		printf("Enter the destination: ");
		scanf("%d", &d);
	
	
		if(s > n || d > n || s <= 0 || d <= 0)
		{
			printf("Invalid choice\n");
			printf("Try again\n");
		}
		else
		{
			if(graph[s][d] != 1 && graph[d][s] != 1)
			{
				graph[s][d] = 1;
				graph[d][s] = 1;
				printf("edge inserted successfully\n");
			}
			else
			{
				printf("edge already exists\n");
			}
			flag = 1;
		}
	}while(flag==0);
	
	display_graph();
}

void delete_edge()
{
	int s, d;
	int flag = 0;
	printf("Deleting edge from the graph: \n");
	do
	{
		printf("Enter the source: ");
		scanf("%d", &s);
		
		printf("Enter the destination: ");
		scanf("%d", &d);
	
	
		if(s > n || d > n || s <= 0 || d <= 0)
		{
			printf("Invalid choice\n");
			printf("Try again\n");
		}
		else
		{
			if(graph[s][d] == 1 && graph[d][s] == 1)
			{
				graph[s][d] = 0;
				graph[d][s] = 0;
				printf("edge deleted successfully\n");
			}
			else
			{
				printf("No such edge exists\n");
			}
			flag = 1;
		}
	}while(flag==0);
	
	display_graph();
	
}

int main()
{
	int source, dest, edge, choice;
	int i;
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	printf("Enter the no. of edges: ");
	scanf("%d", &edge);
	for(i=1; i<=edge; i++)
	{
		printf("Enter the source: ");
		scanf("%d", &source);
		
		printf("Enter the destination: ");
		scanf("%d", &dest);
	
	
		if(source > n || dest > n || source <= 0 || dest <= 0)
		{
			printf("Invalid choice\n");
			i--;
			continue;
		}
		else
		{
			graph[source][dest] = 1;
			graph[dest][source] = 1;
		}
	
	}
	do
	{
		printf("Choose the following:\n");
		printf("1)Insert Vertex 2)Delete Vertex 3)Insert Edge 4)Delete edge 5)Print graph 6)Exit\n");
		scanf("%d", &choice);
		system("cls");
		switch(choice)
		{
			case 1: insert_vertex();
			break;
		
			case 2: delete_vertex();
			break;
			
			case 3: insert_edge();
			break;
			
			case 4: delete_edge();
			break;
			
			case 5: display_graph();
			break;
		
			case 6: printf("Exiting the program\n");
			exit(0);
			break;
		
			default: printf("Invalid choice\n");
		}	
	}while(1);
	
	
}




