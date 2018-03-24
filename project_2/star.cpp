#include "star.hpp"
#include <cmath>
#include <iostream>

Star::Star() :mPosition(static_cast<GLfloat>(0), static_cast<GLfloat>(0)), mTime(0), mDeltaTime(0.5), mA(1.56), mB(0.1759) {
	updatePosition();
}

Star::~Star()
{}

void Star::move() {
	mTime += mDeltaTime;
	updatePosition();
}

void Star::updatePosition() {
	// std::clog << "mTime [" << mTime << "]\n";
	// std::clog << "x [" << mPosition.first << "] y [" << mPosition.second << "]\n";
	mPosition.first = static_cast<GLfloat>(mA * std::exp(mB * mTime) * std::cos(mTime));
	mPosition.second = static_cast<GLfloat>(mA * std::exp(mB * mTime) * std::sin(mTime));
	// std::clog << "x [" << mPosition.first << "] y [" << mPosition.second << "]\n";
}
