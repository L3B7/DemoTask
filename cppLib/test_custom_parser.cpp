#include <iostream>
#include <map>
#include <string>
#include "custom_parser.h"
#include "test_custom_parser.h"

using namespace std;

void printPairs(const vector<pair<string, string>> &parsedData);

int main() {
    cout << "Test 1" << endl;
    string input = "key1=value1;key2=value2;key3=value3";
    vector<pair<string, string>> parsedData = parseKeyValuePairs(input);
    printPairs(parsedData);

    cout << "Test 2" << endl;
    input = "name=Levente;age=25;city=Budapest";
    parsedData = parseKeyValuePairs(input);
    printPairs(parsedData);

    cout << "Test 3" << endl;
    input = "NoEqualSign;key1=value1;key2=value2";
    parsedData = parseKeyValuePairs(input);
    printPairs(parsedData);

    return 0;
}

void printPairs(const vector<pair<string, string>> &parsedData) {
    for (const auto &pair : parsedData) {
        cout << pair.first << " : " << pair.second << endl;
    }
}