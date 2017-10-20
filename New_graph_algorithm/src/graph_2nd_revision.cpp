//============================================================================
// Name        : graph_2nd_revision.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main()
{
	graph g1(13);

	Vertex v0(0, 0, 0, 0);
	Vertex v1(1, 0, 1, 1);
	Vertex v2(2, 0, 4, 2);
	Vertex v3(3, 0, 6, 3);
	Vertex v4(4, 0, 8, 5);
	Vertex v5(5, 0, 1, 5);
	Vertex v6(6, 0, 34, 6);
	Vertex v7(7, 0, -1, -3);
	Vertex v8(8, 0, -4, 10);
	Vertex v9(9, 0, 6, -14);
	Vertex v10(10, 0, 32, -24);
	Vertex v11(11, 0, -15, -64);
	Vertex v12(12, 0, 6, 14);

//	Vertex v0(0, 0, 0, 0);
//	Vertex v1(1, 0, 0, 1);
//	Vertex v2(2, 0, 1, 1);
//	Vertex v3(3, 0, 1, 0);
//
//	Vertex v4(4, 0, 8, 5);
//	Vertex v5(5, 0, 1, 5);
//	Vertex v6(6, 0, 34, 6);
//	Vertex v7(7, 0, -1, -3);
//	Vertex v8(8, 0, -4, 10);
//	Vertex v9(9, 0, 6, -14);
//	Vertex v10(10, 0, 32, -24);
//	Vertex v11(11, 0, -15, -64);
//	Vertex v12(12, 0, 6, 14);


//	g1.add_edge(0, 1, v1, 1); // 0 -> 1
//	g1.add_edge(0, 2, v2, 2); // 0 -> 2
//	g1.add_edge(1, 3, v3, 1); // 1 -> 3
//	g1.add_edge(2, 4, v4, 1); // 2 -> 4
//	g1.add_edge(2, 6, v6, 3); // 2 -> 6
//	g1.add_edge(3, 5, v5, 1); // 3 -> 5

	vector<Vertex> allVert;

	allVert.push_back(v0);
	allVert.push_back(v1);
	allVert.push_back(v2);
	allVert.push_back(v3);
	allVert.push_back(v4);
	allVert.push_back(v5);
	allVert.push_back(v6);
	allVert.push_back(v7);
	allVert.push_back(v8);
	allVert.push_back(v9);
	allVert.push_back(v10);
	allVert.push_back(v11);
	allVert.push_back(v12);

	g1.store_all_nodes(allVert);

		g1.add_edge(v0, v1, 1); // 0 -> 1
		g1.add_edge(v0, v2, 2); // 0 -> 2
		g1.add_edge(v0, v3, 3); // 1 -> 3
		g1.add_edge(v2, v4, 1); // 2 -> 4
		g1.add_edge(v2, v6, 3); // 2 -> 6
		g1.add_edge(v3, v5, 1); // 3 -> 5
		g1.add_edge(v1, v8, 4);
		g1.add_edge(v8, v7, 4);
		g1.add_edge(v7, v9, 4);

		g1.add_edge(v9, v10, 2);   // one way to 10, 11, 12
		//g1.add_edge(v10, v11, 7);

		g1.add_edge(v9, v11, 3);   // 2nd way to 10, 11, 12
		g1.add_edge(v11, v10, 5);

		g1.add_edge(v10, v12, 6);

//	g1.add_edge(v0, v1, 1);
//	g1.add_edge(v0, v2, 1);
//	g1.add_edge(v0, v3, 1);
//
//	g1.add_edge(v1, v3, 1);
//	g1.add_edge(v1, v0, 1);
//	g1.add_edge(v1, v2, 1);
//
//	g1.add_edge(v2, v3, 1);
//	g1.add_edge(v2, v1, 1);
//	g1.add_edge(v2, v0, 1);
//
//	g1.add_edge(v3, v2, 1);
//	g1.add_edge(v3, v0, 1);
//	g1.add_edge(v3, v1, 1);

  cout << "DFS: ";	g1.dfs(v0);  cout << endl;

  cout << "BFS: ";	g1.bfs(v0);  cout << endl;

  //g1.dijktra(0);

  int f = g1.shortest_path_dijktra(0, 12);
  if(f == -2)
  {
	  cout << "destination not found in your graph:  " << endl;
  }
  else
  {
	  cout << "dist: " << f << endl;
  }

  g1.get_all_adj_nodes(0);
//
//	cout << "!!!Spiral primes!!!" << endl; // prints !!!Spiral primes!!!
	return 0;
}
