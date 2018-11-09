#include <GL/glut.h>
#include <math.h>
void myDisplayRGB()
{
	glClearColor(1.0f,1.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.5f, 0.6f);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	glFlush();
}
void myDisplayEight()
{
	const GLfloat PI = 3.1415926f;
	glShadeModel(GL_FLAT);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <=8; i++)
	{
		glColor3f(1 & 0x04, i & 0x02, i & 0x01);
		glVertex2f(cos(i*PI / 4), sin(i*PI / 4));
	}
	glEnd();
	glFlush();
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(400, 400);
	glutCreateWindow("forth part");
	//glutDisplayFunc(myDisplayRGB);
	glutDisplayFunc(myDisplayEight);
	glutMainLoop();
	return 0;
}
