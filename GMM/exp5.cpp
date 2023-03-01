/*

Given a square object with corrdinate point a = (0, 3) b = (3, 3) c = (3, 0)
d = (0, 0)

perform the following
1. scaling
2. translation with d = 1 x axis and 5 y axis
3. reflection on y axis
4. rotation 90 anti-clockwise

*/

#include <stdio.h>
#include <GL/glut.h>

GLfloat V1X = 0.0f, V1Y = 300.0f, V1Z = 0.0f;
GLfloat V2X = 300.0f, V2Y = 300.0f, V2Z = 0.0f;
GLfloat V3X = 300.0f, V3Y = 0.0f, V3Z = 0.0f;
GLfloat V4X = 0.0f, V4Y = 0.0f, V4Z = 0.0f;

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

void drawSquare()
{
	glBegin(GL_LINE_LOOP);
	glVertex3f(V1X, V1Y, V1Z);
	glVertex3f(V2X, V2Y, V2Z);
	glVertex3f(V3X, V3Y, V3Z);
	glVertex3f(V4X, V4Y, V4Z);
	glEnd();
	glFlush();
}

void transformRotate(float deg, float xaxis, float yaxis, float zaxis)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(deg, xaxis, yaxis, zaxis);
	drawSquare();
}

void transformTranslate(float xaxis, float yaxis, float zaxis)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glTranslatef(xaxis, yaxis, zaxis);
	drawSquare();
}

void transformScale(float xaxis, float yaxis, float zaxis)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glScalef(xaxis, yaxis, zaxis);
	drawSquare();
}

void transformReflect(float xaxis, float yaxis, float zaxis)
{
	glColor3f(0.0f, 0.5f, 0.2f);
	if (xaxis == 1.0)
	{
		V1Y = -V1Y;
		V2Y = -V2Y;
		V3Y = -V3Y;
	}
	if (yaxis == 1.0)
	{
		V1X = -V1X;
		V2X = -V2X;
		V3X = -V3X;
	}
	drawSquare();
}

void myDisplay()
{
	glColor3f(1.0, 1.0, 1.0);
	drawSquare();
	int opt;
	printf("Choose the operation to perform\n"
		   "1. Scaling\n"
		   "2. Translation\n"
		   "3. Reflection\n"
		   "4. Rotation\n"
		   "\n");

	scanf("%d", &opt);

	switch (opt)
	{
	case 1:
		transformScale(1.5, 1.5, 0.0);
		break;
	case 2:
		transformTranslate(200.0, 200.0, 0.0);
		break;
	case 3:
		transformReflect(0.0, 1.0, 0.0);
		break;
	case 4:
		transformRotate(-45.0, 0.0, 0.0, 1.0);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500, 0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("2D TRANSFORMATION of Square");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}