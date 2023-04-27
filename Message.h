#pragma once
#include <iostream>

class Message {
    virtual std::string  getLayerName() = 0;
};