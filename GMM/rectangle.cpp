#include <GL/glut.h>
#include <GL/gl.h>

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5, 0.4);
	glVertex2f(-0.5, -0.4);
	glVertex2f(0.5, -0.4);
	glVertex2f(0.5, 0.4);
	glEnd();

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Rectangle in OpenGL");
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}