#include <GL/glut.h>
#include <iostream>
#include <math.h>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f,-0.5f,0.5f,0.5f);
	glFlush();
}
void myDisplay_points(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(0.0f,3.0f);
	glVertex2f(1.7f,300.0f);
	glEnd();
	glFlush();
}
void myDisplayCircle(void)
{
	const int n =50;
	const GLfloat R = 0.5f;
	const GLfloat Pi = 3.1415926f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for(int i = 0;i<n;++i)
		glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));
	glEnd();
	glFlush();
}
void myDisplayFiveStars(void)
{
	const GLfloat Pi = 3.1415926f;
	GLfloat a = 1/(2-2*cos(72*Pi/180));
	GLfloat bx = a*cos(18*Pi/180);
	GLfloat by = a*sin(18*Pi/180);
	GLfloat cy = -a*cos(18*Pi/180);
	GLfloat A[2] = {0,a};
	GLfloat B[2] = {bx,by};
	GLfloat C[2] = {0.5,cy};
	GLfloat D[2] = {-0.5,cy};
	GLfloat E[2] = {-bx,by};
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2fv(A);
	glVertex2fv(C);
	glVertex2fv(E);
	glVertex2fv(B);
	glVertex2fv(D);
    glEnd();
    glFlush();
}
void myDisplaySinFunc(void)
{
	const GLfloat factor = 0.1f;
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(0.0f,-1.0f);
	glVertex2f(0.0f,1.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	for(x=-1.0f/factor;x<1.0f/factor;x+=0.01f)
	{
		glVertex2f(x*factor,sin(x)*factor);
	}
    glEnd();
    glFlush();

}
int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("first openGl");
    //glutDisplayFunc(&myDisplay);
    //glutDisplayFunc(&myDisplay_points);
	//glutDisplayFunc(&myDisplayCircle);
	//glutDisplayFunc(&myDisplayFiveStars);
	glutDisplayFunc(&myDisplaySinFunc);
	glutMainLoop();
    return 0;
}
