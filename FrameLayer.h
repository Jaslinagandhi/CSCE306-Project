#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

#include "RequestLine.h"
#include "HTTPMsg.h"
#include "TCPSegment.h"
#include "NetworkLayer.h"

class FrameLayer {
	NetworkLayer network;
	long int preamble;
	char destMac[6];
	char sourceMac[6];
	__int16 type;
	__int32 crc;
	__int64 interFrameGap;
	FrameLayer() = default;
	FrameLayer(NetworkLayer networkk, long int preamble, char destMacc[6], char sourceMacc[6], __int16 typee, __int32 crcc,
		__int64 interFrameGapp) {
		this->network = networkk;
		this->preamble = preamble;
		for (int i = 0;i < 6;i++) {
			this->destMac[i] = destMacc[i];
		}
		for (int j = 0;j < 6;j++) {
			this->sourceMac[j] = sourceMacc[j];
		}
		this->type = typee;
		this->crc = crcc;
		this->interFrameGap = interFrameGapp;
	}
	void setPreamble(long int pre) {
		preamble = pre;
	}
	long int getPreamble() {
		return preamble;
	}
	void setDestMac(char mac[6]) {
		for (int i = 0;i < 6;i++) {
			destMac[i] = mac[i];
		}
	}
	char*  getDestMac() {
		char* mac = destMac;
		return mac;
	}
	void setSourceMac(char mac[6]) {
		for (int i = 0;i < 6;i++) {
			sourceMac[i] = mac[i];
		}
	}
	char* getSourceMac() {
		char* mac = sourceMac;
		return mac;
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

};