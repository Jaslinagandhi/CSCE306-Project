#pragma once
//Import included files and previous header files
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include "NetworkLayer.h"
#include "Message.h"

//Let framelayer inherit from message class
class FrameLayer:public Message {
	//define attributes
	NetworkLayer network;
	long int preamble;
	std::string destMac="00-00-5e-00-53-af";
	std::string  sourceMac="00-07-E9-42-AC-28";
	__int16 type;
	__int32 crc;
	__int64 interFrameGap;
	FrameLayer() = default; //default constructor
public:
	//overloaded constructor
	FrameLayer(NetworkLayer networkk, long int preamble, std::string destMacc, std::string sourceMacc, __int16 typee, __int32 crcc,
		__int64 interFrameGapp) {
		this->network = networkk;
		this->preamble = preamble;
		this->destMac = destMacc;
		this->sourceMac = sourceMacc;
		this->type = typee;
		this->crc = crcc;
		this->interFrameGap = interFrameGapp;
	}
	//get and set methods for all attributes
	std::string getLayerName() {
		return "Link Layer";
	}
	void setPreamble(long int pre) {
		preamble = pre;
	}
	long int getPreamble() {
		return preamble;
	}
	void setDestMac(std::string mac) {
		this->destMac = mac;
	}
	std::string  getDestMac() {
		 return destMac;
	}
	void setSourceMac(std::string mac) {
		 this->sourceMac = mac;
	}
	std::string getSourceMac() {
		return sourceMac;
	}
	void setType(__int16 typee) {
		type = typee;
	}
	__int16 getType() {
		return type;
	}
	void setCrc(__int32 crcc) {
		crc = crcc;
	}
	__int32 getCrc() {
		return crc;
	}
	void setInterFrameGap(__int64 gap) {
		interFrameGap = gap;
	}
	__int64 getInterFrameGap() {
		return interFrameGap;
	}
	//String method that prints all values
	std::string toString() {
		return "In FrameLayer, following are the content of the message:\ncrc: " + std::to_string(crc) + "\nPreamble: " + std::to_string(preamble) +
			"\nDestination Mac: " + destMac + "\nSource Mac: " + sourceMac + "\nType: " + std::to_string(type) + "\nInter Frame Gap:" + std::to_string(interFrameGap);
	}

};