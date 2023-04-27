#pragma once
#include <string>

class RequestLine {
	std::string method;
	std::string URL;
	std::string http_ver;
	std::string cr;
	std::string lf;
private:
	void setMethod(std::string met) {
		method = met;
	}
	std::string getMethod() {
		return method;
	}
	void setURL(std::string link) {
		URL = link;
	}
	std::string geturl() {
		return URL;
	}
	void setVersion(std::string vers) {
		http_ver = vers;
	}
	std::string gethttp() {
		return http_ver;
	}


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
	std::string toString() {
		return
			"The requestLine method: " + method;
	}
};
