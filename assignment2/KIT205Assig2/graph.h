#pragma once

typedef struct edge {
	int to_vertex;
	int weight;
} Edge;

typedef struct edgeNode {
	Edge edge;
	struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
	EdgeNodePtr head;
} EdgeList;

typedef struct graph {
	int V;
	EdgeList *edges;
} Graph;

Graph init_graph(int size);
void insert_edge(Graph *self, int vert_num, int to_vertex, int cost);
void floyd(Graph *self, int ** dist, int** next);
void dijkstra(Graph *self, int source, int* dist, int* prev);