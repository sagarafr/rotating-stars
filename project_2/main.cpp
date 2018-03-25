#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include "star.hpp"

std::random_device rd;
std::uniform_real_distribution<float> dist(0, 1);
std::vector<Star> gStar;

void displayCallback(void) {
	std::clog << "display\n";
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (const auto & s : gStar) {
		s.draw();
	}
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
		s.move();
	}
	glutPostRedisplay();
	glutTimerFunc(10, updateCallback, value);
}

void addStarCallback(int value) {
	std::clog << "add star\n";
	gStar.emplace(gStar.begin(), Star(static_cast<GLfloat>(dist(rd)), static_cast<GLfloat>(dist(rd)), static_cast<GLfloat>(dist(rd)), 10));
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

	/*
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// global light
	GLfloat global_ambient[] = { 0.4, 0.4, 0.4, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	// GL_LIGHT0
	GLfloat diffuse[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	*/

	glutCreateWindow("rotating stars");

	//gStar.emplace(gStar.begin(), Star(static_cast<GLfloat>(dist(rd)), static_cast<GLfloat>(dist(rd)), static_cast<GLfloat>(dist(rd)), 2));

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(10, updateCallback, 0);
	glutTimerFunc(1000, addStarCallback, 1);

	glutMainLoop();
	return 0;
}
