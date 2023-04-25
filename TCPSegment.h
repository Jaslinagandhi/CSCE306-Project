#pragma once
#include <cstdlib>
#include <iostream>
#include "HTTPMsg.h"

class TCPSegment {
private:
	HTTPMsg httpmsg;

public:
	TCPSegment() {};

	TCPSegment(HTTPMsg hmsg) {
		//generate two numbers - one for sourcePort, one for destPort
		__int16 portGenerator(); {
			__int16 sourcePort = (1024 + (rand() % 65535));
			__int16 destPort = (1024 + (rand() % 65535));
		};
		int sequenceNum = 0;
		int acknowledgeNum = 0;
		__int8 dataOffset = 5;
		__int8 res = 0;
		__int8 flags = 0;
		__int16 windowSize = 65535;
		__int16 checkSum = 0;
		__int16 urgentPointer = 0;
		this->httpmsg = hmsg;
	};

};