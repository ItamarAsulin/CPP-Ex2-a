//
// Created by itamarq on 23/03/2022.
//

#ifndef EX2_A_NOTEBOOK_HPP
#define EX2_A_NOTEBOOK_HPP
#include <map>
#include <vector>
#include "Direction.hpp"
#include <string>
namespace ariel {
    class Notebook {
    private:
        std::map<int, std::vector<char *>> pages;
    public:
        bool write(int pageNum, int rowNum, int colNum, ariel::Direction direction, std::string& input);

        std::string read(int pageNum, int rowNum, int colNum, ariel::Direction direction, int len);

        bool erase(int pageNum, int rowNum, int colNum, ariel::Direction direction, int len);

        void show(int pageNum);
    };
}

#endif //EX2_A_NOTEBOOK_HPP
