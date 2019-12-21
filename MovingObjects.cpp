/*
 * MovingObjects.cpp
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#include "MovingObjects.h"

MovingObjects::MovingObjects() {
	// TODO Auto-generated constructor stub

}

int MovingObjects::getDirection() const
{
    return direction;
}

void MovingObjects::setDirection(int direction)
{
    this->direction = direction;
}

MovingObjects::~MovingObjects() {
	// TODO Auto-generated destructor stub
}

