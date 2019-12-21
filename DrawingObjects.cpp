/*
 * DrawingObjects.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: saad
 */

#include "DrawingObjects.h"

DrawingObjects::DrawingObjects() {
	// TODO Auto-generated constructor stub

}

int DrawingObjects::getColor() const
{
    return Color;
}

int DrawingObjects::getPosX() const
{
    return posX;
}

int DrawingObjects::getPosY() const
{
    return posY;
}

void DrawingObjects::setColor(int Color)
{
    this->Color = Color;
}

void DrawingObjects::setPosX(int posX)
{
    this->posX = posX;
}

void DrawingObjects::setPosY(int posY)
{
    this->posY = posY;
}

DrawingObjects::~DrawingObjects() {
	// TODO Auto-generated destructor stub
}

