#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int** make_dem(int size, int roughness) {
	int seed = 0;//time(NULL);
	srand(seed);
	int** dem = malloc(size * sizeof *dem);
	for (int x = 0; x < size; x++) {
		dem[x] = malloc(size * sizeof *dem[x]);
		for (int y = 0; y < size; y++) {
			dem[x][y] = -1;
		}
	}
	int r = roughness;

	dem[0][0] =				50 - r / 2 + rand() % r;
	dem[size-1][0] =		50 - r / 2 + rand() % r;
	dem[0][size-1] =		50 - r / 2 + rand() % r;
	dem[size-1][size-1] =	50 - r / 2 + rand() % r;

	for (int step = (size - 1); step > 0; step /= 2) {
		r = r > 1 ? r / 2:r;
		if (r < 1) r = 1;
		for (int cx = 0; cx < (size-1) / step; cx++) {
			for (int cy = 0; cy < (size-1) / step; cy++) {
				int a = dem[cx*step][cy*step];
				int b = dem[cx*step+step][cy*step];
				int c = dem[cx*step][cy*step+step];
				int d = dem[cx*step+step][cy*step+step];

				dem[cx*step + step / 2][cy*step + step / 2] = (a + b + c + d) / 4 + rand() % r - r/2;
				
				dem[cx*step + step / 2][cy*step]		= (a + b) / 2 + rand() % r - r/2;
				dem[cx*step][cy*step + step / 2]		= (a + c) / 2 + rand() % r - r/2;
				dem[cx*step + step][cy*step + step / 2] = (b + d) / 2 + rand() % r-r/2;
				dem[cx*step + step/2][cy*step + step]	= (c + d) / 2 + rand() % r-r/2;
			}
		}
	}
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			dem[x][y] = dem[x][y]<0	? 0 : dem[x][y];
			dem[x][y] = dem[x][y]>99? 99: dem[x][y];
		}
	}
	return dem;
}


int cost_funcA(int diff) {
	int cost = 1;
	if (diff > 0) cost += diff * diff;
	return cost;
}

int cost_funcB(int diff) {
	int cost = 1;
	if (diff > 0)
		cost += diff * diff;
	else
		cost += diff;
	return cost;
}

void build_graph_A(int** dem_array, int size)
{
	Graph dem_graph;//create graph
	//inputs for algo function
	int *dist = malloc(sizeof size); 
	int *prev = malloc(sizeof size);
	int source = 0;

	int row = 0; //for the row
	int column = 0; //for the column
	int edges = 0; //number of edges in vertex
	int edge_cost = 0; //cost of a new edge

	//creating the graph from the 2d DEM array
	for (row; row <= size; row++)
	{
		//looping through array
		for (column; column <= size; column++)
		{
			//assigning array element to a graph vertex
			dem_array[row][column];
			dem_graph.V = row * size + column;
			column++;

		}
		row++;
	}

	//assigning edges
	for (row = 0; row <= size; row++)
	{
		//looping through array
		for (column = 0; column <= size; column++)
		{
			//assigning array element to a graph vertex
			dem_array[row][column];
				//checking for vertex on right edge
				if (dem_graph.V == size - 1)
				{
					edges++;
					edge_cost = cost_funcA(dem_graph.V - dem_array[row-1][column]);

					insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
				}
				//check for vertex left edge
				if (dem_graph.V >= 0)
				{
					edges++;
					edge_cost = cost_funcA(dem_graph.V - dem_array[row+1][column]);

					insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
				}
				//check for vertex on bottom edge
				if (dem_graph.V == size - 1)
				{
					edges++;
					edge_cost = cost_funcA(dem_graph.V - dem_array[row][column-1]);

					insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
				}
				//check for vertex on top edge
				if (dem_graph.V >= 0)
				{
					edges++;
					edge_cost = cost_funcA(dem_graph.V - dem_array[row][column+1]);

					insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
				}
			column++;
		}
		row++;
	}
	
	void dijkstra(dem_graph, source, dist, prev);
}
void build_graph_B(int** dem_array, int size)
{
	Graph dem_graph;//create graph
	int **dist = malloc(sizeof size * size);
	int **next = malloc(sizeof size * size);

	int row = 0; //for the row
	int column = 0; //for the column
	int edges = 0; //number of edges in vertex
	int edge_cost = 0; //cost of a new edge

					   //creating the graph from the 2d DEM array
	for (row; row <= size; row++)
	{
		//looping through array
		for (column; column <= size; column++)
		{
			//assigning array element to a graph vertex
			dem_array[row][column];
			dem_graph.V = row * size + column;
			column++;

		}
		row++;
	}

	//assigning edges
	for (row = 0; row <= size; row++)
	{
		//looping through array
		for (column = 0; column <= size; column++)
		{
			//assigning array element to a graph vertex
			dem_array[row][column];
			//checking for vertex on right edge
			if (dem_graph.V == size - 1)
			{
				edges++;
				edge_cost = cost_funcB(dem_graph.V - dem_array[row - 1][column]);

				insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
			}
			//check for vertex left edge
			if (dem_graph.V >= 0)
			{
				edges++;
				edge_cost = cost_funcB(dem_graph.V - dem_array[row + 1][column]);

				insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
			}
			//check for vertex on bottom edge
			if (dem_graph.V == size - 1)
			{
				edges++;
				edge_cost = cost_funcB(dem_graph.V - dem_array[row][column - 1]);

				insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
			}
			//check for vertex on top edge
			if (dem_graph.V >= 0)
			{
				edges++;
				edge_cost = cost_funcB(dem_graph.V - dem_array[row][column + 1]);

				insert_edge(&dem_graph, dem_graph.V, edges, edge_cost);
			}
			column++;
		}
		row++;
	}
	void floyd(dem_graph, dist, next);
}
void print_2D(int** array2D, int size) {
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (array2D[x][y] >= 0) {
				printf("%2d ", array2D[x][y]);
			}
			else {
				printf("() ");
			}
		}
		printf("\n");
	}
}

void print_2D_ascii(int** array2D, int size) {
	char *shades = " .-:=+*#%@";
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (array2D[x][y] >= 0) {
				char shade = shades[array2D[x][y] * 10 / 100];
				printf("%c%c", shade, shade);
			} else {
				printf("()");
			}
		}
		printf("\n");
	}
}

int main() {
	int dem_roughness = 64;
	int dem_size = 5;
	

	int **dem = make_dem(dem_size,dem_roughness);

	
	printf_s("printing 2d dem\n");
	print_2D(dem, 5);

	//heres the two functions for the algortithms
	//dijkstras
	build_graph_A(dem, dem_size);
	//floyds
	//build_graph_B(dem, dem_size);



	//printf_s("printing 2d ascii dem\n");
	//print_2D_ascii(dem, dem_size);
	//printf("\npress enter to exit\n");
	getchar();
	return 0;
}