#include <iostream>
#include <sstream>
#include "custom_parser.h"

std::vector<std::pair<std::string, std::string>> parseKeyValuePairs(const std::string& input) {
    std::vector<std::pair<std::string, std::string>> dataPairs;
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
        dataPairs.emplace_back(key, value);
    }
    return dataPairs;
}