/*
 * Player.h
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "MovingObjects.h"
//#include "game.cpp"
using namespace std;
class Player:public MovingObjects {
	int life;
public:

	Player(): life (3){

	}
	void draw(){
		DrawCircle(posX,posY,5,colors[Color]);
	}
	void move (int x, int y){
	if (posX+x<820 && posX + x > 200)
            posX += x;

        //	else if (posX==820)
        //		posX=810;
        //	else if (posX==200)
        //		posX=210;
        if(posY + y < 200 && posY + y > 0)
            posY += y;

        //	else if (posY==0)
        //		posY=10;
        //	else if (posY==840)
        //		posY=830;
    }
    virtual ~Player();
    int getLife() const;
    void setLife(int life);
};

#endif /* PLAYER_H_ */
