#include <GL/glut.h>
void myDisplay_points()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    	glVertex2f(0.0f,0.0f);
    	glVertex2f(0.5f,0.5f);
    glEnd();
    glFlush();
}
void myDisplay_lines()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2,0x0F0F);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	 glVertex2f(0.0f,0.0f);
	 glVertex2f(0.5f,0.5f);
	glEnd();
	glFlush();
}
void myDisplay_liti()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_LINE);
	glFrontFace(GL_CW);
	glBegin(GL_POLYGON);
    	glVertex2f(-0.5f,-0.5f);
    	glVertex2f(0.0f,-0.5f);
    	glVertex2f(0.0f,0.0f);
    	glVertex2f(-0.5f,0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glVertex2f(0.0f,0.0f);
    	glVertex2f(0.0f,0.5f);
    	glVertex2f(0.5f,0.5f);
    	glVertex2f(0.5f,0.0f);
    glEnd();
    glFlush();

}
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("points and more");
	//glutDisplayFunc(&myDisplay_points);
	//glutDisplayFunc(&myDisplay_lines);
	glutDisplayFunc(&myDisplay_liti);
	glutMainLoop();
	return 0;
}
