#pragma once
#include <string>

class RequestLine {
	std::string method;
	std::string URL;
	std::string http_ver;
	std::string cr;
	std::string lf;

public:
	//add a construtor to populate the instant vars.
	RequestLine() {};

	RequestLine(std::string m, std::string r, std::string v, std::string cr, std::string lf) {
		this->method = m;
		this->URL = r;
		this->http_ver = v;
		this->cr = cr;
		this->lf = lf;
	};
};

