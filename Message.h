#pragma once
#include <iostream>

class Message {
public:
    Message() {};
    virtual std::string  getLayerName()  { 
        return "Message";
    };
    virtual ~Message();

    virtual std::string toString() {
        return "Hi from Message.toString()";
    }
};