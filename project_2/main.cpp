#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "star.hpp"

std::vector<Star> gStar;

void displayCallback(void) {
	std::clog << "display\n";
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(static_cast<GLfloat>(0.5), static_cast<GLfloat>(0.25), static_cast<GLfloat>(0.5));
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	for (const auto & s : gStar) {
		glVertex2d(s.x(), s.y());
	}
	glEnd();
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
	std::clog << "update\n";
	for (auto & s : gStar) {
		// std::clog << "before star x [" << s.x() << "] y [" << s.y() << "]\n";
		s.move();
		// std::clog << "after star x [" << s.x() << "] y [" << s.y() << "]\n";
	}
	gStar.emplace_back(Star());
	glutPostRedisplay();
	glutTimerFunc(500, updateCallback, value);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	gStar.emplace_back(Star());
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 200);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutCreateWindow("rotationg stars");

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(10, updateCallback, 0);
	//glutIdleFunc()

	glutMainLoop();
	return 0;
}
