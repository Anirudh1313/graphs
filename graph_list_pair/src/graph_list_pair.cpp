//============================================================================
// Name        : graph_list_pair.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "graph.h"
using namespace std;

int main()
{

	graph g(7);

	//creating vertices with magnitude, distance and index.
	Vertex v0(10, 0, 0);
	Vertex v1(10, 1, 1);
	Vertex v2(10, 4, 2);
	Vertex v3(10, 2, 3);
	Vertex v4(10, 1, 4);
	Vertex v5(10, 2, 5);
	Vertex v6(10, 3, 6);

	vector<Vertex> a; //vector for vertices

	//storing all vertices to the vector defined in the graph

	//connecting the vertices with edges
//	g.add_edges(0, 1, v1);
//	g.add_edges(0, 2, v2);
//	g.add_edges(4, 1, v1);
//	g.add_edges(1, 3, v3);
//	g.add_edges(2, 3, v3);
//	g.add_edges(2, 6, v6);
//	g.add_edges(3, 6, v6);
//	g.add_edges(6, 5, v6);
//	g.add_edges(5, 4, v4);

//	g.add_edges(5, 2, v2);

	g.add_edges(0, 1, v1, 1);
	g.add_edges(0, 6, v6, 7);
	g.add_edges(0, 2, v2, 2);
	g.add_edges(4, 1, v1, 2);
	g.add_edges(1, 3, v3, 3);
	g.add_edges(2, 3, v3, 5);
	g.add_edges(2, 6, v6, 3);
	g.add_edges(3, 6, v6, 1);
	g.add_edges(6, 5, v6, 2);
	g.add_edges(5, 4, v4, 3);

	a.push_back(v0);
	a.push_back(v1);
	a.push_back(v2);
	a.push_back(v3);
	a.push_back(v4);
	a.push_back(v5);
	a.push_back(v6);
	//creating a vector with all the vertices

	g.store_edges(a);
	cout << v2.dist << "** " << endl;

//	g.shortestpath_onenode(0, 6);
	g.shortestpath(0);
	g.afsp_r(0,6);

	//finds the path from vertex to vertex doesn't care about all other vertices,
	//and stops finding the shortest path of all other vertices on finding the required vertex.

	//g.shortestpath_onenode(0, 4);

	//g.bfs(0);
//	g.bfs_path(0, 4);

//	g.dfs(0);

//	if(g.detect_cycle_BFS())
//		cout << "yes! found a cycle" << endl;
//	else
//		cout << "no! not found any cycle" << endl;



	return 0;
}
