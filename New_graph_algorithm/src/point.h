/*
 * point.h
 *
 *  Created on: Sep 22, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef POINT_H_
#define POINT_H_

class point
{
public:
	point() : x(0), y(0) {}
	point(int x, int y) : x(x), y(y) {}

	int x;
	int y;
};



#endif /* POINT_H_ */
