#pragma once
#include <vector>
#include <random>
#include "star.hpp"

class StarManager
{
public:
	static StarManager* instance() {
		if (mInstance == nullptr) {
			mInstance = new StarManager();
		}
		return mInstance;
	}
	~StarManager();

	std::vector<Star> getStar() const {
		return mStar;
	}

	void moveStar() {
		for (auto & star : mStar) {
			star.move();
		}
	}

	void drawStar() {
		for (const auto & star : mStar) {
			star.draw();
		}
	}

	void addStar(float radius);

private:
	StarManager();

	std::vector<Star> mStar;
	std::random_device mRandomDevice;
	std::uniform_real_distribution<float> mDistrubution;
	static StarManager *mInstance;
};
