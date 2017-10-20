//============================================================================
// Name        : graph_2nd_revision.cpp
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
	graph g1(7);

	Vertex v0(0, 0, 0);
	Vertex v1(1, 1, 1);
	Vertex v2(2, 2, 2);
	Vertex v3(3, 3, 3);
	Vertex v4(4, 4, 4);
	Vertex v5(5, 5, 5);
	Vertex v6(6, 6, 6);

	g1.add_edge(0, 1, v1, 1); // 0 -> 1
	g1.add_edge(0, 2, v2, 2); // 0 -> 2
	g1.add_edge(1, 3, v3, 1); // 1 -> 3
	g1.add_edge(2, 4, v4, 1); // 2 -> 4
	g1.add_edge(2, 6, v6, 3); // 2 -> 6
	g1.add_edge(3, 5, v5, 1); // 3 -> 5


	//g1.bfs(0);

	g1.dijktra(0);
//
//	cout << "!!!Spiral primes!!!" << endl; // prints !!!Spiral primes!!!
	return 0;
}
