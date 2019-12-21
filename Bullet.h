/*
 * Bullet.h
 *
 *  Created on: May 2, 2019
 *      Author: saad
 */

#ifndef BULLET_H_
#define BULLET_H_
#include "MovingObjects.h"
#include "Mushroom.h"
//#include "game.cpp"
class Bullet:public MovingObjects {
public:
	Bullet();
	void draw(){
			DrawLine( posX , posY+15 ,  posX , (posY+=10) + 10, 5 , colors[GRAY] );
	}
	void collision (Mushroom& a){
		a.setLife(a.getLife()-1);
		cout<<"Mushroom hit, life is "<<a.getLife()<<endl;
		//	return mainInt.flagger[posX][posY];
	}
	virtual ~Bullet();
};

#endif /* BULLET_H_ */
