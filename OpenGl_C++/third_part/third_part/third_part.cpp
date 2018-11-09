#include <GL/glut.h>
void myDisplayPoints()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 5.0f);
	glEnd();
	glFlush();
}
void myDisplayVistualLines()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0x0F0F);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(10.0f, 10.0f);
	glEnd();
	glFlush();
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(400, 400);
	glutCreateWindow("third part");
	//glutDisplayFunc(myDisplayPoints);
	glutDisplayFunc(myDisplayVistualLines);
	glutMainLoop();
	return 0;
}