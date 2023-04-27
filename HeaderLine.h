#pragma once
#include <string>

class HeaderLine {
	std::string host;
private:
	void setHost(std::string hostIn) {
		host = hostIn;
	}
	std::string getHost() {
		return host;
	}

public:
	//add a construtor to populate the instant vars.
	HeaderLine() {};

	HeaderLine(std::string h) {
		this->host = h;
	}
	std::string toString() {
		return "This is the HeaderLine output: " + host;
	}
};
