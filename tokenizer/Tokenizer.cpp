//
// Created by gritukan on 6/10/17.
//

#include "Tokenizer.h"

const std::unordered_set<std::string> Tokenizer::terminals = {"int", "=", ";", "-", "+"};

bool Tokenizer::isSpace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

bool Tokenizer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Tokenizer::isLetter(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c == '_') return true;
    return false;
}

std::vector<Token> Tokenizer::tokenize(const std::string &source) {
    std::vector<Token> result;
    size_t i = 0;
    while (i < source.size()) {
        if (isSpace(source[i])) {
            i++;
            continue;
        }
        if (isDigit(source[i])) {
            std::string token;
            while (i < source.size() && isDigit(source[i])) {
                token += source[i];
                i++;
            }
            result.push_back(Token(token, TokenType::CONSTANT));
        } else if (isLetter(source[i])) {
            std::string token;
            while (i < source.size() && isLetter(source[i])) {
                token += source[i];
                i++;
            }
            if (terminals.count(token)) {
                result.push_back(Token(token, TokenType::TERMINAL));
            } else {
                result.push_back(Token(token, TokenType::ID));
            }
        } else {
            std::string token;
            for (auto &s: terminals) {
                if (s.size() > token.size() && source.substr(i, s.size()) == s) {
                    token = s;
                }
            }
            if (token.size() == 0) {
                throw "Unexpected token " + source.substr(i, 5);
            }
            i += token.size();
            result.push_back(Token(token, TokenType::TERMINAL));
        }
    }
    return result;
}