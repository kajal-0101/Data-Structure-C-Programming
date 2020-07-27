#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int n = 0;
int graph[20][20];

void display_graph()
{
	int i, j;
	printf("The adjacent matrix is:\n");
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
	for(i=1; i<=n; i++)
	{
		graph[i][n] = 0;
		graph[n][i] = 0;
	}
	printf("Vertex inserted succesfully\n");
	display_graph();
}

void delete_vertex()
{
	n = n - 1;
	printf("Vertex deleted successfully\n");
	display_graph();
}

void insert_edge()
{
	int s, d;
	int flag = 0;
	do
	{
		printf("Enter the source: ");
		scanf("%d", &s);
		
		printf("Enter the destination: ");
		scanf("%d", &d);
		
		if(s > n || d > n || s <= 0 || d <= 0)
		{
			printf("Invalid choice\n");
		}
		else
		{
			if(graph[s][d] == 1)
			{
				printf("Edge already exists!\n");
			}
			else
			{
				graph[s][d] = 1;
				printf("Edge Inserted successfully\n");
			}
			flag = 1;
			display_graph();
		}
	}while(flag == 0);
}

void delete_edge()
{
	int s, d;
	int flag = 0;
	do
	{
		printf("Enter the source: ");
		scanf("%d", &s);
		
		printf("Enter the destination: ");
		scanf("%d", &d);
		
		if(s > n || d > n || s <= 0 || d <= 0)
		{
			printf("Invalid choice\n");
		}
		else
		{
			if(graph[s][d] != 1)
			{
				printf("Edge does not exist!\n");
			}
			else
			{
				graph[s][d] = 0;
				printf("Edge deleted successfully\n");
			}
			flag = 1;
			display_graph();
		}
		
	}while(flag == 0);
}

int main()
{
	int source, dest, edge, choice;
	int i;
	
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	
	printf("Enter the no. of edges: ");
	scanf("%d", &edge);
	
	for(i=1; i<=n; i++)
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
		}
	}
	
	do
	{
		printf("Choose from the following: ");
		printf("1)Insert vertex 2)Delete vertex 3)Insert edge 4)Delete edge 5) Print graph 6)Exit\n");
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
			
			case 5: printf("Exiting from the program\n");
			display_graph();
			break;
			
			case 6: exit(0);
			break;
			
			default: printf("Invalid choice\n");
		}
	}while(1);
	return 0;
}
