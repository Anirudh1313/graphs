/*
 * Vertex.h
 *
 *  Created on: Sep 18, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef VERTEX_H_
#define VERTEX_H_

class Vertex
{
public:
	Vertex(): val(0), dist(0), index(0), path(0) {}
	Vertex(int v, int d, int i): val(v), dist(d), index(i), path(0) {}

	int val;
	int dist;
	int index;
	int path;
};


#endif /* VERTEX_H_ */
