/*
 * vertex.h
 *
 *  Created on: Sep 22, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "point.h"

class Vertex
{
public:
	Vertex(): weight(0), index(0), co_ordinate(point(0, 0)) {}
	Vertex(int index, int x, int y) : index(index), weight(0), co_ordinate(point(x, y)) {}

	int weight;
	int index;
	point co_ordinate;
};


#endif /* VERTEX_H_ */
