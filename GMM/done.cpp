#include <bits/stdc++.h>
#include <GL/glut.h> 

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

using namespace std;


float x_min = -30, y_min = 10, x_max = 20, y_max = 60; 
void drawWindow () {
	cout << "Cordinate of rectangle are x_min = -30, x_max = 20, Y_min = 10, y_max = 60\n";
	glBegin (GL_LINES); 
		glVertex2f(x_min, -600.0f);
		glVertex2f(x_min, 600.0f);
	glEnd();
	glBegin (GL_LINES);
		glVertex2f(x_max, -600.0f);
		glVertex2f(x_max, 600.0f);
	glEnd();
	glBegin (GL_LINES);
		glVertex2f(-600.0f, y_min);
		glVertex2f(600.0f, y_min);
	glEnd();
	glBegin (GL_LINES);
		glVertex2f(-600.0f, y_max);
		glVertex2f(600.0f, y_max);
	glEnd();
    glFlush ();
}
void mark_point(int x,int y,int xoffset, int yoffset, char str[]){
   	int w= glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (unsigned char*)str);
   	glRasterPos2f(x+xoffset,y+yoffset);
   	int len = strlen(str);
   	for (int i = 0; i < len; i++) {
   	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
	}
}
void drawOriginal(float x0, float y0, float x1, float y1){
	glColor3f(1.0, 1.0, 0);
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
    glFlush();
}
int get_code(float x, float y) {
    int code = INSIDE;
    if (x < x_min) code |= LEFT;
    else if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    else if (y > y_max) code |= TOP;
    return code;
}

void cohen_sutherland_clip(float x0, float y0, float x1, float y1, string name) {
	cout << "For line " << name << '\n';
    int code0 = get_code(x0, y0);
    int code1 = get_code(x1, y1);
    //cout << "Code of (" << x0 << ", " << y0 <<") is " << code0 << '\n';
   // cout << "Code of (" << x1 << ", " << y1 <<") is " << code1 << '\n';
    bool accept = false;
	if (code0 & code1) {
    	//cout << "Line (" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << ") is rejected\n";
    	return;
    }
    while (true) {
        if ((code0 == 0) && (code1 == 0)) {
            accept = true;
            break;
        }  
		else { 
            int code = (code0 != 0) ? code0 : code1;
            float x, y;
            if (code & LEFT) {
                x = x_min;
                y = y0 + (y1 - y0) * (x - x0) / (x1 - x0);
                // if(x < x_min || x > x_max || y < y_min || y > y_max)continue;
                 //cout << "Intersecting point: " << x << ", " << y << '\n';
            } 
			else if (code & RIGHT) {
                x = x_max;
                y = y0 + (y1 - y0) * (x - x0) / (x1 - x0);
                //if(x < x_min || x > x_max || y < y_min || y > y_max)continue;
                //cout << "Intersecting point: " << x << ", " << y << '\n';
            } 
			else if (code & BOTTOM) {
                y = y_min;
                x = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
                // if(x < x_min || x > x_max || y < y_min || y > y_max)continue;
                //cout << "Intersecting point: " << x << ", " << y << '\n';
            } 
			else { 
                y = y_max;
                x = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
                // if(x < x_min || x > x_max || y < y_min || y > y_max)continue;
                //  cout << "Intersecting point: " << x << ", " << y << '\n';
            }
            if (code == code0) {
                x0 = x;
                y0 = y;
                code0 = get_code(x0, y0);
            } 
			else {
                x1 = x;
                y1 = y;
                code1 = get_code(x1, y1);
            }
        }
    }
    if (accept) {
        glBegin(GL_LINES);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        glEnd();
        glFlush();
    }
}


