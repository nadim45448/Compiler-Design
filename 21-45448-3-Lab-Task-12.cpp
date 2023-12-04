#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void generateThreeAddressCode(const string& expression) {
    stringstream ss(expression);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    int tempCount = 1;


    for (size_t i = 0; i < tokens.size(); ++i) {

        if (tokens[i] == "+" || tokens[i] == "-") {

            string tempVar = "t" + to_string(tempCount++);
            cout << tempVar << "=" << tokens[i - 1] << tokens[i] << tokens[i + 1] << endl;

            tokens[i + 1] = tempVar;
        }
    }

    cout << "out=" << tokens.back() << endl;
}

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string expression;
    getline(inputFile, expression);

    generateThreeAddressCode(expression);

    inputFile.close();

    return 0;
}
