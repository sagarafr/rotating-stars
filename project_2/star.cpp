#include "star.hpp"
#include <cmath>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

Star::Star(GLfloat r, GLfloat g, GLfloat b, float radius):mPosition(static_cast<GLfloat>(0), static_cast<GLfloat>(0)), mTime(0.0f), mDeltaTime(0.01f), mA(1.56f), mB(0.1759f), mColor(r, g, b) {
	updatePosition();
	mRadius = radius;
	for (int cpt(0); cpt < 1000; ++cpt) {
		double theta(2 * M_PI * cpt / 1000);
		mCircle.emplace_back(std::make_pair<GLfloat, GLfloat>(static_cast<GLfloat>(radius * std::cos(theta)), static_cast<GLfloat>(radius * std::sin(theta))));
	}
}

Star::~Star()
{}

void Star::move() {
	mTime += mDeltaTime;
	updatePosition();
}

void Star::draw() const {
	bool isFirst(true);
	GLfloat xFirst(0.0f);
	GLfloat yFirst(0.0f);

	color();
	glBegin(GL_TRIANGLE_FAN);
	glNormal3d(0, 0, 1);
	glVertex3f(x(), y(), 1.0f);
	for (const auto & it : mCircle) {
		if (isFirst) {
			xFirst = it.first + x();
			yFirst = it.second + y();
			isFirst = false;
		}
		glVertex3f(it.first + x(), it.second + y(), 0.0f);
	}
	glVertex3f(xFirst, yFirst, 0.0f);
	glEnd();
}

void Star::color() const {
	glColor3f(std::get<0>(mColor), std::get<1>(mColor), std::get<2>(mColor));
}

void Star::updatePosition() {
	mPosition.first = static_cast<GLfloat>(mA * std::exp(mB * mTime) * std::cos(mTime));
	mPosition.second = static_cast<GLfloat>(mA * std::exp(mB * mTime) * std::sin(mTime));
}
