/*
 * Interface.h
 *
 *  Created on: Apr 30, 2019
 *      Author: saad
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <cstdlib>
#include "util.h"
#include "Player.h"
#include "Mushroom.h"
#include "Bullet.h"
#include "Centipede.h"
using namespace std;
class Interface {


public:

	bool flagger [840][1020];

	int centicount;

	int flag;

	Mushroom* mushrooms;
	int mushcount;
	int mushCol;
	//Spider* spider;
	Player* player;
	int playercount;

	int level;
	int pointCounter;
	int endPoints;
	int speed;
	Bullet* bullets;
	int bullcount;
	int buffer;
	int temptime;

	int frames;

	int GameStartTime;

	bool tens;

	Centipede* centipedes;

	Interface(){
		newGame();
	}

	void newGame(){
		level =1; pointCounter =0; endPoints =0; speed=2000.0;
		flag=1;
		Centipede tempCent(20, 500, 500, GLUT_KEY_RIGHT, 0);
		centicount=0;
		addCentipede(tempCent);
		mushcount=40;
		bullcount=0;
		initializeMushroom();
		mushCol=GREEN;
		//spider = new Spider;
		player = new Player;
		playercount=0;

		player->setPosX(1020/2);
		player->setPosY(100);
		player->setColor(RED);

		bullets= NULL;
		buffer=0;
		temptime=0;

		frames=0;

		tens=0;

		GameStartTime = time(NULL);

		for (int i =200; i<=820; i++)
			flagger[i][840]=1;
		for (int i =200; i<=820; i++)
			flagger[i][0]=1;
		for (int i =0; i<=840; i++)
			flagger[820][i]=1;
		for (int i =0; i<=840; i++)
			flagger[200][i]=1;
	}

	int Time (){
		return time(NULL) - GameStartTime;
	}

	void initializeMushroom(){
		mushrooms = new Mushroom [mushcount];
		srand(time(NULL));
		for (int i=0; i<mushcount; i++){
			bool repeat;
			mushrooms[i].setColor(mushCol);
			cout<<i<<" mushroom made"<<endl;
			do{
			repeat = false;
			mushrooms[i].setPosX(abs(210 + 10*(rand()%61)));
			cout<<mushrooms[i].getPosX()<<" ";
			mushrooms[i].setPosY(abs(10+ 10*(rand()%83)));
			cout<<mushrooms[i].getPosY()<<endl;
			for (int j=0; j<i; j++)
				if (mushrooms[i].getPosX()==mushrooms[j].getPosX() and mushrooms[i].getPosY()==mushrooms[j].getPosY())
					repeat=true;
			}
			while (repeat == true);
		}

	}

	void fireBullet(int number){
		if (bullcount==0){
			bullets = new Bullet;
			bullets->setPosX(player[number].getPosX());
			bullets->setPosY(player[number].getPosY());
			bullcount++;
			cout<<"First bullet created!"<<endl;
		}
		else
		{
			bullcount++;
			Bullet * temparray = new Bullet [bullcount-1];
			for (int i=0; i<bullcount-1; i++){
				temparray[i]=bullets[i];
			}
			bullets = new Bullet[bullcount];
			for (int i=0; i<bullcount-1; i++){
				bullets[i]=temparray[i];
			}
			bullets[bullcount-1].setPosX(player[number].getPosX());
			bullets[bullcount-1].setPosY(player[number].getPosY());
			cout<<"Next bullet created!"<<endl;
		}
	}

	void addMushroom(int x, int y){
		if (mushcount==0){
			mushrooms = new Mushroom;
			mushrooms->setPosX(x);
			mushrooms->setPosY(y);
			mushcount++;
			cout<<"First extra mushroom created!"<<endl;
		}
		else
		{
			mushcount++;
			Mushroom * temparray = new Mushroom [mushcount-1];
			for (int i=0; i<mushcount-1; i++){
				temparray[i]=mushrooms[i];
			}
			mushrooms = new Mushroom[mushcount];
			for (int i=0; i<mushcount-1; i++){
				mushrooms[i]=temparray[i];
			}
			mushrooms[mushcount-1].setPosX(x);
			mushrooms[mushcount-1].setPosY(y);
			cout<<"Next extra mushroom created!"<<endl;
		}
	}
	//template possible
	void removeBullet (int i){
		if (i==bullcount-1 or bullcount==1){
			bullcount--;
			cout<<"Last bullet destroyed!"<<endl;
		}
		else{
			for (int k=i; k<bullcount-1; k++){
				bullets[k]=bullets[k+1];
			}
			bullcount--;
			cout<<"A bullet was destroyed."<<endl;
		}
	}

	void removeMush (int i){
		if (i==mushcount-1 or mushcount==1){
			mushcount--;
//			Bullet * temparray = new Bullet [bullcount];
//			for (int i=0; i<bullcount; i++){
//				temparray[i]=bullets[i];
//			}
//			bullets = new Bullet[bullcount];
//			for (int i=0; i<bullcount-1; i++){
//				bullets[i]=temparray[i];
//			}
			cout<<"Last mushroom destroyed!"<<endl;
		}
		else{
			for (int k=i; k<mushcount-1; k++){
				mushrooms[k]=mushrooms[k+1];
			}
			mushcount--;
			cout<<"A mushroom was destroyed."<<endl;
		}
	}


	void addPlayer(){
		if (playercount!=2){
			playercount=2;
			Player * temparray = new Player [2];
			for (int i=0; i<2; i++){
				temparray[i]=player[i];
			}

			player = new Player[2];
			for (int i=0; i<2; i++){
				player[i]=temparray[i];
			}
			player[1].setPosX(1020/2);
			player[1].setPosY(100);
			player[1].setColor(ORANGE);
		}
	}

	void addCentipede (Centipede &other){
		if (centicount==0){
			cout<<"Into first centipede..."<<endl;
			centipedes = new Centipede;
			cout<<"1..."<<endl;
			centipedes->length = other.length;
			cout<<"2..."<<endl;
			centipedes->body=new CentiPart [other.length];
			//centipedes->head.setColor(other.head.getColor());
			cout<<"3..."<<endl;
			centipedes->head.setDirection(other.head.getDirection());
			cout<<"4..."<<endl;
			centipedes->head.setPosX(other.head.getPosX());
			cout<<"5..."<<endl;
			centipedes->head.setPosY(other.head.getPosY());
			cout<<"6..."<<endl;

			for (int i=0; i<other.length; i++){
			//	centipedes->body[i].setColor(other.body[i].getColor());
				centipedes->body[i].setDirection(other.body[i].getDirection());
				centipedes->body[i].setPosX(other.body[i].getPosX());
				centipedes->body[i].setPosY(other.body[i].getPosY());
				//cout<<"Exit loop.."<<endl;
			}
			centicount++;
			cout<<"First centipede created!"<<endl;
		}
		else
		{
			cout<<"Into NEXT centipede..."<<endl;
			centicount++;
			Centipede* tempcentipedes = new Centipede [centicount-1];
			for (int i=0; i<centicount-1; i++)
			{
				//cout<<"1..."<<endl;
				tempcentipedes[i].length = centipedes[i].length;
				//cout<<"2..."<<endl;
				tempcentipedes[i].body=new CentiPart [centipedes[i].length];
				//centipedes->head.setColor(other.head.getColor());
				//cout<<"3..."<<endl;
				//if ()
				tempcentipedes[i].head.setDirection(centipedes[i].head.getDirection());
				//cout<<"4..."<<endl;
				tempcentipedes[i].head.setPosX(centipedes[i].head.getPosX());
				//cout<<"5..."<<endl;
				tempcentipedes[i].head.setPosY(centipedes[i].head.getPosY());
				cout<<"6..."<<endl;
				for (int j=0; j<centipedes[i].length; j++){
				//	centipedes->body[i].setColor(other.body[i].getColor());
					tempcentipedes[i].body[j].setDirection(centipedes[i].body[j].getDirection());
					tempcentipedes[i].body[j].setPosX(centipedes[i].body[j].getPosX());
					tempcentipedes[i].body[j].setPosY(centipedes[i].body[j].getPosY());
					cout<<"Exit loop.."<<endl;
				}
			}
			centipedes = new Centipede[centicount];
			for (int i=0; i<centicount-1; i++)
			{
			//	cout<<"1..."<<endl;
				centipedes[i].length=tempcentipedes[i].length;
				//cout<<"2..."<<endl;
				centipedes[i].body=new CentiPart [centipedes[i].length];
				//centipedes->head.setColor(other.head.getColor());
			//	cout<<"3..."<<endl;
				centipedes[i].head.setDirection(tempcentipedes[i].head.getDirection());
				//cout<<"4..."<<endl;
				centipedes[i].head.setPosX(tempcentipedes[i].head.getPosX());
			//	cout<<"5..."<<endl;
				centipedes[i].head.setPosY(tempcentipedes[i].head.getPosY());
				//cout<<"6..."<<endl;
				for (int j=0; j<centipedes[i].length; j++){
				//	centipedes->body[i].setColor(other.body[i].getColor());
					centipedes[i].body[j].setDirection(tempcentipedes[i].body[j].getDirection());
					centipedes[i].body[j].setPosX(tempcentipedes[i].body[j].getPosX());
					centipedes[i].body[j].setPosY(tempcentipedes[i].body[j].getPosY());
			//		cout<<"Exit loop.."<<endl;
				}
			}
			centipedes[centicount-1].length = other.length;
		//	cout<<"2..."<<endl;
			centipedes[centicount-1].body=new CentiPart [other.length];
			//centipedes->head.setColor(other.head.getColor());
		//	cout<<"3..."<<endl;
			centipedes[centicount-1].head.setDirection(other.head.getDirection());
	//		cout<<"4..."<<endl;
			centipedes[centicount-1].head.setPosX(other.head.getPosX());
	//		cout<<"5..."<<endl;
			centipedes[centicount-1].head.setPosY(other.head.getPosY());
			cout<<"6..."<<endl;

			for (int i=0; i<other.length; i++){
			//	centipedes->body[i].setColor(other.body[i].getColor());
				centipedes[centicount-1].body[i].setDirection(other.body[i].getDirection());
				centipedes[centicount-1].body[i].setPosX(other.body[i].getPosX());
				centipedes[centicount-1].body[i].setPosY(other.body[i].getPosY());
		//		cout<<"Exit loop.."<<endl;
			}

			cout<<"Next centipede created! (length="<<centipedes[centicount-1].length<<")"<<endl;
			cout<<"There are "<<centicount<<" centipedes in the game."<<endl;
		}
	}

	void draw(){
		//for (int i=0; i<centicount; i++)

		//Centipede[i].draw(frames%2);


//		if (frames==10)
	//			a.move();

		for (int i=210; i<820; i++){
			for (int j=10; j<840; j++)
				flagger[i][j]=0;
		}

		//Create BARRIERS on top, left, right wall


		DrawLine(200, 0, 820, 0, 10, colors[BLUE]);
		DrawLine(200, 0, 200, 840, 10, colors[BLUE]);

		DrawLine(200, 840, 820, 840, 10, colors[BLUE]);
		DrawLine(820, 840, 820, 0, 10, colors[BLUE]);

		DrawLine(205, 200, 815, 200, 2, colors[GRAY]);

		//	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );


//		for (int i=0; i<centicount+1; i++)
//			centipede[i].draw();
  		for (int i=0; i<mushcount; i++){
			mushrooms[i].draw();
			flagger[mushrooms[i].getPosX()][mushrooms[i].getPosY()]=1;
  		}
  		if (playercount==0){
  			player->draw();
  			//flagger[player->getPosX()][player->getPosY()]=1;
  		}
  		else
  			for (int i=0; i<2; i++){
  				player[i].draw();
  				//flagger[player[i].getPosX()][player[i].getPosY()]=1;
  			}

  		if (bullets != NULL){
  	  		for (int i=0; i<bullcount; i++){
  				bullets[i].draw();
  	  		}
  		}

  		if (playercount==0){
			if (tens==1)
			{
					DrawString4( 850, 410, "INSERT COIN TO PLAY", colors[GOLD]);
				if (frames%20==0)
					tens=0;
			}
			else
			{
					DrawString4( 850, 410, "INSERT COIN TO PLAY", colors[BLACK]);
				if (frames%20==0)
					tens=1;
			}
  		}

  		for (int i=0; i<centicount; i++){
  			//cout<<"Drawing centipede #"<<i<<endl;
			centipedes[i].move();
			centipedes[i].draw(frames>FPS/2.0);
			flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()]=1;
			for (int j=0; j<centipedes[i].length; j++)
				flagger[centipedes[i].body[j].getPosX()][centipedes[i].body[j].getPosY()]=1;
  		}

	}
	//template possible
	bool searchMush(int x, int y, int& theOne){
		for (int i=0; i<mushcount; i++)
			if (x==mushrooms[i].getPosX() and y==mushrooms[i].getPosY()){
				theOne=i;
				return true;
			}

		return false;

	}

	bool searchCent(int x, int y, int& theOne, int& from){
		for (int i=0; i<centicount; i++){
			for (int j=0; j<centipedes[i].length; j++){
				if (x==centipedes[i].head.getPosX() and y==centipedes[i].head.getPosY()){
					theOne=-1;
					from=j;
					return true;
				}

				if (x==centipedes[i].body[j].getPosX() and y==centipedes[i].body[j].getPosY()){
					theOne=j;
					from=i;
					return true;
				}
		}
		}
		return false;
	}

	int checkAllSides(int centinumber){
		if (flagger[centipedes[centinumber].head.getPosX()+10][centipedes[centinumber].head.getPosY()]==0){
			return GLUT_KEY_RIGHT;
		}
		else if (flagger[centipedes[centinumber].head.getPosX()-10][centipedes[centinumber].head.getPosY()]==0){
			return GLUT_KEY_LEFT;
		}
		else if (flagger[centipedes[centinumber].head.getPosX()][centipedes[centinumber].head.getPosY()+10]==0){
			return GLUT_KEY_UP;
		}
		return GLUT_KEY_DOWN;
	}

	void checkCollisions(){
		for (int i=0; i<bullcount; i++)
			if (flagger[bullets[i].getPosX()][bullets[i].getPosY()]){
				int TheOne=-1;

				if (searchMush(bullets[i].getPosX(), bullets[i].getPosY(), TheOne))
				{
					bullets[i].collision(mushrooms[TheOne]);
					if (mushrooms[TheOne].getLife()<=0){
						removeMush(TheOne);
						endPoints+=10;
						pointCounter+=10;
					}
					cout<<"Bullet which hit mushroom, DESTROYED."<<endl;
					removeBullet(i);
				}

				int from;
				if (searchCent(bullets[i].getPosX(), bullets[i].getPosY(), TheOne, from))
				{
					cout<<"Centipede "<<from<<"'s part "<<TheOne<<" has been shot!"<<endl;
					if (TheOne==-1){
						cout<<"HEADSHOT!"<<endl;
						addMushroom(centipedes[from].head.getPosX(), centipedes[from].head.getPosY());
						centipedes[from].head.setPosX(centipedes[from].body[0].getPosX());
						centipedes[from].head.setPosY(centipedes[from].body[0].getPosY());
						for (int i=0; i<centipedes[from].length-1; i++){
							centipedes[from].body[i].setPosX(centipedes[from].body[i+1].getPosX());
							centipedes[from].body[i].setPosY(centipedes[from].body[i+1].getPosY());
						}
						centipedes[from].length--;
						cout<<"Exit sec;"<<endl;

					}
					else{
						cout<<"Creating new copy centipede......"<<endl;
						Centipede tempCent (TheOne, centipedes[from]);
						if (TheOne!=centipedes[from].length-1){
						cout<<"Adding centipede to database..."<<endl;
						addCentipede (tempCent);
						cout<<"Decreasing original length..."<<endl;
						centipedes[from].length=(TheOne-1);
						cout<<"Adding mushroom in that place..."<<endl;
						addMushroom(bullets[i].getPosX(), bullets[i].getPosY());
						}
						else
							cout<<"Tail hit, so no new centipede made."<<endl;
					}
					endPoints+=50;
					pointCounter+=50;
					cout<<"Bullet which hit centipede, DESTROYED."<<endl;
					removeBullet(i);
				}

				if (bullets[i].getPosY()>830){
					cout<<"Bullet which reached board end, DESTROYED."<<endl;
					removeBullet(i);
				}
			}





		for (int i=0; i<centicount; i++){
			if (centipedes[i].getDirection()==GLUT_KEY_UP and flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()+10]==1){
				cout<<"There is something above!"<<endl;
				centipedes[i].setDirection(GLUT_KEY_LEFT);
				if (flagger[centipedes[i].head.getPosX()-10][centipedes[i].head.getPosY()]==1)
					centipedes[i].setDirection(checkAllSides(i));
			}
			else if (centipedes[i].getDirection()==GLUT_KEY_DOWN and flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()-10]==1){
				cout<<"There is something below!"<<endl;
				centipedes[i].setDirection(GLUT_KEY_RIGHT);
				if (flagger[centipedes[i].head.getPosX()+10][centipedes[i].head.getPosY()]==1)
					centipedes[i].setDirection(checkAllSides(i));
			}
			else if (centipedes[i].getDirection()==GLUT_KEY_LEFT and flagger[centipedes[i].head.getPosX()-10][centipedes[i].head.getPosY()]==1){
				cout<<"There is something on the left!"<<endl;
				centipedes[i].setDirection(GLUT_KEY_DOWN);
				if (flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()-10]==1)
					centipedes[i].setDirection(checkAllSides(i));
				else{
					centipedes[i].move();
					centipedes[i].setDirection(GLUT_KEY_RIGHT);
				}

			}
			else if (centipedes[i].getDirection()==GLUT_KEY_RIGHT and flagger[centipedes[i].head.getPosX()+10][centipedes[i].head.getPosY()]==1){
				cout<<"There is something on the right!"<<endl;

				if (centipedes[i].head.getPosY()<200){
					centipedes[i].setDirection(GLUT_KEY_UP);
					if (flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()+10]==1)
						centipedes[i].setDirection(checkAllSides(i));
				}
				else{
					centipedes[i].setDirection(GLUT_KEY_DOWN);
					if (flagger[centipedes[i].head.getPosX()][centipedes[i].head.getPosY()-10]==1)
						centipedes[i].setDirection(checkAllSides(i));
					else{
						centipedes[i].move();
						centipedes[i].setDirection(GLUT_KEY_LEFT);
					}
				}
				//cout<<"Direction set to up! ("<<GLUT_KEY_UP<<")"<<endl;
			}
		}

			if (player[0].getPosX()==1 and player[0].getPosY()==1)
				player[0].setLife(player[0].getLife()-1);
			if (playercount==2){
				if (player[1].getPosX()==1 and player[1].getPosY()==1)
					player[1].setLife(player[1].getLife()-1);
		}
		//cout<<"ALL CLEAR!!!"<<endl;
	}

	void changeLevel(){
		level++;
		speed+=100;
		mushcount+=10;
		centicount++;
	}

	virtual ~Interface();
};

#endif /* INTERFACE_H_ */
