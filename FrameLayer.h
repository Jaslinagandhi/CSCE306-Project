#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include "NetworkLayer.h"
#include "Message.h"

class FrameLayer:public Message {
	NetworkLayer network;
	long int preamble;
	std::string destMac;
	std::string  sourceMac;
	__int16 type;
	__int32 crc;
	__int64 interFrameGap;
	FrameLayer() = default;
public:
	FrameLayer(NetworkLayer networkk, long int preamble, char destMacc[6], char sourceMacc[6], __int16 typee, __int32 crcc,
		__int64 interFrameGapp) {
		this->network = networkk;
		this->preamble = preamble;
		this->destMac = destMacc;
		this->sourceMac = sourceMacc;
		this->type = typee;
		this->crc = crcc;
		this->interFrameGap = interFrameGapp;
	}
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
	std::string toString() {
		return "In FrameLayer, following are the crc of the msg: "+std::to_string(crc) ;
	}

};