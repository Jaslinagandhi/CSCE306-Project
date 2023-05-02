#pragma once
//import all files
#include <iostream> 
#include <string>
#include <list>
#include "RequestLine.h"
#include "HeaderLine.h"
#include "Message.h"
//inherit from message class
class HTTPMsg: public Message {
private:
    RequestLine rlo;
    HeaderLine hlo;
    std::string body;

public:
    //constructors
    HTTPMsg() {};

    HTTPMsg(RequestLine rl, HeaderLine hl, std::string b = "0") {
        this->rlo = rl;
        this->hlo = hl;
        this->body = b;
    }
    std::string getLayerName() {
        return "HTTP";
    }
    //string method to print all values
    std::string toString() {
        
       return "In HTTPmsg, following are the content of the msg: \nBody: "
           + body+"\nrequest Line:"+rlo.toString()+"\nHost Line: "+hlo.toString();
    }
};