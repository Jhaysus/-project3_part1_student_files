//
// Created by Ali Kooshesh on 9/27/25.
//

#include "Scanner.hpp"

#include <utility>
#include <iostream>
#include <fstream>
#include <vector>


#include "utils.hpp"


//makes sure that
Scanner::Scanner(std::filesystem::path inputPath) {
    //I want to be able to go through the file
    namespace fs = std::filesystem;
    if (inputPath.has_extension() && inputPath.extension() == ".tokens") {
        inputPath.replace_extension(".txt");
    }
    inputPath_ = std::move(inputPath);
}


static bool iswordChar(char c) {
    return ( c >='a' && c <='z');
}
std::string Scanner::readWord(std::istream &in) {



    bool lastApostrophe= false;
    char c;
    std::string word ="";
    bool inWord = false;
    while ( in.get(c)) {
        c = std::toupper(static_cast<unsigned char>(c));
        if (iswordChar(c)) {
            word += c;
            inWord = true;
            lastApostrophe = false;
        }else if ( c == '\'') {
           if (inWord && !lastApostrophe) {
               word += c;
               lastApostrophe = true;
           }else if ( inWord) {
               break;
           }
        }else {
            if (inWord) {
                break;
            }
        }
    }

    while (!word.empty() && word.back() == '\'') {
        word.pop_back();
    }
    return word;
}

error_type Scanner::tokenize(std::vector<std::string>& words) {
    words.clear();
    std::ifstream inFile(inputPath_);
    if (!inFile) {
        return error_type::FILE_NOT_FOUND;
    }
    while (true) {
        std::string word = readWord(inFile);
        if (word.empty()) {
            break;
        }
        words.push_back(word);
    }

    return NO_ERROR;
}

error_type Scanner::tokenize(std::vector<std::string>& words, const std::filesystem::path& outputFile) {
    error_type ret = tokenize(words);
    if (ret == error_type::FILE_NOT_FOUND) {
        return ret;
    }
    std::ofstream outFile(outputFile);
    if (!outFile) {
        return error_type::FILE_NOT_FOUND;
    }
    for (auto& word : words) {
        outFile <<word <<'\n';
    }
    return NO_ERROR;
}
