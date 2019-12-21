//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDEGAME_CPP_
#define CENTIPEDEGAME_CPP_
#include "util.h"
#include "Interface.h"
#include <iostream>
#include <string>
//#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
Interface mainInt;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	mainInt.checkCollisions();
	mainInt.draw();
//	if (mainInt.pointCounter > 500){
//		mainInt.changeLevel();
//		mainInt.pointCounter=0;
//	}

//	//Display Score
	DrawString( 50, 60, "Score", colors[MISTY_ROSE]);
	DrawString( 50, 30, to_string(mainInt.endPoints), colors[MISTY_ROSE]);

	//Display Time
	DrawString( 900, 60, "Time", colors[MISTY_ROSE]);
	DrawString( 900, 30, to_string(mainInt.Time()), colors[MISTY_ROSE]);


	//	//Spider
//	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
//

	//mainInt.temptime++;

	mainInt.frames++;
	if (mainInt.frames==FPS)
		mainInt.frames=0;

	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		if (mainInt.flagger[mainInt.player[0].getPosX()-10][mainInt.player[0].getPosY()]!=1)
			mainInt.player[0].move(-10, 0);
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (mainInt.flagger[mainInt.player[0].getPosX()+10][mainInt.player[0].getPosY()]!=1)
			mainInt.player[0].move(+10, 0);

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (mainInt.flagger[mainInt.player[0].getPosX()][mainInt.player[0].getPosY()+10]!=1)
			mainInt.player[0].move(0, +10);

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (mainInt.flagger[mainInt.player[0].getPosX()][mainInt.player[0].getPosY()-10]!=1)
			mainInt.player[0].move(0, -10);

	}





	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	else if (key == 'c'/* c key ASCII*/) {
		mainInt.addPlayer(); // add another player.
		cout<<"c pressed..."<<endl;
	}

	else if (key == ' ' ) //Key for placing the bomb
			{
		//do something if b is pressed

		//if (abs(mainInt.frames - mainInt.temptime) > 15){
		if (mainInt.frames-mainInt.buffer>2){
			mainInt.fireBullet(0);
			cout<<"Bullet fired at frame "<<mainInt.frames<<" at temptime "<<mainInt.temptime<<endl;
		}
		//}
//		if (mainInt.buffer>=2){
//			if ((mainInt.Time() - mainInt.temptime) >=1)
//				mainInt.buffer=0;
//			else
//				cout<<"The temporary time is "<<mainInt.temptime<<endl;
//		else{
	//	}
		cout << "space pressed" << endl;
		mainInt.buffer=mainInt.frames;
}

	else if (key == 'g' || key == 'G' ) //Key for placing the bomb
			{
		//do something if b is pressed

		//if (mainInt.frames - mainInt.temptime > FPS/2)
		if (mainInt.playercount==2)
			mainInt.fireBullet(1);
//		if (mainInt.buffer>=2){
//			if ((mainInt.Time() - mainInt.temptime) >=1)
//				mainInt.buffer=0;
//			else
//				cout<<"The temporary time is "<<mainInt.temptime<<endl;
//		else{
	//	}
		cout << "G pressed" << endl;
//		mainInt.temptime=mainInt.frames;
}

	else if (key
			== 65 || key
			== 97/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		cout<<"Button a pressed..."<<endl;
		if (mainInt.playercount==2){
		cout<<"player 2 move"<<endl;
			mainInt.player[1].move(-10, 0);
		}
		// what to do when left key is pressed...

	} else if (key
			== 'd' /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (mainInt.playercount==2)
			mainInt.player[1].move(+10, 0);
	} else if (key
			== 'w'/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (mainInt.playercount==2)
			mainInt.player[1].move(0, +10);
	}

	else if (key
			== 's'/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (mainInt.playercount==2)
			mainInt.player[1].move(0, -10);
	}

	//glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(mainInt.speed/FPS, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

//	b = new Board(1020, 840); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
//	b->InitalizeBoard(width, height);
//	b->Draw();
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(2000.0/200, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
