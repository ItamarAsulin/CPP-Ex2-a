//
// Created by itamarq on 23/03/2022.
//

#include <vector>
#include <string>
#include <algorithm>
#include "Notebook.hpp"
#include "Direction.hpp"
#include "doctest.h"


using namespace ariel;
using namespace std;


// testing cases of wrting to a high row and page numbers.
TEST_CASE ("HIGH PAGE AND ROW NUMBER") {
    ariel::Notebook notebook1;
    std::string toWrite = "abc";
    for (int i = 100000; i < 100100; ++i) { // horizontal writing, reading and erasing,
        for (int j = 100000; j < 100100; ++j) {
                    CHECK(notebook1.write(i, j, 0, ariel::Direction::Horizontal, toWrite) == true);
                    CHECK(notebook1.read(i, j, 0, ariel::Direction::Horizontal, 3) == toWrite);
                    CHECK(notebook1.erase(i, j, 0, ariel::Direction::Horizontal, 3) == true);
                    CHECK(notebook1.read(i, j, 0, ariel::Direction::Horizontal, 3) == "~~~");
        }
    }

    ariel::Notebook notebook2;
    for (int i = 100000; i < 100100; ++i) {  // vertical writing, reading and erasing,
        for (int j = 100000; j < 100100; ++j) {
            CHECK(notebook2.write(i, j, 0, ariel::Direction::Vertical, toWrite) == true);
            CHECK(notebook2.read(i, j, 0, ariel::Direction::Vertical, 3) == toWrite);
            CHECK(notebook2.erase(i, j, 0, ariel::Direction::Vertical, 3) == true);
            CHECK(notebook2.read(i, j, 0, ariel::Direction::Vertical, 3) == "~~~");
        }
    }
}

// testing cases when the page, row, or column number are negative for writing, reading and erasing,
TEST_CASE ("NEGATIVE INPUT") {
    ariel::Notebook notebook;
    std::string toWrite = "abc";
    for (int i = 0; i < 50; i++) {
        int randomNum =(int) (-1 * (rand() % 1000));
        //writing
        CHECK_THROWS(notebook.write(randomNum, 0, 0, ariel::Direction::Horizontal, toWrite));
        CHECK_THROWS(notebook.write(0, randomNum, 0, ariel::Direction::Horizontal, toWrite));
        CHECK_THROWS(notebook.write(0, 0, randomNum, ariel::Direction::Horizontal, toWrite));
        //reading
        CHECK_THROWS(notebook.read(randomNum, 0, 0, ariel::Direction::Horizontal, 10));
        CHECK_THROWS(notebook.read(0, randomNum, 0, ariel::Direction::Horizontal, 10));
        CHECK_THROWS(notebook.read(0, 0, randomNum, ariel::Direction::Horizontal, 10));
        //erasing
        CHECK_THROWS(notebook.erase(randomNum, 0, 0, ariel::Direction::Horizontal,10));
        CHECK_THROWS(notebook.erase(0, randomNum, 0, ariel::Direction::Horizontal,10));
        CHECK_THROWS(notebook.erase(0, 0, randomNum, ariel::Direction::Horizontal,10));
    }
}

// testing cases when the input text or reading\erasing length are greater than 100.
TEST_CASE ("LONG TEXT READ\'WRITE") {
    ariel::Notebook notebook;
    for (int i = 0; i < 100; ++i) {
        string toWrite;
        for (int j = 0; j <= 100 +i; ++j) {
            toWrite += 'a';
        }
        CHECK_THROWS(notebook.write(0, 0, 0, ariel::Direction::Horizontal, toWrite));
        CHECK_THROWS(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 100+i));
        CHECK_THROWS(notebook.erase(0, 0, 0, ariel::Direction::Horizontal, 100+i));
    }

}

// testing cases when the text length is fine, but we get out of row boundaries.
TEST_CASE ("ROW OVERFLOW") {
    ariel::Notebook notebook;
    for (int i = 0; i < 100; ++i) {
        string toWrite;
        for (int j = 100 -i ; j >= 0 ; --j) {
            toWrite += 'a';
        }
        CHECK_THROWS(notebook.write(0, 0, i, ariel::Direction::Horizontal, toWrite));
        CHECK_THROWS(notebook.read(0, 0, i, ariel::Direction::Horizontal, 100-i));
//        CHECK_THROWS(notebook.erase(0, 0, i, ariel::Direction::Horizontal, 100-i));
    }
}

// testing cases for when trying to write a char that is not allowed.
TEST_CASE("BAD_INPUT_WRITE"){
    ariel::Notebook notebook;
    std::vector<char> badCharsArr {'~'};
    for (unsigned long i = 0; i < badCharsArr.size(); ++i) {
        char currChar = badCharsArr.at(i);
        string toWrite = to_string(currChar) ;
        CHECK_THROWS(notebook.write(0,0,0,ariel::Direction::Horizontal, toWrite));
    }

}