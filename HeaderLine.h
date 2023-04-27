#pragma once
#include <string>

class HeaderLine {
	std::string host;

public:
	HeaderLine() {};

	HeaderLine(std::string h) {
		this->host = h;
	}

private:
	void setHost(std::string hostIn) {
		host = hostIn;
	}
	std::string getHost() {
		return host;
	}
};