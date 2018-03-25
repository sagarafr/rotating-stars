#include <fstream>
#include <sstream>
#include "configuration.hpp"

Configuration* Configuration::mConfiguration = nullptr;

Configuration::Configuration(const std::string &filename) : mWindowTitle("rotating stars") {
	std::ifstream file;
	file.open(filename);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream is_line(line);
			std::string key;
			if (std::getline(is_line, key, '='))
			{
				std::string value;
				if (std::getline(is_line, value)) {
					if (key == "a") {
						try {
							mA = std::stof(value);
						}
						catch (std::invalid_argument) {
							mA = 1.56f;
						}
					}
					else if (key == "b") {
						try {
							mB = std::stof(value);
						}
						catch (std::invalid_argument) {
							mB = 0.1759f;
						}
					}
					else if (key == "height") {
						try {
							mHeight = std::stoi(value);
						}
						catch (std::invalid_argument) {
							mHeight = 800;
						}
					}
					else if (key == "width") {
						try {
							mWidth = std::stoi(value);
						}
						catch (std::invalid_argument) {
							mWidth = 600;
						}
					}
					else if (key == "addStarTime") {
						try {
							mAddStarTime = std::stoul(value);
						}
						catch (std::invalid_argument) {
							mAddStarTime = 1000;
						}
					}
					else if (key == "updateTime") {
						try {
							mUpdateTime = std::stoul(value);
						}
						catch (std::invalid_argument) {
							mUpdateTime = 10;
						}
					}
					else if (key == "deltaMoveStar") {
						try {
							mDeltaMoveStar = std::stof(value);
						}
						catch (std::invalid_argument) {
							mDeltaMoveStar = 0.01f;
						}
					}
					else if (key == "windowTitle") {
						mWindowTitle = value;
					}
				}
			}
		}
		file.close();
	}
}

Configuration::~Configuration() {
	if (mConfiguration != nullptr) {
		delete mConfiguration;
	}
}
