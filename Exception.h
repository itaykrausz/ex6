//
// Created by Omer Ran on 14/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include <exception>
#include <iostream>
class DeckFileNotFound: public std::exception {
public:
    const char* what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError: public std::exception {
    std::string m_error;
public:
    explicit DeckFileFormatError(const int line){
        this->m_error = "Deck File Error: File format error in line "+ std::to_string(line);
    }
    const char* what() const noexcept override{
        return this->m_error.c_str();
    }
};

class DeckFileInvalidSize: public std::exception {
public:
    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};
#endif //EX4_EXCEPTION_H
