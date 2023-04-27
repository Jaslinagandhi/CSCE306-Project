//This file contains the 'main' function. Program execution begins and ends here.

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include "RequestLine.h"
#include "HeaderLine.h"
#include "HTTPMsg.h"
#include "TCPSegment.h"

std::tuple<std::string, std::string, std::string> goingThroughGETFile1();
std::string goingThroughGETFile2();

int main() {
    //make string variables to hold values from file
    std::string method, URL, version;
    std::string host;

    //separate tuple into three separate variables
    std::tie(method, URL, version) = goingThroughGETFile1();
    host = goingThroughGETFile2();

    RequestLine rl(method, URL, version, "\r", "\n");
    HeaderLine hl(host);

    HTTPMsg httpmsg(rl, hl);

    //tcp segment
    //create and initialize variables for source and destination ports
    __int16 sourcePort = 0;
    __int16 destPort = 0;
    TCPSegment tcps(httpmsg, sourcePort, destPort);
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
