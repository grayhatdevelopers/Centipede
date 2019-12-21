/*
 * CentiPart.h
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#ifndef CENTIPART_H_
#define CENTIPART_H_
#include "MovingObjects.h"
using namespace std;
class CentiPart: public MovingObjects {
public:
	CentiPart(){

	}
	CentiPart(int x, int y){
			posX=x;
			posY=y;
	}
	void draw(){

	}
	void draw (bool state){
		if (direction==GLUT_KEY_LEFT or direction==GLUT_KEY_RIGHT){
			if (state){
				DrawLine( posX , posY ,  posX-5 , posY+6, 2 , colors[WHITE] );
				DrawLine( posX , posY ,  posX-5 , posY-6, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);
			}
			else{
				DrawLine( posX , posY ,  posX+5 , posY+6, 2 , colors[WHITE] );
				DrawLine( posX , posY ,  posX+5 , posY-6, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);
			}
	}

		if (direction==GLUT_KEY_UP or direction==GLUT_KEY_DOWN){
			if (state){
				DrawLine( posX , posY ,  posX+6 , posY-5, 2 , colors[WHITE] );
				DrawLine( posX , posY ,  posX-6 , posY-5, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);
			}
			else{
				DrawLine( posX , posY ,  posX+6 , posY+5, 2 , colors[WHITE] );
				DrawLine( posX , posY ,  posX-6 , posY+5, 2 , colors[WHITE] );
				DrawCircle(posX,posY,5,colors[GREEN]);
			}
	}


		}


	void move(){
		if (direction==GLUT_KEY_UP){
			posY+=10;
			//olddirection=GLUT_KEY_UP;
		}
		else if (direction==GLUT_KEY_DOWN){
			posY-=10;
			//olddirection=GLUT_KEY_DOWN;
		}
		else if (direction==GLUT_KEY_LEFT){
			posX-=10;
			//olddirection=GLUT_KEY_LEFT;
		}
		else if (direction==GLUT_KEY_RIGHT){
			posX+=10;
			//olddirection=GLUT_KEY_RIGHT;
		}
	}
	virtual ~CentiPart();
};

#endif /* CENTIPART_H_ */
