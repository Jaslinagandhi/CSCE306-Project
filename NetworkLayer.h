#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>


#include "RequestLine.h"
#include "HTTPMsg.h"
#include "TCPSegment.h"

class NetworkLayer {
	TCPSegment tcp;
	__int8 version=4;
	__int8 ihl;
	__int8 dscp;
	__int8 ecn;
	__int16 totalLength;
	__int16 identification;
	__int8 flags;
	__int16 fragmentOffset;
	__int8 timeToLive;
	__int8 protocol;
	__int16 headerChecksum;
	std::string sip = "192.152.22.117";
	std::string dip = "195.155.1.10";

	std::string options;

public:
	NetworkLayer()=default;
	NetworkLayer(TCPSegment tcpp, __int32 sipp, __int32 dipp) {
		this->tcp = tcpp;
		this->sip = sipp;
		this->dip = dipp;
	}
	__int8 getVersion() {
		return version;
	}
	void setihl(__int8 Ihl) {
		ihl = Ihl;
	}
	__int8 getihl() {
		return ihl;
	}

	void setdscp(__int8 Dscp) {
		dscp = Dscp;
	}
	__int8 getdscp() {
		return dscp;
	}
	void setecn(__int8 Ecn) {
		ecn = Ecn;
	}
	__int8 getecn() {
		return ecn;
	}
	void setTotalLength(__int16 totalLengthh) {
		totalLength = totalLengthh;
	}
	__int16 getTotalLength() {
		return totalLength;
	}
	void setIdentification(__int16 Identification) {
		identification = Identification;
	}
	__int16 getIdentification() {
		return identification;
	}
	void setFlags(__int8 Flags) {
		flags = Flags;
	}
	__int8 getFlags() {
		return flags;
	}
	void setFragmentOffset(__int16 Fragment) {
		fragmentOffset = Fragment;
	}
	__int16 getFragmentOffset() {
		return fragmentOffset;
	}
	void setTimeToLive(__int8 time) {
		timeToLive = time;
	}
	__int8 getTimeToLive() {
		return timeToLive;
	}
	void setProtocol(__int8 Protocol) {
		protocol = Protocol;
	}
	__int8 getProtocol() {
		return protocol;
	}
			
};