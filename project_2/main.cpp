#include <GL/glut.h>
#include <vector>
#include <tuple>
#include <random>
#include <iostream>
#include <experimental/filesystem>
// TODO see if it's the same for linux
namespace fs = std::experimental::filesystem;

#include "starManager.hpp"
#include "configuration.hpp"

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
	Configuration::instance()->height(height);
	Configuration::instance()->height(width);
}

void updateCallback(int value) {
	StarManager::instance()->moveStar();
	glutPostRedisplay();
	glutTimerFunc(Configuration::instance()->updateTime(), updateCallback, value);
}

void addStarCallback(int value) {
	StarManager::instance()->addStar(10);
	glutPostRedisplay();
	glutTimerFunc(Configuration::instance()->addStarTime(), addStarCallback, value);
}

std::string getProjectDir() {
	std::string projectDir;
#if defined(_PROJECT_DIR_)
#if defined(_WIN32) || defined(_WIN64)
	std::wstring ws(_PROJECT_DIR_);
	projectDir = std::string(ws.begin(), ws.end());
#endif // defined(_WIN32) || defined(_WIN64)
#if defined(__linux__)
	projectDir = _PROJECT_DIR_;
#endif // defined(__linux__)
#endif // defined(_PROJECT_DIR_)
	return projectDir;
}

std::string getConfigFile() {
	return getProjectDir() + "config.txt";
}

int main(int argc, char **argv) {
	Configuration::instance(getConfigFile());
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(Configuration::instance()->height(), Configuration::instance()->width());
	glutInitWindowPosition(200, 200);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutCreateWindow(Configuration::instance()->windowTitle());

	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(Configuration::instance()->updateTime(), updateCallback, 0);
	glutTimerFunc(Configuration::instance()->addStarTime(), addStarCallback, 1);

	glutMainLoop();
	return 0;
}
 