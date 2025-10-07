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
<<<<<<< HEAD
=======
        using traits = std::istream::traits_type;
        unsigned char u = static_cast<unsigned char>(c);

        //UTF-8 bytes: E2 80 99
        //https://www.cogsci.ed.ac.uk/~richard/utf-8.cgi?input=2019&mode=hex
        //checking each byte to see if it's a curly '
        // byte by btye
        // E2 80 99
        if (u == 0xE2) {
            int b1 = in.peek();
            if (b1 != traits::eof() && static_cast<unsigned char>(b1) == 0x80) {
                in.get();
                int b2 = in.peek();
                if (b2 != traits::eof() && static_cast<unsigned char>(b2) == 0x99) {
                    in.get();
                    c = '\'';   // normalize to ASCII apostrophe
                } else {
                    // not E2 80 99
                    if (inWord) {
                        break;
                    }else {
                        continue;
                    }
                }
            } else {
                if (inWord) {
                    break;
                }
                else {
                    continue;
                }
            }
        }

        //go thorugh the word to do the Tokenize checklist
>>>>>>> a398b4e (Updated project files)
        c = std::tolower(static_cast<unsigned char>(c));
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
        }
        else {
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
