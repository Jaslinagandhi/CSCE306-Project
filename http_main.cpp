//This file contains the 'main' function. Program execution begins and ends here.

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include "RequestLine.h"
#include "HeaderLine.h"
#include "HTTPMsg.h"

std::tuple<std::string, std::string, std::string> goingThroughFile1();
std::string goingThroughFile2();

HTTPMsg httpmsg() {
    //make string variables to hold values from file
    std::string method, URL, version;
    std::string host;

    //separate tuple into three separate variables
    std::tie(method, URL, version) = goingThroughFile1();

    std::string vari1 = method;
    std::string vari2 = URL;
    std::string vari3 = version;

    //put returned host into variable
    std::string vari4 = host;

    RequestLine rl(vari1, vari2, vari3, "\r", "\n");
    HeaderLine hl(vari4);

    HTTPMsg httpmsg(rl, hl);

    return httpmsg;
}

std::tuple<std::string, std::string, std::string> goingThroughFile1() {
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
            return std::make_tuple(method, URL, version);
        }
    }
    return std::make_tuple("", "", "");
}

std::string goingThroughFile2() {
    std::string host;
    std::string line;
    std::ifstream GETFile("GET_request.txt");

    while (std::getline(GETFile, line)) {
        if (line.find("Host:") != std::string::npos) {
            std::istringstream iss{ line };
            std::getline(iss >> std::ws, host, ' '); // skip whitespace
            return host;
        }
    }
    return std::string("");
}