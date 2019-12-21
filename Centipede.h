/*
 * Centipede.h
 *
 *  Created on: May 5, 2019
 *      Author: saad
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_
#include "MovingObjects.h"
#include "CentiPart.h"
#include "CentiHead.h"
using namespace std;

class Centipede:public MovingObjects {
public:
	int length;
	CentiHead head;
	CentiPart *body;

	int getDirection(){
		return head.getDirection();
	}

	Centipede (): length(0), head(0, 0), body(NULL){

	}
	Centipede(int len, int x, int y, int dir, int number): length(len), head(x, y){
		direction=dir;
		posX=x;
		posY=y;

		if (length!=0)
			body = new CentiPart[length];
		else
			body=NULL;
		head.setPosX(x);
		head.setPosY(y);
		head.setDirection(direction);
		if (number==0)
		{
			for (int i=0; i<length;i++){
				body[i].setPosX(x-(10*(i+1)));
				body[i].setPosY(y);
				body[i].setDirection(direction);
			}

		}
		else
		{
			for (int i=0; i<length;i++){
				body[i].setPosX(x+(10*(i+1)));
				body[i].setPosY(y);
			}
		}
		cout<<"Centipede created at point ("<<posX<<", "<<posY<<")!"<<endl;
	}

	void move (){

		int tempx=head.getPosX();
		int tempy=head.getPosY();

		head.move();
			for (int i=length-1; i>0; i--){
				body[i].setPosX(body[i-1].getPosX());
				body[i].setPosY(body[i-1].getPosY());
			}
			body[0].setPosX(tempx);
			body[0].setPosY(tempy);

		}

	Centipede(int index, Centipede& other){
		if (index==other.length-1){
			other.length--;
			cout<<"Tail hit, length decreased!"<<endl;
		}
		else{
			cout<<"Creating new centipede with copied values from the last..."<<endl;
			posX=other.body[index+1].getPosX();
			posY=other.body[index+1].getPosY();
			head.setPosX(other.body[index+1].getPosX());
			head.setPosY(other.body[index+1].getPosY());
			setDirection(other.getDirection());

			length=other.length - index - 1;
			cout<<"Setting the body!"<<endl;
		if (length>0){
			body = new CentiPart [length];
			for (int i=0, j=index+2; i<length; i++)
				body[i]=other.body[j];
			}
		else
			body = NULL;
		}
	}

	void draw(int state){
		//cout<<"Drawing CentiBoi..."<<endl;
		head.draw();
		for (int i=0; i<length; i++)
			body[i].draw(state);
	}

	void setDirection(int dir) {
		head.setDirection(dir);
		for (int i=0; i<length; i++){
			body[i].setDirection(dir);

		}
	}

	void draw(){

	}
	void shrink(int i){

	}

	virtual ~Centipede();
};

#endif /* CENTIPEDE_H_ */
