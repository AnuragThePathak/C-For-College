/*

Given a square object with corrdinate point a = (0, 3) b = (3, 3) c = (3, 0)
d = (0, 0)

perform the following
1. scaling
2. translation with d = 1 x axis and 5 y axis
3. reflection on y axis
4. rotation 90 anti-clockwise

*/

#include <GL/glut.h>
#include <stdio.h>

void initGL()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-10, 10, -10, 10);
}

void original()
{
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(0.0f, 3.0f);
   glVertex2f(3.0f, 3.0f);
   glVertex2f(3.0f, 0.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
}

void translate()
{
   glTranslatef(1.0f, 5.0f, 0.0f);
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.0f, 3.0f);
   glVertex2f(3.0f, 3.0f);
   glVertex2f(3.0f, 0.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
}

void scale()
{
   glScalef(2.0f, 3.0f, 0.0f);
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.0f, 3.0f);
   glVertex2f(3.0f, 3.0f);
   glVertex2f(3.0f, 0.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
}

void rotate()
{
   glRotatef(90, 0.0f, 0.0f, 1.0f);
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.0f, 3.0f);
   glVertex2f(3.0f, 3.0f);
   glVertex2f(3.0f, 0.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
}

void reflection()
{
   GLfloat m[16] = {
       1.0f, 0.0f, 0.0f, 0.0f,
       0.0f, -1.0f, 0.0f, 0.0f,
       0.0f, 0.0f, 1.0f, 0.0f,
       0.0f, 0.0f, 0.0f, 1.0f};
   glMultMatrixf(m);
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.0f, 3.0f);
   glVertex2f(3.0f, 3.0f);
   glVertex2f(3.0f, 0.0f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.0f, 10.0f);
   glVertex2f(0.0f, -10.0f);
   glEnd();
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(10.0f, 0.0f);
   glVertex2f(-10.0f, 0.0f);
   glEnd();
   original();
   translate();
   glFlush();
}

void display2()
{
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.0f, 10.0f);
   glVertex2f(0.0f, -10.0f);
   glEnd();
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(10.0f, 0.0f);
   glVertex2f(-10.0f, 0.0f);
   glEnd();
   glClear(GL_COLOR_BUFFER_BIT);
   original();
   scale();
   glFlush();
}

void display3()
{
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.0f, 10.0f);
   glVertex2f(0.0f, -10.0f);
   glEnd();
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(10.0f, 0.0f);
   glVertex2f(-10.0f, 0.0f);
   glEnd();
   glClear(GL_COLOR_BUFFER_BIT);
   original();
   rotate();
   glFlush();
}

void display4()
{
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.0f, 10.0f);
   glVertex2f(0.0f, -10.0f);
   glEnd();
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(10.0f, 0.0f);
   glVertex2f(-10.0f, 0.0f);
   glEnd();
   glClear(GL_COLOR_BUFFER_BIT);
   original();
   reflection();
   glFlush();
}

int main(int argc, char **argv)
{
   int choice;
   printf("Enter the choice for transformation\n");
   printf("1. Translation\n");
   printf("2. Scaling\n");
   printf("3. Rotation\n");
   printf("4. Reflection\n");
   scanf("%d", &choice);
   glutInit(&argc, argv);
   glutCreateWindow("Square Transformation");
   glutInitWindowSize(1600, 900);
   glutInitWindowPosition(0, 0);
   if (choice == 1)
   {
      glutDisplayFunc(display);
   }
   else if (choice == 2)
   {
      glutDisplayFunc(display2);
   }
   else if (choice == 3)
   {
      glutDisplayFunc(display3);
   }
   else if (choice == 4)
   {
      glutDisplayFunc(display4);
   }
   else
   {
      printf("Invalid Input");
      return 0;
   }
   initGL();
   glutMainLoop();
   return 0;
}