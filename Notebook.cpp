//
// Created by itamarq on 23/03/2022.
//

#include "Notebook.hpp"
namespace ariel {

    bool Notebook::write(int pageNum, int rowNum, int colNum, ariel::Direction direction, std::string& input) {
        this->pages.emplace(1, std::vector<char*>());
        return true;
    }

    std::string Notebook::read(int pageNum, int rowNum, int colNum, ariel::Direction direction, int len) {
        this->pages.emplace(2, std::vector<char*>());
        return "";
    }

    bool Notebook::erase(int pageNum, int rowNum, int colNum, ariel::Direction direction, int len) {
        this->pages.emplace(3, std::vector<char*>());
        return true;
    }

    void Notebook::show(int pageNum) {
        this->pages.emplace(4, std::vector<char*>());
    }
}