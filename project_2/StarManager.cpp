#include "starManager.hpp"

StarManager* StarManager::mInstance = nullptr;

StarManager::StarManager() : mDistrubution(0, 1) {
}

StarManager::~StarManager() {
	if (mInstance != nullptr) {
		delete mInstance;
	}
}

void StarManager::addStar(float radius) {
	mStar.emplace(mStar.begin(), Star(static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), static_cast<GLfloat>(mDistrubution(mRandomDevice)), radius));
}
