#include <GL\glut.h>
#include <math.h>
void myDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0f, 0.0f, 0.0f); 
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
void myDisplay_two()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	glFlush();
}
void myDisplayLine()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	glFlush();
}
void myDisplayCircle()
{
	const int n = 50;
	const GLfloat R = 0.5f;
	const GLfloat PI = 3.1415926f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(R*cos(2 * PI / n*i), R*sin(2 * PI / n*i));
	}
	glEnd();
	glFlush();
}
void myDisplayFiveStar()
{
	const GLfloat PI = 3.1415926f;
	GLfloat a = 1 / (2 - 2*cos(72 * PI / 180));
	GLfloat bx = a*cos(18 * PI / 180);
	GLfloat by = a*sin(18 * PI / 180);
	GLfloat cy = -a*cos(18 * PI / 180);
	GLfloat 
		PointA[2] = { 0,a },
	    PointB[2] = { bx,by },
	    PointC[2] = { 0.5,cy },
	    PointD[2]= { -0.5,cy },
	    PointE[2] = { -bx,by };
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	glFlush();
}
void myDisplaySin()
{
	const GLfloat factor = 0.1f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (GLfloat x = -1.0f / factor; x < 1.0f / factor; x = x + 0.001f)
	{
		glVertex2f(x*factor, sin(x)*factor);
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(400, 400);
	glutCreateWindow("MY FRIST OPENGL");
	glutDisplayFunc(&myDisplaySin);
	glutMainLoop();
	return 0;
}