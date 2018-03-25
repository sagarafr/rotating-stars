#include "starManager.hpp"
#include "configuration.hpp"
#include <iostream>

StarManager* StarManager::mInstance = nullptr;

StarManager::StarManager() : mDistrubution(0, 1) {
}

StarManager::~StarManager() {
	if (mInstance != nullptr) {
		delete mInstance;
	}
}

void StarManager::addStar(float radius) {
	if (mStar.size() != 0 && mStar.front().y() > static_cast<GLfloat>(Configuration::instance()->height() + radius)) {
		std::clog << "rest\n";
		mStar.front().rest(static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), radius);
	}
	else {
		mStar.emplace(mStar.begin(), Star(static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), radius));
	}
}
