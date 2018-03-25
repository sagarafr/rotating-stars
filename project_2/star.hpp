#pragma once
#include <utility>
#include <tuple>
#include <vector>
#include <GL/glut.h>

class Star
{
public:
	Star(GLfloat r, GLfloat g, GLfloat b, float radius);
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
	void draw() const;

private:
	std::pair<GLfloat, GLfloat> mPosition;
	std::vector<std::pair<GLfloat, GLfloat>> mCircle;
	float mTime;
	float mDeltaTime;
	float mA;
	float mB;
	std::tuple<GLfloat, GLfloat, GLfloat> mColor;

	void updatePosition();
	void color() const;
};
