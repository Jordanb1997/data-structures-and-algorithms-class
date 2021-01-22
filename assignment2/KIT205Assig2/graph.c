#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"

Graph init_graph(int size)
{

	Graph temp;
	temp.V = size;
	temp.edges = malloc(sizeof *temp.edges * temp.V);

	for (int i = 0; i < temp.V; i++)
	{
		temp.edges[i].head = NULL;
	}
	return temp;
}

void insert_edge(Graph *self, int vert_num, int to_vertex,int cost)
{

		EdgeNodePtr new_node = malloc(sizeof *new_node);

		Edge new_edge;
		//put vertex weight assignment here

		new_edge.to_vertex = to_vertex;
		new_edge.weight = cost;

		new_node->edge = new_edge;
		new_node->next = self->edges[vert_num].head;
		self->edges[vert_num].head = new_node;
}
void floyd(Graph *self, int ** dist, int** next)
{
	int row = 0;//set the row
	int column = 0;//set the column

	//initialise the dist array
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < column; y++)
		{
			dist[row][column] = INT_MAX/2;
			column++;
		}
		row++;
	}

	//reset the row and column for next set of loops
	row = 0;
	column = 0;
	//initialise edge weights
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < column; y++)
		{

		}
	}

	//reset the row and column for next set of loops
	row = 0;
	column = 0;
	//set each vertex to 0
	for (int m = 0; m < self->V; m++)
	{
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < column; b++)
			{
				dist[row][column] = 0;
				column++;
			}
			row++;
		}
	}
	//go through the graph to find path
	for (int k = 0; k < self->V; k++)
	{
		for (int i = 0; i < self->V; i++)
		{
			for (int j = 0; j < self->V; j++)
			{
				if (dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

}
void dijkstra(Graph *self, int source, int* dist, int* prev)
{
	//vertex array
	int *q = malloc(sizeof self->V);
	
	//initilasation of the vertex array
	for (int i = 0; i < self->V; i++)
	{
		//initialise the arrays for vertex states
		dist[i] = INT_MAX;
		prev[i] = -1;

		q[i] = self->V;
	}
	dist[source] = 0;
	while (q != NULL)
	{
		//dealing with least distance node
		int u = dist[source];//current vertex
		int v = 0;//vertex from vertex array
		
		for (int j = 0; j < q-1; j++)
		{
			q[j] = q[j+1];
		}

		//for each edge connected to u
		for(int a = 0; a < self->edges; a++)
		{
			for(int b= 0; b > v; b++)
			{
				//set edge weight  then calculate the distance between u and v
				//then move through the vertives
				int edge = self->edges[a].head->edge.weight;
				int alt = dist[u] + edge;
				if (alt < dist[v])
				{
					dist[v] = alt;
					prev[v] = u;
				}
			}
		}	
	}
}

