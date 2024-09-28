#pragma once
#include "common.h"
class Printer;
class Book;

//functions from a Friend class 
class Scanner
{
public:
    void pageCount(const Book& bk);
};


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
    
    //Global friend func
    friend void print(const Book& bk);

    //Global friend func
    friend Printer;

    friend void Scanner::pageCount(const Book& bk);
};

//Global Friend functions 
void print(const Book& bk) {
    std::cout << "print : \n Title/pages" << bk.title_ << "/" << bk.num_pages_ << endl;
}

//functions from a Friend class 
class Printer
{
public:
    void print(const Book& bk) {
        std::cout << "Printer::print : \n Title/pages" << bk.title_ << "/" << bk.num_pages_ << endl;
    }
};


void Scanner::pageCount(const Book& bk) {
    std::cout << "Scanner : Num Pages -> " << bk.num_pages_ << endl;
}
