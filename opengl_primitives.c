#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
short int ch=0,os=0;
float i=0;
float rnd(float min, float max)
{
  return min+(float)(rand()/(float)RAND_MAX*(max-min+1));
}
void lines()
{
	glColor3f(rnd(0,1),rnd(0,1),rnd(0,1));
	glBegin(GL_LINE_LOOP);
		for(i=1;i<=rnd(4,16);i++)
			glVertex2f(rnd(-1366,1366),rnd(-740,740));
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void points()
{
	glPointSize(rnd(2,32));
	glColor3f(rnd(0,1),rnd(0,1),rnd(0,1));
	glBegin(GL_POINTS);
		glVertex2f(rnd(-1366,1366),rnd(-740,740));
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void shapes()
{
	glColor3f(rnd(0,.5),rnd(0,.5),rnd(0,.5));
	glBegin(GL_POLYGON);
		for(i=1;i<=rnd(3,1024);i++)
			glVertex2f(rnd(-1366,1366),rnd(-740,740));
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();	
}
void wipe()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
	glutPostRedisplay();
}
void display()
{
	if(os)	wipe();	
	switch(ch)
	{
		case 1:
			lines();
		break;
		case 2:
			points();
		break;
		case 3:
			shapes();
		break;
		case 4:
			wipe();
		break;
		case 5:
			os=!os;
		break;
		case 0:
			glutSwapBuffers();
			glutPostRedisplay();
		break;
		case -1: exit(0);
	}
}
void menu(int keys)
{
	ch=keys;
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(1366,740);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("PATTERNS");	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1366,1366,-740,740);
	glutDisplayFunc(display);	
	glutCreateMenu(menu);
	glutAddMenuEntry("Pause",0);
	glutAddMenuEntry("Points",2);
	glutAddMenuEntry("Lines",1);	
	glutAddMenuEntry("Shapes",3);
	glutAddMenuEntry("Different",5);
	glutAddMenuEntry("Clear",4);
	glutAddMenuEntry("Exit",-1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	
	glutMainLoop();
}
