/*
 * graph.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: krishnasaianirudhkatamreddy
 */


#include "graph.h"


using namespace std;

graph::graph(int v)
{
	this->V = v;
	for(int i = 0; i < v; i++)
	{
		list< pair<int, Vertex> > l;
		data[i] = l;
	}
}

void graph::add_edge(int u, int v, Vertex x, int w)
{
	x.weight = w;
	map<int, list< pair<int, Vertex> > >::iterator it;
	it =  data.find(u);
//	if(it == data.end())
//	{
//		list< pair<int, Vertex> > l;
//		l.push_back(make_pair(v, x));
//		data[u] = l;
//	}
//	else
	{
		it->second.push_back(make_pair(v, x));
	}
}

void graph::dfs(int s)
{
	bool *visited = new bool[V];

	cout << "dd" << endl;
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	cout << "dd" << endl;
	dfs_until(s, visited);
}

void graph::dfs_until(int s, bool visited[])
{
	cout << "d1" << endl;
	visited[s] = true;
	cout << s << " ";

	list< pair<int, Vertex> >::iterator it;

	for(it = data.find(s)->second.begin(); it != data.find(s)->second.end(); it++)
	{
		if(!visited[it->first])
			dfs_until(it->first, visited);
	}
}

void graph::bfs(int s)
{
	bool *visited = new bool[V];

	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	list< pair<int, Vertex> >::iterator it;

	queue.push_back(s);

	while(!queue.empty())
	{
		int f = queue.front();
		cout << f << " ";
		queue.pop_front();

		for(it = data.find(f)->second.begin(); it != data.find(f)->second.end(); it++)
		{
			int i = it->first;
			if(!visited[i])
				visited[i] = true;
				queue.push_back(i);
		}

	}
}

void graph::dijktra(int s)
{
	vector<int> dist(V, INF);

	set< pair<int, int> > que;

	int path[V];

	que.insert(make_pair(0, s));
	path[s] = 0;
	dist[s] = 0;

	while(!que.empty())
	{
		pair<int, int> temp = *(que.begin());
		que.erase(que.begin());

		int parent = temp.second;

		list< pair<int, Vertex> >::iterator it;


		for(it = data[parent].begin(); it != data[parent].end(); it++)
		{
			int child = it->first;
			int  weight = it->second.weight;

			if(dist[child] > dist[parent] + weight)
			{

				if(dist[child] != INF)
					que.erase(que.find(make_pair(dist[child], child)));



				dist[child] = dist[parent] + weight;
				path[child] = parent;

				que.insert(make_pair(dist[child], child));
			}


		}

	}

	cout << "Vertices with the distance from the source node" << endl;
	    cout << "node" << "   " << "dist from " << s << " node    prev-path" << endl;
	for(int i = 0; i < V; i++)
	{
		cout << i << "      " << dist[i] << "                   " << path[i] << endl;
	}
}
