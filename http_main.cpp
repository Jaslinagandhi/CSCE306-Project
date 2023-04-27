//This file contains the 'main' function. Program execution begins and ends here.

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <queue>
#include "RequestLine.h"
#include "HeaderLine.h"
#include "HTTPMsg.h"
#include "TCPSegment.h"
#include "NetworkLayer.h"
#include "FrameLayer.h"




std::tuple<std::string, std::string, std::string> goingThroughGETFile1();
std::string goingThroughGETFile2();

int main() {
    std::queue<Message> buffer;
    //make string variables to hold values from file
    std::string method, URL, version;
    std::string host;

    //separate tuple into three separate variables
    std::tie(method, URL, version) = goingThroughGETFile1();
    host = goingThroughGETFile2();

    RequestLine rl(method, URL, version, "\r", "\n");
    HeaderLine hl(host);

    HTTPMsg httpmsg(rl, hl);
    std::cout << httpmsg.toString() << std::endl;

    //add the httpmsg to the queue 
    buffer.push(httpmsg);
    std::cout << buffer.size() << std::endl;

    //tcp segment
    //create and initialize variables for source and destination ports
        //generate two numbers - one for sourcePort, one for destPort
    __int16 sourcePort = (1024 + (rand() % 65535));
    __int16 destPort = (1024 + (rand() % 65535));

    //HTTPMsg httpmsg2 = buffer.pop();
    TCPSegment tcps(httpmsg, sourcePort, destPort);
    std::cout << tcps.toString() << std::endl;

    //network layer
    // make a function that builds what the layer needs

    std::string sipp = "0";
    std::string dipp = "0";
    NetworkLayer network(tcps, sipp, dipp);
    std::cout << network.toString() << std::endl;
    //link layer
    long int preamble=0; 
    char destMac[6]; 
    char sourceMac[6];
    __int16 type=0; 
    __int32 crc=0;
    __int64 interFrameGapp=0;
    FrameLayer link(network, preamble, destMac, sourceMac, type, crc, interFrameGapp);
    std::cout << link.toString() << std::endl;
}

std::tuple<std::string, std::string, std::string> goingThroughGETFile1() {
    std::string method, URL, version;
    std::string line;
    std::ifstream GETFile("GET_request.txt");

    while (std::getline(GETFile, line)) {
        if (line.find("GET") != std::string::npos) {
            std::istringstream iss{ line };
            std::getline(iss >> std::ws, method, ' '); // skip whitespace
            std::getline(iss >> std::ws, URL, ' ');
            std::getline(iss >> std::ws, version);
            version.erase(version.end() - 4, version.end());
        }
    }
    return std::make_tuple(method, URL, version);
}

std::string goingThroughGETFile2() {
    std::string host;
    std::string line;
    std::ifstream GETFile("GET_request.txt");

    while (std::getline(GETFile, line)) {
        if (line.find("Host:") != std::string::npos) {
            std::istringstream iss{ line };
            iss.ignore(std::numeric_limits<std::streamsize>::max(), ' '); // skip "Host:"
            std::getline(iss >> std::ws, host, ' '); // skip whitespace
            host.erase(host.end() - 4, host.end());
            return host;
        }
    }
    return std::string("");
}