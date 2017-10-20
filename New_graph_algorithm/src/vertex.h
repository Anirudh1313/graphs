/*
 * vertex.h
 *
 *  Created on: Sep 22, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "point.h"
using namespace std;

class Vertex
{
public:
	Vertex() : index(0), weight(0), co_ordinate(point(0, 0)) {}
	Vertex(int index, int weig, int x, int y) : index(index), weight(weig), co_ordinate(point(x, y)) {}
//	Vertex(const Vertex& other)
//	{
//		*this = other;
//	}
//	~Vertex()
//	{
//		//cout << "destructor called" << endl;
//	}

	int index;
	int weight;
	point co_ordinate;
};


#endif /* VERTEX_H_ */
