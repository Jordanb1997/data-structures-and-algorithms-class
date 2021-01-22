#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void pagerank(Graph g)
{

}

void main()
{
	Graph g;

	scanf_s("%d", &g.V);

	g.edges = malloc(sizeof *g.edges * g.V);

	for (int i = 0; i < g.V; i++)
	{
		int  out_edges;

		scanf_s("%d", &out_edges);

		g.edges[i].head = NULL;

		for (int j = 0; j < out_edges; j++)
		{
			EdgeNodePtr new_node = malloc(sizeof *new_node);
			int to_vertex;
			int weight;
			Edge new_edge;
			scanf_s("%d,%d", &to_vertex, &weight);

			new_edge.to_vertex = to_vertex;
			new_edge.weight = weight;

			new_node->edge = new_edge;
			new_node->next = g.edges[i].head;
			//g.edges[i].head = new_node.;

		}
	}
}