#pragma once
#include <iostream>

//parent class that following classes inherit from
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