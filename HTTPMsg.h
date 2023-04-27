#pragma once
#include <iostream> 
#include <string>
#include <list>
#include "RequestLine.h"
#include "HeaderLine.h"
#include "Message.h"

class HTTPMsg: public Message {
private:
    RequestLine rlo;
    HeaderLine hlo;
    std::string body;

public:
    HTTPMsg() {};

    HTTPMsg(RequestLine rl, HeaderLine hl, std::string b = "0") {
        this->rlo = rl;
        this->hlo = hl;
        this->body = b;
    }
    std::string getLayerName() {
        return "HTTP";
    }

    std::string toString() {
        
       return "In HTTPmsg, following are the content of the msg: " +body;
    }
};