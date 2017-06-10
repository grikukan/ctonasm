
#include <iostream>
#include <fstream>

std::string readFile(char *fileName) {
    std::ifstream file(fileName);
    if (file.bad()) {
        throw "Error opening file " + std::string(fileName);
    }
    std::string text;
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        text = text + "\n" + line;
    }
    return text;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ctonasm <filename>" << std::endl;
        return 1;
    }
    std::string source;
    try {
        source = readFile(argv[1]);
    } catch (const std::string &exception) {
        std::cerr << exception << std::endl;
        return 1;
    }
    return 0;
}