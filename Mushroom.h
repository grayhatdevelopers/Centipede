/*
 * Mushroom.h
 *
 *  Created on: Apr 30, 2019
 *      Author: saad
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_

#include "util.h"
#include "DrawingObjects.h"
using namespace std;

class Mushroom:public DrawingObjects {
protected:
	int life;
public:
	Mushroom(): life (3){
	}

	void draw (){
		//cout<<"Drawing at "<<posX<<", "<<posY<<endl;
		if (life == 3){
		DrawCircle( this->posX , this->posY ,5,colors[Color]);
		DrawSquare( this->posX-5, this->posY-5, 5, colors[BLACK]);
		DrawSquare( this->posX+1, this->posY-5, 5, colors[BLACK]);
		}
		else if (life == 2){
			DrawCircle( this->posX , this->posY ,5,colors[Color]);
			DrawSquare( this->posX-5, this->posY-5, 5, colors[BLACK]);
			DrawSquare( this->posX+1, this->posY-5, 5, colors[BLACK]);
			DrawSquare( this->posX+1, this->posY+1, 5, colors[BLACK]);
		}
		else if (life == 1){
			DrawCircle( this->posX , this->posY ,5,colors[Color]);
			DrawSquare( this->posX-5, this->posY-5, 5, colors[BLACK]);
			DrawSquare( this->posX+1, this->posY-5, 5, colors[BLACK]);
			DrawSquare( this->posX+1, this->posY+1, 5, colors[BLACK]);
			DrawSquare( this->posX-5, this->posY+1, 5, colors[BLACK]);

		}
	}
	virtual ~Mushroom();
    int getLife() const;
    void setLife(int life);
};

#endif /* MUSHROOM_H_ */
