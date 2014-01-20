// Lesson 5: Shading Models
// Author: Michael Hall
//
// This program is available for download through our website XoaX.net with no guarantees.
// Disclaimer: While we have made every effort to ensure the quality of our content, all risks associated
// with downloading or using this solution, project and code are assumed by the user of this material.
//
// Copyright 2009 XoaX - For personal use only, not for distribution
#include <glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	// Set material properties
	GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0};
	GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat qaBlue[] = {0.0, 0.0, 1.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};

	for (int iIndex = 0; iIndex < 2; ++iIndex) {
		if (iIndex == 0) {
			glShadeModel(GL_FLAT);
		} else {
			glShadeModel(GL_SMOOTH);
		}

		//Set, ambient, diffuse and specular lighting. Set ambient to 20%.
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

		// Draw a sphere
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
			glTranslatef(-0.5 + (float)iIndex, 0.5, -2.0);
			glutSolidSphere(.5, 20, 20);
		glPopMatrix();

		// Turn off diffuse and specular reflection. Set ambient light to full.
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlack);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaBlack);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaFullAmbient);

		// Draw a triangle with one red, green, and blue vertex.
		glBegin(GL_TRIANGLES);
			glMaterialfv(GL_FRONT, GL_AMBIENT, qaRed);
			glVertex3f(-.5 + (float)iIndex, 0.0, -.2);
			glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
			glVertex3f(-.933 + (float)iIndex, -.75, -.2);
			glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlue);
			glVertex3f(-.067 + (float)iIndex, -.75, -.2);
		glEnd();
	}

	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -3.0, 3.0);

	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[]	= {0.0, 1.0, -.5, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}