#pragma once
#include <utility>
#include <GL/glut.h>

class Star
{
public:
	Star();
	~Star();

	void x(float x) {
		mPosition.first = static_cast<GLfloat>(x);
	}
	void y(float y) {
		mPosition.second = static_cast<GLfloat>(y);
	}

	GLfloat x() const {
		return mPosition.first;
	}
	GLfloat y() const {
		return mPosition.second;
	}

	void move();

private:
	std::pair<GLfloat, GLfloat> mPosition;
	float mTime;
	float mDeltaTime;
	float mA;
	float mB;
	void updatePosition();
};
