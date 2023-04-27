#pragma once
#include <cstdlib>
#include <iostream>
#include "HTTPMsg.h"
#include "Message.h"

class TCPSegment: public Message {
private:
	int sequenceNum;
	__int16 acknowledgeNum;
	__int8 dataOffset;
	__int8 res;
	__int8 flags;
	__int16 windowSize;
	__int16 checkSum;
	__int16 urgentPointer;
	__int16 destPort;
	__int16 sourcePort;

public:
	TCPSegment() =default;
	TCPSegment(HTTPMsg hmsg, __int16 sPort, __int16 dPort) {
		this->sourcePort = sPort;
		this->destPort = dPort;
		sequenceNum = 0;
		acknowledgeNum = 0;
		dataOffset = 5;
		res = 0;
		flags = 0;
		windowSize = 65;
		checkSum = 0;
		urgentPointer = 0;
		this->httpmsg = hmsg;
	}
	HTTPMsg httpmsg;

	std::string getLayerName() {
		return "TCP";
	}

	void setSourcePort(__int16 source) {
		sourcePort = source;
	}
	__int16 getSourcePort() {
		return sourcePort;
	}
	void setDestPort(__int16 dest) {
		destPort = dest;
	}
	__int16 getDestPort() {
		return destPort;
	}
	void setSequenceNum(int sequence) {
		int sequenceNum = sequence;
	}
	int getSequenceNum() {
		return sequenceNum;
	}
	void setAcknowledgeNum(__int8 acknowledge) {
		__int8 acknowledgeNum = acknowledge;
	}
	__int16 getAcknowledgeNum() {
		return acknowledgeNum;
	}
	void setDataOffset(__int8 offset) {
		__int8 dataOffset = offset;
	}
	__int8 getDataOffset() {
		return dataOffset;
	}
	void setReserved(__int8 reserved) {
		__int8 res = reserved;
	}
	__int8 getReserved() {
		return res;
	}
	void setFlags(__int8 f) {
		__int8 flags = f;
	}
	__int8 getFlags() {
		return flags;
	}
	void setWindowSize(__int16 winSize) {
		__int16 windowSize = winSize;
	}
	__int16 setWindowSize() {
		return windowSize;
	}
	void setCheckSum(__int16 sum) {
		__int16 checkSum = sum;
	}
	__int16 getCheckSum() {
		return checkSum;
	}
	void setUrgentPointer(__int16 urgent) {
		__int16 urgentPointer = urgent;
	}
	__int16 getUrgentPointer() {
		return urgentPointer;
	}

	std::string toString() {
		
		return "In TCP later, the following is the source port of the message: " + std::to_string(this->sourcePort);
	}
};