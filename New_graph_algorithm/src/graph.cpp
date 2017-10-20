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
		list< pair<int, Vertex> > *fourWayList;
		fourWayList = new list< pair<int, Vertex> >[4];  // 1 = N E   2 = N W    3 = S W    4 = S E
		data[i] = fourWayList;
	}
	nodes.resize(v);
}

void graph::store_all_nodes(vector<Vertex> allVertices)
{
	nodes = allVertices;
}

void graph::add_edge(Vertex source_Node, Vertex connect_Node, int edge_dist)
{
	connect_Node.weight = edge_dist;
	map<int, list< pair<int, Vertex> >*>::iterator it;
	it = data.find(source_Node.index);
//	if(it == data.end())
//	{
//		list< pair<int, Vertex> > l;
//		l.push_back(make_pair(v, x));
//		data[u] = l;
//	}
//	else
	{
		int x1 = source_Node.co_ordinate.x;
		int y1 = source_Node.co_ordinate.y;
		int x2 = connect_Node.co_ordinate.x;
		int y2 = connect_Node.co_ordinate.y;

		list< pair<int, Vertex> > *p = it->second;

		if(x2 >= x1 && y2 > y1)
		{
			p[0].push_back(make_pair(connect_Node.index, connect_Node));

		}
		else if(x2 < x1 && y2 >= y1)
		{
			p[1].push_back(make_pair(connect_Node.index, connect_Node));

		}
		else if(x2 <= x1 && y2 < y1)
		{
			p[2].push_back(make_pair(connect_Node.index, connect_Node));
		}
		else if(x2 > x1 && y2 <= y1)
		{
			p[3].push_back(make_pair(connect_Node.index, connect_Node));
		}
	}
}

void graph::get_all_adj_nodes(int n)
{
	list< pair<int, Vertex> >::iterator it;
	for(int i = 0; i < 4; i++)
	{
		for(it = data[n][i].begin(); it != data[n][i].end(); it++)
		{
			cout << it->first << " -> ";
			//if(i == 3 && it+1 != nullptr) cout << " -> ";
		}
	}
}


void graph::dfs(Vertex s)
{
	bool *visited = new bool[V];

	//cout << "dd" << endl;
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	//cout << "dd" << endl;
	dfs_until(s, visited);
}

void graph::dfs_until(Vertex s, bool visited[])
{
	//cout << "d1" << endl;
	visited[s.index] = true;
	cout << s.index << " ";

	list< pair<int, Vertex> >::iterator it;
	for(int i = 0; i < 4; i++)   //it goes in anti clock wise from 0 to 360 degrees
	{
		for(it = data.find(s.index)->second[i].begin(); it != data.find(s.index)->second[i].end(); it++)
		{
			//cout << it->first << endl;
			if(!visited[it->first])
				dfs_until(nodes[it->first], visited);
		}
	}
}

void graph::bfs(Vertex s)
{
	bool *visited = new bool[V];

	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	list< pair<int, Vertex> >::iterator it;

	queue.push_back(s.index);

	while(!queue.empty())
	{
		int f = queue.front();
		cout << f << " ";
		queue.pop_front();

		for(int i = 0; i < 4; i++)
		{
			for(it = data.find(f)->second[i].begin(); it != data.find(f)->second[i].end(); it++)
			{
				int i = it->first;
				if(!visited[i])
				{
					visited[i] = true;
					queue.push_back(i);
				}
			}
		}

	}
}

