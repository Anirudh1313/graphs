/*
 * graph.h
 *
 *  Created on: Sep 18, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <limits>
#include <queue>
#include "Vertex.h"

using namespace std;
# define INF 0x3f3f3f3f

class graph
{
public:
	graph(int v);

	void store_edges(vector<Vertex> k);
	void add_edges(int u, int v, Vertex x);
	void add_edges(int u, int v, Vertex x, int weight);

	//find the shortest path and distance of all the vertices from a source vertex,
	//and print the distance and previous vertex of the current vertex.
	void shortestpath(int s);  //dijktras

	//**** this function should be used with "shortestpath" function and the SOURCE VERTEX should be the SAME ONE.
	//store all the previous nodes from the destination node to a vector,
	//and print out all pathway "from the destination vertex to the source vertex"
	void afsp(int i, int j);
	// (or)
	void afsp_r(int i, int j); // print pathway "from 'SOURCE' vertex to the 'DESTINATION' vertex"
	vector<int> straight_path(vector<int> path, int i, int j);  //recursive function


	//find the path and distance form any node to any node.
	void shortestpath_onenode(int i, int j);



	void bfs(int s);                //breadth first search traversal and assign paths for all the vertices
	void bfs_path(int s, int d);    //breadth first search traversal and search one particular vertex, on finding stop the traversal and print the path from source to destination

	void dfs(int s);
	void dfs_until(int s, bool visited[]);

	bool detect_cycle();
	bool detect_cycle_until(int i, bool visited[]);


	bool detect_cycle_BFS();


private:

	int v;
	vector<Vertex> nodes;
	list< pair<int, Vertex> > *adj;

};



#endif /* GRAPH_H_ */
