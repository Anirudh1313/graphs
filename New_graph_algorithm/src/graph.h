/*
 * graph.h
 *
 *  Created on: Sep 22, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include "vertex.h"
#include <map>
#include <list>
#include <queue>
#include <set>

# define INF 0x3f3f3f3f


using namespace std;

class graph
{
public:
	graph() : V(0) {}
	graph(int v);

	void add_edge(Vertex source_Node, Vertex connect_Node, int edge_dist);
//	void add_edge(Vertex source_Node, Vertex connect_Node, double edge_dist);

	void dfs(Vertex s);
	void bfs(Vertex s);

	void store_all_nodes(vector<Vertex> allVertices);

	//void dijktra(Vertex s);

	void dijktra(int s);

	int shortest_path_dijktra(int s, int d);
	void get_all_adj_nodes(int n);


private:
	int V;
	map <int, list< pair<int, Vertex> >*> data;
	vector<Vertex> nodes;

	void dfs_until(Vertex s, bool visited[]);

};



#endif /* GRAPH_H_ */