void display() {
//	if(f == 1)return;
//	f = 1;
	glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    system("cls");
	mark_point(0, 40, 0, 0, (char *)"0000");
	mark_point(-60, 40, 0, 0, (char *)"0001");
	mark_point(60, 40, 0, 0, (char *)"0010");
	mark_point(-60, 100, 0, 0, (char *)"1001");
	mark_point(0, 100, 0, 0, (char *)"1000");
	mark_point(60, 100, 0, 0, (char *)"1010");
	mark_point(-60, -20, 0, 0, (char *)"0101");
	mark_point(0, -20, 0, 0, (char *)"0100");
	mark_point(60, -20, 0, 0, (char *)"0110");
	float x0 = -40, y0 = 20, x1 = -10, y1 = 70; 
	glColor3f(0.0, 0.0, 1.0); 
	drawWindow();
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-20, 20)");
	mark_point(x1, y1, +2, +2, (char *)"(-10, 70)");
  mark_point(-30, 36.66, 0, 0,(char*)"(-30, 36.66)");
  mark_point(-16, 60, 0, 0 ,(char*)"(-16, 60)");
  cout<<"Line AB is Clipped"<<endl;
	glColor3f(1.0, 0.0, 0.0);
    cohen_sutherland_clip(x0, y0, x1,y1, "AB"); //AB
	x0 = -10, y0 = 50, x1 = 30, y1 = 80; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-10, 50)");
	mark_point(x1, y1, +2, +2, (char *)"(30, 80)");
   mark_point(20, 72.5, 0,0,(char *)"(20, 72.5)");
  mark_point(3.33, 60, 0, 0, (char *)"(3.33, 60)");
  cout<<"Line CD is Partially Clipped"<<endl;

	glColor3f(0.0, 1.0, 0.0);
    cohen_sutherland_clip(x0, y0, x1,y1,"CD"); //CD
	x0 = -10, y0 = 70, x1 = 30, y1 = 30; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-10, 70)");
	mark_point(x1, y1, +2, +2, (char *)"(30, 30)");
    mark_point(0, 60, 0, 0 ,(char *)"(0, 60)");
      mark_point(20, 40, 0, 0, (char *)"(20, 40)");

      cout<<"Line BH is Partially Clipped"<<endl;
  // mark_point(20, 72.5, 0,0,(char *)"(20, 72.5)");
  // mark_point(3.33, 60, 0, 0, (char *)"(3.33, 60)");
	glColor3f(0.0, 0.0, 1.0);
    cohen_sutherland_clip(x0, y0, x1,y1, "BH"); //BH
	x0 = -20, y0 = 30, x1 = 10, y1 = 20; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-20, 30)");
	mark_point(x1, y1, +2, +2, (char *)"(10, 20)");
  cout<<"Line EF lies outside"<<endl;
	glColor3f(1.0, 1.0, 0.0);
    cohen_sutherland_clip(x0, y0, x1,y1, "EF"); //EF 
	x0 = -40, y0 = 70, x1 = -20, y1 = 100; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-40, 70)");
	mark_point(x1, y1, +2, +2, (char *)"(-20, 100)");
  cout<<"Line IJ lies outside"<<endl;
    //mark_point(-40, 60, 0, 0 (char *)"(0, 60)");
	glColor3f(1.0, 0.0, 1.0);
    cohen_sutherland_clip(x0, y0, x1,y1, "IJ"); //IJ
	x0 = 30, y0 = 80, x1 = 10, y1 = 20; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(30, 80)");
	mark_point(x1, y1, +2, +2, (char *)"(10, 20)");
    mark_point(20, 50, 0, 0 ,(char *)"(20, 50)");
    cout<<"Line DF Partially Clipped"<<endl;
	glColor3f(0.0, 1.0, 1.0);
    cohen_sutherland_clip(x0, y0, x1,y1, "DF");  //DF
	x0 = -20, y0 = 30, x1 = 30, y1 = 30; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-20, 30)");
	mark_point(x0, y0, +2, +2, (char *)"(30, 30)");
    mark_point(20, 30, 0, 0, (char *)"(20, 30)");
    cout<<"Line EH is PArtially Clipped"<<endl;
	glColor3f(0.6, 0.4, 0.9);
    cohen_sutherland_clip(x0, y0, x1,y1, "EH"); //EH 
	x0 = -20, y0 = 30, x1 = 10, y1 = -20; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(-20, 30)");
	mark_point(x1, y1, +2, +2, (char *)"(10, -20)");
  cout<<"Line EG is PArtially Clipped"<<endl;
    mark_point(-8, 10, 0, 0 ,(char *)"(-8, 10)");
	glColor3f(0.5, 0.5, 0.5);
    cohen_sutherland_clip(x0, y0, x1,y1, "EG"); //EG 
	x0 = 30, y0 = 80, x1 = -20, y1 = 100; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(30, 80)");
	mark_point(x1, y1, +2, +2, (char *)"(-20, 100)");
  cout<<"Line DJ lies outside"<<endl;
    //mark_point(0, 60, 0, 0 (char *)"(0, 60)");
	glColor3f(0.5, 0.8, 0.3);
    cohen_sutherland_clip(x0, y0, x1,y1, "DJ"); //DJ 
	x0 = 10, y0 = 20, x1 = 30, y1 = 30; 
	drawOriginal(x0, y0, x1, y1);
	mark_point(x0, y0, -4, -4, (char *)"(10, 20)");
	mark_point(x1, y1, +2, +2, (char *)"(30, 30)");
    mark_point(20, 25, 0, 0 ,(char *)"(20, 25)");
    cout<<"Line FH is Partially Clipped"<<endl;
	glColor3f(0.2, 0.7, 0.5);
    cohen_sutherland_clip(x0, y0, x1,y1, "FH"); //FH 
}

void myInit (void) {
	glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.2, 0.7, 0.5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-70, 70, -30, 110);
    glFlush ();
}


int main(int argc, char** argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition (850, 180);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("Cohen Sutherland Line Clipping");
    glutDisplayFunc (display);
    myInit ();
    glutMainLoop ();
	return 0;
}