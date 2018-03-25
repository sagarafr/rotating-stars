#pragma once
#include <string>
class Configuration
{
public:
	static Configuration* instance(const std::string &filename = "") {
		if (mConfiguration == nullptr) {
			mConfiguration = new Configuration(filename);
		}
		return mConfiguration;
	}
	~Configuration();

	int width() const {
		return mWidth;
	}

	int height() const {
		return mHeight;
	}

	void width(int w) {
		mWidth = w;
	}

	void height(int h) {
		mHeight = h;
	}

	float a() const {
		return mA;
	}

	float b() const {
		return mB;
	}

	float deltaMoveStar() const {
		return mDeltaMoveStar;
	}

	unsigned int addStarTime() const {
		return mAddStarTime;
	}

	unsigned int updateTime() const {
		return mUpdateTime;
	}
	
	const char* windowTitle() const {
		return mWindowTitle.c_str();
	}

private:
	Configuration(const std::string &filename);

	static Configuration *mConfiguration;
	int mWidth;
	int mHeight;
	unsigned int mAddStarTime;
	unsigned int mUpdateTime;
	float mA;
	float mB;
	float mDeltaMoveStar;
	std::string mWindowTitle;
};

