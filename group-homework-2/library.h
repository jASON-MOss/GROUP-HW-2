/**
 * @file library.h
 * @author Jason Moss
 * @date 2023-10-12
 * @brief Lists methods for library class
 * 
 * lists methods for library class
 */



#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>

using namespace std;

struct Book{

  string title;
  string authorName;
  int pages;
  string isbn;
  float coverPrice;
  int year;
};

class Library{
 private:
  Book head;
  list<Book> myLibrary;
 public:
  Library();
  
  ~Library();

  void write_file(string fileName);
  
  void push_front(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased);
   
  void push_back(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased);
  
  void read_from_file(string fileName);
  
  void insert_sorted(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased);
  
  void find_author(string name);
  
  void find_album(string bookName);
  
  void print();
  
  void remove(string authorName, string bookName);
};

#endif
