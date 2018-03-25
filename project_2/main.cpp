#include <GL/glut.h>
#include <vector>
#include <tuple>
#include <random>
#include "starManager.hpp"

void displayCallback(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	StarManager::instance()->drawStar();
	glFlush();
	glutSwapBuffers();
}

void reshapeCallback(int width, int height) {
	glViewport(static_cast<GLint>(0), static_cast<GLint>(0), static_cast<GLsizei>(width), static_cast<GLsizei>(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(static_cast<GLdouble>(-width/2), static_cast<GLdouble>(width/2), static_cast<GLdouble>(-height/2), static_cast<GLdouble>(height/2));
}

void updateCallback(int value) {
	StarManager::instance()->moveStar();
	glutPostRedisplay();
	glutTimerFunc(10, updateCallback, value);
}

void addStarCallback(int value) {
	StarManager::instance()->addStar(10);
	glutPostRedisplay();
	glutTimerFunc(1000, addStarCallback, value);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 200);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutCreateWindow("rotating stars");

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(10, updateCallback, 0);
	glutTimerFunc(1000, addStarCallback, 1);

	glutMainLoop();
	return 0;
}
