#pragma once
#include <cstdlib>
#include <iostream>
#include "HTTPMsg.h"
#include "Message.h"

#pragma once
#include <cstdlib>
#include <iostream>
#include "HTTPMsg.h"
#include "Message.h"

class TCPSegment : public Message {
private:
	int sequenceNum;
	__int16 acknowledgeNum;
	__int8 dataOffset;
	__int8 res = 0;
	__int8 flags = 0;
	__int16 windowSize;
	__int16 checkSum;
	__int16 urgentPointer;
	__int16 destPort = 80;
	__int16 sourcePort = 1029;

public:

	TCPSegment() = default;
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
	//create http message object
	HTTPMsg httpmsg;
	//getters and setters for all attributes
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
	//String method that prints all values
	std::string toString() {

		return "\nIn TCP later, the following is the content of the message: \nSource Port: " + std::to_string(this->sourcePort) +
			"\nDestination Port: " + std::to_string(this->destPort) +
			"\nSequence Number: " + std::to_string(sequenceNum) +
			"\nAcknowledgment Number:" + std::to_string(acknowledgeNum) +
			"\nData Offset:" + std::to_string(dataOffset) +
			"\nres: " + std::to_string(res) +
			"\nFlags: " + std::to_string(flags) + "\nWindow Size:" + std::to_string(windowSize) + "\nCheck Sum:" + std::to_string(checkSum) + "\nUrgent Pointer:" + std::to_string(urgentPointer) + "\n";
	}
};