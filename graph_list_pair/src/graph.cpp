/*
 * graph.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#include"graph.h"

graph::graph(int v)
{
	this->v = v;
	adj = new list< pair<int, Vertex> >[v];
	nodes.resize(v);
}

void graph::add_edges(int u, int v, Vertex w)
{
	adj[u].push_back(make_pair(v, w));
//	adj[v].push_back(make_pair(u, w));
}

void graph::add_edges(int u, int v, Vertex x, int weight)
{
	x.dist = weight;
	adj[u].push_back(make_pair(v, x));
}

void graph::store_edges(vector<Vertex> k)
{
	nodes = k;
}

void graph::shortestpath(int s)
{

	//storing the distance and index of the vertices
	set< pair<int, int> > setds;

	vector<int> dist(v, INF);

	 //1.current node    2.previous node
	set< pair<int, int> > path;


	setds.insert(make_pair(0, s));
	dist[s] = 0;

	int prev_node[v];
	prev_node[0] = 0;


	while(!setds.empty())
	{

		pair<int, int> temp = *(setds.begin());

		setds.erase(setds.begin());

//		int d = temp.first;
		int index = temp.second;

		list< pair<int, Vertex> >::iterator it;
		for(it = adj[index].begin(); it != adj[index].end(); it++)
		{
			int i = it->first;
			int weight = it->second.dist;


			if(dist[i] > dist[index] + weight)
			{

				if(dist[i] != INF)
					setds.erase (setds.find(make_pair(dist[i], i)));

				dist[i] = dist[index] + weight;
				//it->second.path = index;
				//nodes[i].path = index;
				prev_node[i] = index;
				//it->second.dist = dist[i];

				path.insert(make_pair(i, index));
				setds.insert(make_pair(dist[i], i));


			}
		}
	}

	cout << "Vertices with the distance from the source node" << endl;
	    cout << "node" << "   " << "dist from " << s << " node    prev-path" << endl;
	for(int i = 0; i < v; i++)
	{
		cout << i << "      " << dist[i] << "                   " << prev_node[i] << endl;
	}

}

void graph::afsp(int i, int j)  //path from reverse (destination to source)
{
	vector<int> path;
	int count = 0;
	int k = j;
	while(k != i)
	{
		path.push_back(k);
		k = nodes[k].path;
		count++;
	}

	cout << "\npath from '" << i << "' to '" << j << "' : ";
	for(int c = 0; c < count; c++)
	{
		cout << path[c];
		if(c != count-1)
			cout << " <- ";
	}

	cout << " <- " << i << "   total distance: " << nodes[j].dist << endl;
}

void graph::afsp_r(int i, int j)  // straight path from source to destination.
{
	vector<int> path;
	int k = j;


	vector<int> n = straight_path(path, i, k);

	n.push_back(j); //push_backing the destination node at last.

	cout << "\npath from '" << i << "' to '" << j << "' : ";
	for(int len = 0; len < n.size(); len++)
	{
		cout << n[len];
		if(len != n.size()-1)
			cout << " -> ";
	}

	cout << "     total distance: " << nodes[j].dist << endl;
}


// ****using recursive function to save the source to destination path while traversing from the destination vertex's path to the source
vector<int> graph::straight_path(vector<int> path, int i, int k)
{
	if(k == i)
		return path;

	k = nodes[k].path;

	path = straight_path(path, i, k);

	path.push_back(k);

	return path;
}

// *** j = destination node  && s = source node *****
void graph::shortestpath_onenode(int s, int j)
{
	set< pair<int, int> > setds;           //storing the distance and index of the vertices

	vector<int> dist(v, INF);              // setting a vector named 'dist' to save all vertices final distance from the source vertex, and initially setting all vertices distance to infinity .

//	 //1.current node    2.previous node
//	set< pair<int, int> > path;


	setds.insert(make_pair(0, s));
	dist[s] = 0;

	int q = 0;
	while(!setds.empty() && q == 0)
	{

		pair<int, int> temp = *(setds.begin());

		setds.erase(setds.begin());

//		int d = temp.first;
		int index = temp.second;

		int prev1[v], prev2[v];


		list< pair<int, Vertex> >::iterator it;
		for(it = adj[index].begin(); it != adj[index].end() && q == 0; it++)
		{
			int i = it->first;
			int weight = it->second.dist;


			if(dist[i] > dist[index] + weight)
			{

				if(dist[i] != INF)   //checking if the vertex is present in the set, if yes erase it
					setds.erase (setds.find(make_pair(dist[i], i)));

				dist[i] = dist[index] + weight;  //modify the longer distance with shorter distance and so on till we get the shortest one
				//it->second.path = index;         //set the new shorter path's previous node to the current node's path as its parent node
				nodes[i].path = index;           //modify parent to our vector storage of all vertices for instant access.
				//nodes[i].dist = dist[i];         //modify distance to our vector storage of all vertices for instant access.
				prev1[i] = index;
//				path.insert(make_pair(i, index));
				setds.insert(make_pair(dist[i], i));  //insert current vertex in set to access its adjacent vertices to traverse
			}
			else if(dist[i] == dist[index] + weight)
			{
				prev2[i] = index;
			}



			if(j == i) //if the current node is the destination node, (if we find the destination node)
			{
				vector<int> path;
				int count = 0;
				int k = j;   // j = destination vertex
				while(k != s)  // s = source
				{
					path.push_back(k);
					k = nodes[k].path;    //setting the parent of the current to current and push_back until we find the source vertex to get the path of source to destination
					count++;
				}

//				int e = path.size()-1;
//
//				for(int r = 0; r < path.size() && e >= 0; r++)
//				{
//					temp = path[r];
//					path[r] = path[e];
//					//cout << "* " << path[e];
//					path[e] = temp;
//
//					e--;
//				}

				cout << "\npath from '" << s << "' to '" << j << "' : ";

				cout << s << " -> ";
				for(int c = count-1; c >= 0; c--)  //printing the path by traversing a vector from back
				{
					cout << path[c];
					if(c != 0)
						cout << " -> ";
				}

				cout << "   total distance: " << dist[j] << endl;

				q = 1; //setting q = 1, will stop the process of going to other nodes, as we determined the required vertex and its path.
			}
		}
	}

//	cout << "\nVertices with the distance from the source node" << endl;
//	    cout << "node" << "   " << "dist from " << s << " node    prev-path" << endl;
//	for(int i = 0; i < v; i++)
//	{
//		cout << i << "      " << dist[i] << "                   " << nodes[i].path << endl;
//	}

}
//
//void graph::bfs(int s)    // showing the traversal from source vertex to all other vertices, and also setting up the paths
//{
//	bool *visited = new bool[v];
//
//	for(int i = 0; i < v; i++)
//	{
//		visited[i] = false;
//	}
//
//	list<int> queue;
//	visited[s] = true;
//	nodes[s].path = 0;
//	queue.push_back(s);
//
//	while(!queue.empty())
//	{
//
//		int k = queue.front();
//		cout << k << " ";
//		queue.pop_front();
//
//		list< pair<int, Vertex> >::iterator it;
//		for(it = adj[k].begin(); it != adj[k].end(); it++)
//		{
//			int i = it->first;
//			if(!visited[i])
//			{
//				visited[i] = true;
//				nodes[i].path = k;
//				it->second.path = k;
//				queue.push_back(i);
//			}
//		}
//	}
//}

void graph::bfs(int s)    // showing the traversal from source vertex to all other vertices, and also setting up the paths
{
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	priority_queue< pair<int, int> > queue;

	visited[s] = true;
//	nodes[s].path = 0;

	queue.push(make_pair(-nodes[s].dist, s));

	while(!queue.empty())
	{

		int k = queue.top().second;
		cout << k << " ";
		queue.pop();

		list< pair<int, Vertex> >::iterator it;
		for(it = adj[k].begin(); it != adj[k].end(); it++)
		{
			int i = it->first;
			if(!visited[i])
			{
				visited[i] = true;
				nodes[i].path = k;
				it->second.path = k;
				queue.push(make_pair(-it->second.dist, i));
			}
		}
	}
}

void graph::bfs_path(int s, int d)   // going node by node WITHOUT considering DISTANCES and finding out the destination vertex from the source vertex.
{
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	visited[s] = true;
	nodes[s].path = 0;
	queue.push_back(s);

	int b = 0;

	while(!queue.empty() && b == 0)
	{

		int k = queue.front();
		cout << k << " ";
		queue.pop_front();

		list< pair<int, Vertex> >::iterator it;
		for(it = adj[k].begin(); it != adj[k].end() && b == 0; it++)
		{
			int i = it->first;
			if(!visited[i])
			{
				visited[i] = true;
				nodes[i].path = k;
				it->second.path = k;
				queue.push_back(i);
			}

			if(i == d)   //if we find the destination vertex, print the path obtain from source to destination
			{

				b = 1;   //stopping the code by setting the b to '1', from not traversing to other vertices

				cout << "\n yes! destination path: " << nodes[d].path << endl;

				vector<int> path;
				int count = 0;
				int k = d;   // d = destination
				while(k != s)  // s = source
				{
					path.push_back(k);
					k = nodes[k].path;    //setting the parent of the current to current and push_back until we find the source vertex to get the path of source to destination
					count++;
				}

				cout << "\npath from '" << s << "' to '" << d << "' : ";

				cout << s << " -> ";
				for(int c = count-1; c >= 0; c--)  //printing the path by traversing a vector from back
				{
					cout << path[c];
					if(c != 0)
						cout << " -> ";
				}
				cout << endl << endl;
//				cout << "   total distance: ! " << nodes[d].dist << endl;

			}
		}
	}
}

void graph::dfs(int s)
{
//	cout << "dd" << endl;
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	dfs_until(s, visited);
}

void graph::dfs_until(int s, bool visited[])
{
	visited[s] = true;
	cout << s << " ";

	list< pair<int, Vertex> >::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		int i = it->first;
		if(!visited[i])
		{
			it->second.path = s;
			nodes[i].path = s;
			dfs_until(i, visited);
		}
	}
}

//detecting cycle in a graph using DFS, which is not successful
bool graph::detect_cycle()
{
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	return detect_cycle_until(0, visited);
}

bool graph::detect_cycle_until(int i, bool visited[])
{
	visited[i] = true;

	list< pair<int, Vertex> >::iterator it;

	for(it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if(!visited[it->first])
		{
			detect_cycle_until(it->first, visited);
		}
		else
		{
			return true;
		}
	}

	return false;
}


//Detecting cycle using BFS which is successful.
bool graph::detect_cycle_BFS()
{
	bool *visited = new bool[v];

	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	queue.push_back(0);

	while(!queue.empty())
	{
		int f = queue.front();
		queue.pop_front();
		visited[f] = true;

		list< pair<int, Vertex> >::iterator it;

		for(it = adj[f].begin(); it != adj[f].end(); it++)
		{
			int i = it->first;

			if(!visited[i])  //while traversing if the encountering vertex is a new one continue traversing
			{
				nodes[i].path = f;
				it->second.path = f;
				queue.push_back(i);
			}
			else if(i != nodes[f].path)   //else if the vertex is an old vertex and not the parent of the current vertex, then it should be the formation point of the cycle
			{
				cout << "connection is at: " << f << " -> (" << i << ") " << endl;
				return true;
			}
		}
	}

	return false;

}
