/*
 * CentiHead.h
 *
 *  Created on: May 5, 2019
 *      Author: saad
 */

#ifndef CENTIHEAD_H_
#define CENTIHEAD_H_
#include "CentiPart.h"
using namespace std;

class CentiHead: public CentiPart {
public:
	CentiHead (){

	}
	CentiHead(int x, int y){
		posX=x;
		posY=y;
	}
	void draw (){
		//if (state)
		if (direction==GLUT_KEY_LEFT or direction==GLUT_KEY_RIGHT){
			DrawTriangle( posX, posY+5 , posX, posY-5 , posX+10 , posY, colors[ORANGE] );
			DrawTriangle( posX, posY+5 , posX, posY-5 , posX-10 , posY, colors[ORANGE] );
				//DrawLine( posX , posY ,  posX-5 , posY-6, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);
	}

		if (direction==GLUT_KEY_UP or direction==GLUT_KEY_DOWN){
			DrawTriangle( posX, posY+5 , posX, posY-5 , posX , posY+10, colors[ORANGE] );
			DrawTriangle( posX, posY+5 , posX, posY-5 , posX , posY-10, colors[ORANGE] );
				//DrawLine( posX , posY ,  posX-5 , posY-6, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);	}

	}

	void move(){
		if (direction==GLUT_KEY_LEFT){
			posX-=10;
		}
		else if (direction==GLUT_KEY_RIGHT){
			posX+=10;
		}

		else if (direction==GLUT_KEY_UP){
			posY+=10;
		}
		else if(direction==GLUT_KEY_DOWN){
			posY-=10;
		}

	}

	virtual ~CentiHead();
};

#endif /* CENTIHEAD_H_ */
