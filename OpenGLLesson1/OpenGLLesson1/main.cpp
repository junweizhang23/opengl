// A Simple OpenGL Project
// Author: Michael Hall
//
// This C++ code and project are provided "as is" without warranty of any kind.
//
// Copyright 2010 XoaX - For personal use only, not for distribution
#include <glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	/*
	glBegin(GL_LINES);
	
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	*/
	//glBegin(GL_LINES);

	glBegin(GL_POLYGON);
	glVertex3f(0.2,0.2,0.0);
	glVertex3f(0.8,0.2,0.0);
	glVertex3f(0.2,0.5,0.0);
	glVertex3f(0.8,0.5,0.0);
	glVertex3f(0.2,0.8,0.0);
	glVertex3f(0.8,0.8,0.0);

	glEnd();
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}