#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// Function to find comments, identifiers, and literals in a given line
void processLine(const string& line, vector<string>& comments, vector<string>& identifiers, vector<string>& literals) {
    // Regular expressions to match comments, identifiers, and literals
    regex commentRegex("//.*|/\\*.*?\\*/");
    regex identifierRegex("\\b[a-zA-Z_][a-zA-Z0-9_]*\\b");
    regex literalRegex("\\b\\d+\\b");

    // Find and store comments, identifiers, and literals in the vectors
    smatch match;
    if (regex_search(line, match, commentRegex))
    {
        comments.push_back(match.str());
    }
    if (regex_search(line, match, identifierRegex))
    {
        identifiers.push_back(match.str());
    }
    if (regex_search(line, match, literalRegex))
    {
        literals.push_back(match.str());
    }
}

int main() {
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    vector<string> comments, identifiers, literals;
    string line;

    // Read the file line by line
    while (getline(inputFile, line))
    {
        processLine(line, comments, identifiers, literals);
    }

    // Print the results in tabular form
    cout << "Comments:" << endl;
    for (const string& comment : comments)
    {
        cout << comment << endl;
    }
    cout<<endl;

    cout << "Identifiers:" << endl;
    for (const string& identifier : identifiers)
    {
        cout << identifier << endl;
    }
    cout<<endl;

    cout << "Literals:" << endl;
    for (const string& literal : literals)
    {
        cout << literal << endl;
    }
    cout<<endl;

    inputFile.close();
    return 0;
}

