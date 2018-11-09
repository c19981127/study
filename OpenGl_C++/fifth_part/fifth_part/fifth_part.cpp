#include <GL/glut.h>
#include <windows.h>
static int day = 360;
void myDisplay_two(void)
{
	//glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0, 0, -200000000, 0, 0, 0, 0,-1,0);
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
	// ���ƺ�ɫ�ġ�̫����
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 50, 50);
	// ������ɫ�ġ�����
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 50, 50);
	// ���ƻ�ɫ�ġ�������
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 50, 50);
	glFlush();
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(500, 500);
	glutCreateWindow("fifth part");
	glutDisplayFunc(myDisplay_two);
	glutMainLoop();
	return 0;
}