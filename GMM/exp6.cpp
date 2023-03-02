/*
Write a program to perform the following 2D transformation based on the pivot element.
*/

#include <stdio.h>
#include <GL/glut.h>

GLfloat pivot_X = 100, pivot_Y = 200;
GLfloat X = 150, Y = 250;

GLfloat V1X = 0.0f + pivot_X, V1Y = 100.0f + pivot_Y, V1Z = 0.0f;
GLfloat V2X = 100.0f + pivot_X, V2Y = 100.0f + pivot_Y, V2Z = 0.0f;
GLfloat V3X = 100.0f + pivot_X, V3Y = 0.0f + pivot_Y, V3Z = 0.0f;
GLfloat V4X = 0.0f + pivot_X, V4Y = 0.0f + pivot_Y, V4Z = 0.0f;
GLfloat V5X = 50.0f + pivot_X, V5Y = 125.0f + pivot_Y, V5Z = 0.0f;

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.5f, 0.5f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);

	glBegin(GL_LINE_LOOP);
	glVertex3f(-400.0, 0.0, 0.0);
	glVertex3f(400.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, -400.0, 0.0);
	glVertex3f(0.0, 400.0, 0.0);
	glEnd();

	glFlush();
}

void drawPentagon()
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(V1X, V1Y, V1Z);
	glVertex3f(V5X, V5Y, V5Z);
	glVertex3f(V2X, V2Y, V2Z);
	glVertex3f(V3X, V3Y, V3Z);
	glVertex3f(V4X, V4Y, V4Z);
	glEnd();
	glFlush();
}

void drawPivot()
{
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(X, Y);
	glEnd();
	glFlush();
}

void transformTranslate(float xaxis, float yaxis, float zaxis)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(xaxis, yaxis, zaxis);
	drawPentagon();
}

void transformRotate(float deg, float xaxis, float yaxis, float zaxis)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glRotatef(deg, xaxis, yaxis, zaxis);
	transformTranslate(100.0, -400.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	drawPentagon();
}

void transformScale(float xaxis, float yaxis, float zaxis)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glScalef(xaxis, yaxis, zaxis);
	transformTranslate(150.0, 250.0, 0.0);
	drawPentagon();
}

void myDisplay()
{
	glColor3f(1.0, 1.0, 1.0);
	drawPentagon();
	drawPivot();
	printf("Final output: \n");
	transformTranslate(-X, -Y, 0.0);
	transformRotate(90.0, 0.0, 0.0, 1.0);
	transformScale(0.5, 0.5, 0.0);
	transformTranslate(0.0, 0.0, 0.0);
	transformTranslate(500, -300.0, 0.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("2D TRANSFORMATION of pentagon");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}