//void graph::dijktra(Vertex s)
//{
//	vector<int> dist(V, INF);
//
//	set< pair<int, Vertex> > que;
//
//	int path[V];
//
////	int index = s.index;
////	int weight = s.weight;
////	int x_c = s.co_ordinate.x;
////	int y_c = s.co_ordinate.y;
////	Vertex s1(index, weight, x_c, y_c);
//	que.insert(make_pair(0, s));
//
//	path[s.index] = 0;
//	dist[s.index] = 0;
//
//	while(!que.empty())
//	{
//		pair<int, Vertex> temp = *(que.begin());
//		que.erase(que.begin());
//
//		Vertex parent = temp.second;
//
//		list< pair<int, Vertex> >::iterator it;
//
//		for(int i = 0; i < 4; i++)
//		{
//			for(it = data[parent.index][i].begin(); it != data[parent.index][i].end(); it++)
//			{
//				int child = it->first;
//				int weight = it->second.weight;
//
//				if(dist[child] > dist[parent.index] + weight)
//				{
//
//					if(dist[child] != INF)
//						que.erase(que.find(make_pair(dist[child], nodes[child])));
//
//
//
//					dist[child] = dist[parent.index] + weight;
//					path[child] = parent.index;
//
//					que.insert(make_pair(dist[child], nodes[child]));
//				}
//			}
//		}
//	}
//
//	cout << "Vertices with the distance from the source node" << endl;
//	cout << "node" << "   " << "dist from " << s.index << " node    prev-path" << endl;
//	for(int i = 0; i < V; i++)
//	{
//		cout << i << "      " << dist[i] << "                   " << path[i] << endl;
//	}
//}

