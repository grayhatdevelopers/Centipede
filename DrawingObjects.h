/*
 * DrawingObjects.h
 *
 *  Created on: Apr 30, 2019
 *      Author: saad
 */

#ifndef DRAWINGOBJECTS_H_
#define DRAWINGOBJECTS_H_
//#include <iostream>
//#include <string>
#include "util.h"
using namespace std;

class DrawingObjects {
protected:
	int posX;
	int posY;
	int Color;
public:
	DrawingObjects();
	virtual void draw()=0;
    int getColor() const;
    int getPosX() const;
    int getPosY() const;
    void setColor(int Color);
    void setPosX(int posX);
    void setPosY(int posY);
    virtual ~DrawingObjects();

};

#endif /* DRAWINGOBJECTS_H_ */
