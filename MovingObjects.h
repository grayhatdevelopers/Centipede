/*
 * MovingObjects.h
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "DrawingObjects.h"
using namespace std;
class MovingObjects: public DrawingObjects {
protected:
	int direction;
public:
	MovingObjects();
	void move(int, int);
	void collision ();
	virtual ~MovingObjects();
    int getDirection() const;
    void setDirection(int direction);
};

#endif /* MOVINGOBJECTS_H_ */
