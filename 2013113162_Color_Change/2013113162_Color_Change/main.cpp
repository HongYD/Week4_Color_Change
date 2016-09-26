#include<stdio.h>
#include<stdlib.h>
#include<gl\glut.h>
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
#define PI 3.1415926
int width = 800;
int height = 800;

void Render();
void Reshape(int w, int h);
void SetupViewTransform();
void SetupViewVolume();

void Render();
void Reshape(int w, int h);
void SetupViewTransform();
void SetupViewVolume();
void MouseMotion(int x, int y);
void DrawCircle(double radius, double r, double g, double b);
bool change_color1;
bool change_color2;
bool change_color3;

struct Point
{
	int x;
	int y;
};
Point current_move;
vector<Point>PTList;
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Color Change");
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(MouseMotion);
	glutMainLoop();
	return 0;
}
void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	w = width;
	h = height;
}
void SetupViewTransform() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}
void SetupViewVolume() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400,400, -400, 400, -100, 100);
}
void Render() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetupViewTransform();
	SetupViewVolume();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	if (change_color1 == 0)
	{
		DrawCircle(100, 1, 0.5, 0.5);
		
	}
	else
	{
		DrawCircle(100, 0.5, 0.5, 0.5);
		change_color1 = 0;
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(200, 200, 0);
	if (change_color2 == 0)
	{
		DrawCircle(100, 0.3, 1.0, 0.3);

	}
	else
	{
		DrawCircle(100, 0.3, 0.3, 1.0);
		change_color2 = 0;
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-200, 200, 0);
	if (change_color3 == 0)
	{
		DrawCircle(100, 1.0, 1.0, 0.3);

	}
	else
	{
		DrawCircle(100, 0.5, 0.8, 1.0);
		change_color3 = 0;
	}
	glPopMatrix();
	


	glutSwapBuffers();

}
void DrawCircle(double radius, double r, double g, double b)
{
	glColor3f(r, g, b);
	glLineWidth(10);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 1000; i++)
	{
		double theta = PI*2.0*i / 100;
		double x = radius*cos(theta);
		double y = radius*sin(theta);
		glVertex3f(x, y, 0);
	}
	glEnd();
}

void MouseMotion(int x, int y)
{
	current_move.x = x;
	current_move.y = y;
	cout << current_move.x << ',' << current_move.y << endl;
	if (sqrt((current_move.x - 400)*(current_move.x - 400) + (current_move.y - 400)*(current_move.y - 400)) < 100)
	{
		change_color1 = 1;
	}
	if (sqrt((current_move.x - 600)*(current_move.x - 600) + (current_move.y - 200)*(current_move.y - 200)) < 100)
	{
		change_color2 = 1;
	}
	if (sqrt((current_move.x - 200)*(current_move.x - 200) + (current_move.y - 200)*(current_move.y - 200)) < 100)
	{
		change_color3 = 1;
	}
	
	glutPostRedisplay();
}