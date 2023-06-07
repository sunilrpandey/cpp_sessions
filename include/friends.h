#pragma once
#include "common.h"
class Printer;
class Book
{
private:
    int num_pages_;
public:
    Book() = default;
    Book(const std::string& title, int num_page) {
        title_ = title;
        num_pages_ = num_page;             
    }
    std::string title_;
    friend void print(const Book& bk);
    friend Printer;
};
//Friend functions 
void print(const Book& bk) {
    std::cout << "print : \n Title/pages" << bk.title_ << "/" << bk.num_pages_ << endl;
}
class Printer
{
public:
    void print(const Book& bk) {
        std::cout << "Printer::print : \n Title/pages" << bk.title_ << "/" << bk.num_pages_ << endl;
    }
};
