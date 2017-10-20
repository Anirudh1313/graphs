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

	void add_edge(int u, int v, Vertex x, int weight);

	void dfs(int s);
	void bfs(int s);

	void dijktra(int s);


private:
	int V;
	map <int, list< pair<int, Vertex> > > data;

	void dfs_until(int s, bool visited[]);

};



#endif /* GRAPH_H_ */
