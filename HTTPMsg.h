#pragma once
#include <iostream> 
#include <string>
#include <list>

#include "RequestLine.h"
#include "HeaderLine.h"

class HTTPMsg {
private:
    RequestLine rlo;
    HeaderLine hlo;
    std::string body;

public:
    HTTPMsg() {};

    HTTPMsg(RequestLine rl, HeaderLine hl, std::string b = "") {
        this->rlo = rl;
        this->hlo = hl;
        this->body = b;
    }
};