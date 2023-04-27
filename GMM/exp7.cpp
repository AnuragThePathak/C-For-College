/*
Let r be the rectangular window whose left corner is at L(-30, 10) and right hand corner is R(20, 60) the coordinates of some of the points is given below a(-40, 20), b(-10, 70), c(-10, 50), d(30, 80), e(-20, 30), f(10, 20), g(10, -20), h(30, 30), i(-40, 70), j(-20, 100).
Write a program to clip the below given lines using cohen-sutherland line clipping algorightm.

1. ab		(-40, 20) -> (-10, 70)
2. cd		(-10, 50) -> (30, 80)
3. bh		(-10, 70) -> (30, 30)
4. ef		(-20, 30) -> (10, 20)
5. ij		(-40, 70) -> (-20, 100)
6. df		(30, 80) -> (10, 20)
7. eh		(-20, 30) -> (30, 30)
8. eg		(-20, 30) -> (10, -20)
9. bj		(-10, 20) -> (-20, 100)
10. fh		(10, 20) -> (30, 30)

*/

/*
Write a program to perform the following 2D transformation based on the pivot element.
*/

#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

struct Coor
{
	GLfloat x, y;
	int code;
	Coor(GLfloat x, GLfloat y)
	{
		this->x = x;
		this->y = y;
		this->code = INSIDE;
	}
};

float XW_min = -30, XW_max = 20, YW_min = 10, YW_max = 60;
vector<Coor> X = {{-40, 20}, {-10, 70}, {-10, 50}, {30, 80}, {-20, 30}, {10, 20}, {10, -20}, {30, 30}, {-40, 70}, {-20, 100}};

vector<vector<GLfloat>> clipping_window = {{-30, 10}, {20, 10}, {20, 60}, {-30, 60}};
vector<vector<GLfloat>> axes = {{-120, 0}, {120, 0}, {0, -120}, {0, 120}};

void display_clipping_window(GLfloat r, GLfloat g, GLfloat b)
{
	glColor3f(r, g, b);
	glBegin(GL_LINE_LOOP);
	for (auto itr = clipping_window.begin(); itr != clipping_window.end(); itr++)
	{
		glVertex2f((*itr)[0], (*itr)[1]);
	}
	glEnd();
	glFlush();
}

void draw_line(Coor A, Coor B, vector<float> c)
{
	glColor3f(c[0], c[1], c[2]);
	glBegin(GL_LINES);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glEnd();
}

