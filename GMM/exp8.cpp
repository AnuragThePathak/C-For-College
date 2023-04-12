/*
Let r be the rectangular window, whose upper left hand corner is at L(20,-30) and lower right hand corner is at R(90,-100). The coordinates of some the the points are given below-
A(20,-60)
B(90,-20)
C(0,0)
D(30,-20)
E(50,0)
F(50,-200)
G(40,20)
H(140,-160)
I(-200,10)
J(100,-90)
Write a program to clip the given below line using mid-point subdivision algorithm. The lines are
AB (20, -60) -> (90, -20), CD (0, 0)-> (30, -20), EF (50, 0) -> (50, -200), GH (40, 20) -> (140, -160), IJ (-200, 10) -> (100, -90)
*/

#include <iostream>
#include <string>
#include <GL/glut.h>
#include <math.h>
#include <cstring>
using namespace std;

void display();
float xmin = 20;
float ymin = -100;
float xmax = 90;
float ymax = -30;
float xd1, yd1, xd2, yd2;
float xa, ya, xb, yb, xc, yc, xd, yd, xe, ye, xf, yf, xg, yg, xh, yh, xi, yi, xj, yj;

void init(void)
{
    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 200, -250, 50);
}

int code(float x, float y)
{
    int c = 0;
    if (y > ymax)
        c = 8;
    if (y < ymin)
        c = 4;
    if (x > xmax)
        c = c | 2;
    if (x < xmin)
        c = c | 1;
    return c;
}
void mark_point(float x, float y, float xoffset, float yoffset, char str[])
{
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x + xoffset, y + yoffset);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, str[i]);
    }
}

void draw_line(float x1, float y1, float x2, float y2)
{
    xd1 = x1, xd2 = x2, yd1 = y1, yd2 = y2;
    int outcode1 = code(x1, y1);
    int outcode2 = code(x2, y2);
    bool accept = false;

    while (true)
    {
        if (!(outcode1 | outcode2))
        {
            accept = true;
            break;
        }
        else if (outcode1 & outcode2)
        {
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2d(x1, y1);
            glVertex2d(x2, y2);
            glEnd();
            break;
        }
        else
        {
            double x, y;
            int outcode = outcode1 ? outcode1 : outcode2;

            if (outcode & 8)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (outcode & 4)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (outcode & 2)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcode == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = code(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = code(x2, y2);
            }
        }
    }

    if (accept)
    {
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2d(xd1, yd1);
        glVertex2d(x1, y1);
        glEnd();
        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2d(x2, y2);
        glVertex2d(xd2, yd2);
        glEnd();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glEnd();

    // Region Codes
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-250, ymin);
    glVertex2i(200, ymin);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(-250, ymax);
    glVertex2i(200, ymax);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmax, 50);
    glVertex2i(xmax, -250);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, 50);
    glVertex2i(xmin, -250);
    glEnd();
    mark_point(-248, 48, 5, -5, (char *)"1001");
    mark_point(-248, -32, 5, -5, (char *)"0001");
    mark_point(-248, -102, 5, -5, (char *)"0101");
    mark_point(22, 48, 5, -5, (char *)"1000");
    mark_point(22, -90, 5, -5, (char *)"0000");
    mark_point(22, -110, 5, -5, (char *)"0100");
    mark_point(150, 48, 5, -5, (char *)"1010");
    mark_point(150, -40, 5, -5, (char *)"0010");
    mark_point(150, -110, 5, -5, (char *)"0110");

    //   AB
    draw_line(xa, ya, xb, yb);
    mark_point(xa, ya, 5, 0, (char *)"A (20,-60)");
    mark_point(xb, yb, 3, -5, (char *)"B (90,-20)");
    mark_point(72.5, -30, 0, -5, (char *)"(72.5,-30)");

    //   CD
    draw_line(xc, yc, xd, yd);
    mark_point(xc, yc, 0, 2, (char *)"C (0,0)");
    mark_point(xd, yd, -5, -5, (char *)"D (30,-20)");

    //   EF
    draw_line(xe, ye, xf, yf);
    mark_point(xe, ye, -15, -5, (char *)"E (50,0)");
    mark_point(xf, yf, -5, -5, (char *)"F (50,-200)");
    mark_point(50, -30, -15, -5, (char *)"(50,-30)");
    mark_point(50, -100, 2, -5, (char *)"(50,-100)");

    // GH
    draw_line(xg, yg, xh, yh);
    mark_point(xg, yg, -5, 5, (char *)"G (40,20)");
    mark_point(xh, yh, -5, -5, (char *)"H (140,-160)");
    mark_point(67.7, -30, -10, 5, (char *)"(67.7,-30)");
    mark_point(90, -70, 2, 2, (char *)"(90,-70)");

    // IJ
    draw_line(xi, yi, xj, yj);
    mark_point(xi, yi, 0, 5, (char *)"I (-200,10)");
    mark_point(xj, yj, -5, -5, (char *)"J (100,-90)");
    mark_point(20, -63.3, -20, -5, (char *)"(20,-63.3)");
    mark_point(90, -86.67, -20, -5, (char *)"(90,-86.67)");
    glFlush();
}
int main(int argc, char **argv)
{
    xa = 20, ya = -60, xb = 90, yb = -20, xc = 0, yc = 0, xd = 30, yd = -20, xe = 50, ye = 0, xf = 50, yf = -200, xg = 40, yg = 20, xh = 140, yh = -160, xi = -200, yi = 10, xj = 100, yj = -90;
    cout << "The region code of A is " << code(xa, ya) << endl;
    cout << "The region code of B is " << code(xb, yb) << endl;
    cout << "The region code of C is " << code(xc, yc) << endl;
    cout << "The region code of D is " << code(xd, yd) << endl;
    cout << "The region code of E is " << code(xe, ye) << endl;
    cout << "The region code of F is " << code(xf, yf) << endl;
    cout << "The region code of G is " << code(xg, yg) << endl;
    cout << "The region code of H is " << code(xh, yh) << endl;
    cout << "The region code of I is " << code(xi, yi) << endl;
    cout << "The region code of J is " << code(xj, yj) << endl;

    cout << "------------------------------" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-600, -600);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}