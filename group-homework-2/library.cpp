/**
 * @file library.cpp
 * @author Jason Moss
 * @date 2023-10-12
 * @brief Defines methods for library class
 * 
 * defines methods for library class
 */



#include "library.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

Library::Library(){}

Library::~Library(){}

void Library::push_front(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){}

void Library::push_back(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){}

void Library::read_from_file(string fileName){}

void Library::insert_sorted(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){}

string Library::find_author(string name){}//lookup and print all books wtitten by author

string Library::find_album(string bookName){}//reverse lookup and prints all info on all books with a given name(Books that are in a series?)

void Library::print(){}

void Library::remove(string authorName, string bookName){}//delete just one book or all books written by author?
