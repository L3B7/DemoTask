#include <iostream>
#include <sstream>
#include "custom_parser.h"

std::map<std::string, std::string> parseKeyValuePairs(const std::string& input) {
    std::map<std::string, std::string> dataMap;
    std::stringstream ss;
    ss.str(input);
    std::string pair;
    while (std::getline(ss, pair, ';')) {
        std::size_t splitPos = pair.find('=');
        if (splitPos == std::string::npos) {
            std::cerr << "Invalid format in the pair: " << pair << std::endl;
            continue;
        }
        std::string key = pair.substr(0, splitPos);
        std::string value = pair.substr(splitPos + 1);
        dataMap[key] = value;
    }
    return dataMap;
}