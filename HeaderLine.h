#pragma once
#include <string>

class HeaderLine {
	std::string host;

public:
	//add a construtor to populate the instant vars.
	HeaderLine() {};

	HeaderLine(std::string h) {
		this->host = h;
	}

};