void draw_coordinate(float x, float y, char* str)
{
	glRasterPos3f(x, y, 0);

	for (int i = 0; str[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
	}
}

void draw_stippled_line(Coor A, Coor B, vector<float> c = {1, 1, 1})
{
	glPushAttrib(GL_ENABLE_BIT);
	glLineStipple(1, 0XAAAA);
	glEnable(GL_LINE_STIPPLE);

	glColor3f(c[0], c[1], c[2]);
	glBegin(GL_LINES);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glEnd();

	glPopAttrib();

	char first_str[16];
	sprintf(first_str, "(%d, %d)", (int)A.x, (int)A.y);
	draw_coordinate(A.x, A.y, first_str);

	char second_str[16];
	sprintf(second_str, "(%d, %d)", (int)B.x, (int)B.y);
	draw_coordinate(B.x, B.y, second_str);
}

void draw_string(float x, float y, string str)
{
	glRasterPos3f(x, y, 0);

	for (int i = 0; i < str.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
}

void get_codes(Coor *X)
{
	X->code = INSIDE;

	if (X->x < XW_min)
		X->code |= LEFT;
	else if (X->x > XW_max)
		X->code |= RIGHT;
	if (X->y < YW_min)
		X->code |= BOTTOM;
	else if (X->y > YW_max)
		X->code |= TOP;
}

void cohen_sutherland(Coor A, Coor B)
{
	bool accepted = false;

	get_codes(&A);
	get_codes(&B);

	while (true)
	{
		if ((A.code == 0) && (B.code == 0))
		{
			accepted = true;
			break;
		}
		else if (A.code & B.code)
		{
			break;
		}
		else
		{
			int code_out;
			float x, y;

			if (A.code != 0)
				code_out = A.code;
			else
				code_out = B.code;

			if (code_out & TOP)
			{
				x = A.x + (B.x - A.x) * (YW_max - A.y) / (B.y - A.y);
				y = YW_max;
			}
			else if (code_out & BOTTOM)
			{
				x = A.x + (B.x - A.x) * (YW_min - A.y) / (B.y - A.y);
				y = YW_min;
			}
			else if (code_out & RIGHT)
			{
				y = A.y + (B.y - A.y) * (XW_max - A.x) / (B.x - A.x);
				x = XW_max;
			}
			else if (code_out & LEFT)
			{
				y = A.y + (B.y - A.y) * (XW_min - A.x) / (B.x - A.x);
				x = XW_min;
			}

			if (code_out == A.code)
			{
				A.x = x;
				A.y = y;
				get_codes(&A);
			}
			else
			{
				B.x = x;
				B.y = y;
				get_codes(&B);
			}
		}
	}

	if (accepted)
	{
		draw_line(A, B, vector<GLfloat>({0, 1, 1}));
	}
}

void display(void)
{
	display_clipping_window(1, 0, 0.5);

	draw_stippled_line(X[0], X[1], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[2], X[3], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[1], X[7], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[4], X[5], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[8], X[9], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[3], X[5], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[4], X[7], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[4], X[6], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[3], X[9], vector<GLfloat>({1, 0, 0}));
	draw_stippled_line(X[5], X[7], vector<GLfloat>({1, 0, 0}));

	cohen_sutherland(X[0], X[1]);
	cohen_sutherland(X[2], X[3]);
	cohen_sutherland(X[1], X[7]);
	cohen_sutherland(X[4], X[5]);
	cohen_sutherland(X[8], X[9]);
	cohen_sutherland(X[3], X[5]);
	cohen_sutherland(X[4], X[7]);
	cohen_sutherland(X[4], X[6]);
	cohen_sutherland(X[3], X[9]);
	cohen_sutherland(X[5], X[7]);
	glFlush();
}

void my_init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.5, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150, 150, -150, 150);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 2; i++)
	{
		glVertex2f(axes[i][0], axes[i][1]);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (int i = 2; i < 4; i++)
	{
		glVertex2f(axes[i][0], axes[i][1]);
	}
	glEnd();

	draw_stippled_line(Coor(-100, 10), Coor(100, 10));
	draw_stippled_line(Coor(-100, 60), Coor(100, 60));
	draw_stippled_line(Coor(-30, 110), Coor(-30, -50));
	draw_stippled_line(Coor(20, 110), Coor(20, -50));

	draw_string(XW_min - 50, (YW_max + YW_min) / 2, "0010");
	draw_string(XW_min - 50, YW_max + 20, "1010");
	draw_string((XW_min + XW_max) / 2, (YW_max + 20), "1000");
	draw_string(XW_max + 50, (YW_max + 20), "1001");
	draw_string(XW_max + 50, (YW_max + YW_min) / 2, "0001");
	draw_string(XW_max + 50, (YW_max + YW_min) / 2, "0001");
	draw_string(XW_max + 50, YW_min - 20, "0101");
	draw_string((XW_min + XW_max) / 2, YW_min - 20, "0100");
	draw_string(XW_min - 50, YW_min - 20, "0110");
	draw_string((XW_min + XW_max) / 2, (YW_max + YW_min) / 2, "0110");

	draw_coordinate(-30, 36.67, "(-30, 36.67)");
	draw_coordinate(-16, 60, "(-16, 60)");
	draw_coordinate(3.333, 60, "(3.333, 60)");
	draw_coordinate(0, 60, "(0, 60)");
	draw_coordinate(20, 40, "(20, 40)");
	draw_coordinate(16.667, 60, "16.667, 60");
	draw_coordinate(20, 30, "(20, 30)");
	draw_coordinate(-8, 10, "(-8, 10)");
	draw_coordinate(20, 27.5, "(20, 27.5)");

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Cohen-Sutherland Line Clipping");
	glutDisplayFunc(display);
	my_init();
	glutMainLoop();
	return 0;
}