void graph::dijktra(int s)
{
	vector<int> dist(V, INF);

	set< pair<int, int> > que;

	int path[V];

//	int index = s.index;
//	int weight = s.weight;
//	int x_c = s.co_ordinate.x;
//	int y_c = s.co_ordinate.y;
//	Vertex s1(index, weight, x_c, y_c);
	que.insert(make_pair(0, s));

	path[s] = 0;
	dist[s] = 0;

	while(!que.empty())
	{
		pair<int, int> temp = *(que.begin());
		que.erase(que.begin());

		int parent = temp.second;

		list< pair<int, Vertex> >::iterator it;

		for(int i = 0; i < 4; i++)
		{
			for(it = data[parent][i].begin(); it != data[parent][i].end(); it++)
			{
				int child = it->first;
				int weight = it->second.weight;

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
	}

	cout << "Vertices with the distance from the source node" << endl;
	cout << "node" << "   " << "dist from " << s << " node    prev-path" << endl;
	for(int i = 0; i < V; i++)
	{
		cout << i << "      " << dist[i] << "                   " << path[i] << endl;
	}
}

int graph::shortest_path_dijktra(int s, int d)     //my own algorithm by using four queue's for four co-ordinates
{
	vector<int> dist(V, INF);

	set< pair<int, int> > queue;  // (dist, index)

	//set< pair<int, int> > que2;

	list<Vertex> l2;

	int path[V];
	queue.insert(make_pair(0, s));


	dist[s] = 0;
	path[s] = -1;

	while(!queue.empty() || !l2.empty())
	{
		pair<int, int> temp = *(queue.begin());
		queue.erase(queue.begin());

		int ind = temp.second;

		list< pair<int, Vertex> >::iterator it;

		int x1 = nodes[ind].co_ordinate.x;
		int y1 = nodes[ind].co_ordinate.y;

		int x2 = nodes[d].co_ordinate.x;
		int y2 = nodes[d].co_ordinate.y;

		if(x2 >= x1 && y2 > y1)     // 1
		{
			//cout << "1* " << endl;
			for(it = data[ind][0].begin(); it != data[ind][0].end(); it++)
			{
				int c_i = it->first;
				int weight = it->second.weight;

				if(dist[c_i] > dist[ind] + weight)
				{
					if(dist[c_i] != INF)
						queue.erase(queue.find(make_pair(dist[c_i], c_i)));

					dist[c_i] = dist[ind] + weight;
					path[c_i] = ind;
					queue.insert(make_pair(dist[c_i], c_i));
					//cout << "** " << c_i << " q size: " << queue.size() << endl;
				}

				if(c_i == d)
				{
					int i = c_i;
					cout << path[c_i] << " shortest path: ";

					cout << c_i << " -> ";
					while(path[i] != -1)
					{
						cout << path[i] << " -> ";
						i = path[i];
					}

					cout << "found the destination    1total distance: " << dist[c_i] << endl;
					return dist[c_i];
				}
			}


			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][1].begin(); it != data[ind][1].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][3].begin(); it != data[ind][3].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

		}
		else if (x2 < x1, y2 >= y1)  // 2
		{
			//cout << "2* " << endl;

			for(it = data[ind][1].begin(); it != data[ind][1].end(); it++)
			{
				int c_i = it->first;
				int weight = it->second.weight;

				if(dist[c_i] > dist[ind] + weight)
				{
					if(dist[c_i] != INF)
						queue.erase(queue.find(make_pair(dist[c_i], c_i)));

					dist[c_i] = dist[ind] + weight;
					path[c_i] = ind;
					queue.insert(make_pair(dist[c_i], c_i));
				}
				cout << "!! " << c_i << endl;
				if(c_i == d)
				{

					int i = c_i;
					cout << c_i << " -> ";
					while(path[i] != -1)
					{
						cout << path[i] << " -> ";
						i = path[i];
					}

					cout << "found the destination    2total distance: " << dist[c_i] << endl;
					return dist[c_i];
				}
			}

			for(it = data[ind][3].begin(); it != data[ind][3].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][0].begin(); it != data[ind][0].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][1].begin(); it != data[ind][1].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}
		}
		else if (x2 <= x1 && y2 < y1)    // 3
		{
			//cout << "3* " << endl;
			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
				int c_i = it->first;
				int weight = it->second.weight;

				if(dist[c_i] > dist[ind] + weight)
				{
					if(dist[c_i] != INF)
						queue.erase(queue.find(make_pair(dist[c_i], c_i)));

					dist[c_i] = dist[ind] + weight;
					path[c_i] = ind;
					queue.insert(make_pair(dist[c_i], c_i));
				}

				if(c_i == d)
				{
					int i = c_i;
					cout << c_i << " -> ";
					while(path[i] != -1)
					{
						cout << path[i] << " -> ";
						i = path[i];
					}

					cout << "found the destination    3total distance: " << dist[c_i] << endl;
					return dist[c_i];
				}
			}

			for(it = data[ind][0].begin(); it != data[ind][0].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][1].begin(); it != data[ind][1].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][3].begin(); it != data[ind][3].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

		}
		else   // 4
		{
			//cout << "4* " << endl;
			for(it = data[ind][3].begin(); it != data[ind][3].end(); it++)
			{
				int c_i = it->first;
				int weight = it->second.weight;

				if(dist[c_i] > dist[ind] + weight)
				{
					if(dist[c_i] != INF)
						queue.erase(queue.find(make_pair(dist[c_i], c_i)));

					dist[c_i] = dist[ind] + weight;
					path[c_i] = ind;
					queue.insert(make_pair(dist[c_i], c_i));
				}

				if(c_i == d)
				{
					int i = c_i;
					cout << c_i << " -> ";
					while(path[i] != -1)
					{
						cout << path[i] << " -> ";
						i = path[i];
					}

					cout << "found the destination    4total distance: " << dist[c_i] << endl;
					return dist[c_i];
				}
			}

			for(it = data[ind][3].begin(); it != data[ind][3].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][1].begin(); it != data[ind][1].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][0].begin(); it != data[ind][0].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

			for(it = data[ind][2].begin(); it != data[ind][2].end(); it++)
			{
//				que2.insert(make_pair(dist[]))
				l2.push_back(it->second);
				path[it->first] = ind;
			}

		}

		if(queue.empty())
		{

			Vertex vend = l2.back();
			int l_ind = vend.index;    //going to other sided stored nodes in REVERSE OREDER
			l2.pop_back();

			int prev = path[l_ind];

			//cout << "bbb " << l2.size() << endl;
			//cout << "prev dist: " << dist[prev] << " prev id: " << prev << " current id " << l_ind << " current weight: " << vend.weight << endl;


			dist[l_ind] = dist[prev] + vend.weight;

			if(l_ind == d)
			{
				int i = d;
				cout << d << " -> ";
				while(path[i] != -1)
				{
					cout << path[i] << " -> ";
					i = path[i];
				}

				cout << "\ndestination found   distance: " << dist[l_ind] << endl;
				return dist[l_ind];
			}

			queue.insert(make_pair(dist[l_ind], l_ind));
			//cout << "!!!!! U: " << l_ind << endl;
		}
		//for(it = data)


	}

	return -2;
}
