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
#include <list>
using namespace std;



/**
 * Constructor for library class
 *
 * @pre 
 * @post constructor done
 * 
 */
Library::Library(){
  
}



/**
 * Deconstructor for Library class
 *
 * @pre valid library
 * @post list has been deconstructed
 * 
 */
Library::~Library(){
  list<Book>::iterator it;
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    it = myLibrary.erase(it);
  }
}


/**
 * writes linked list to file
 *
 * @param string fileName valid file
 * @pre valid file and linked list
 * @return void 
 * @post list has been written to the file
 * 
 */
void Library::write_file(string fileName){
  list<Book>::iterator it;
  ofstream writeFile;
  writeFile.open(fileName);
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    writeFile << it ->title << endl;
    writeFile << it ->authorName << endl;
    writeFile << it ->pages << endl;
    writeFile << it ->isbn << endl;
    writeFile << it ->coverPrice << endl;
    writeFile << it ->year << endl;
  }
  writeFile.close();
}



/**
 * takes a new entry and pushes it to the front of the list
 *
 * @param string bookName name of book
 * @param string author name of author
 * @param int numPages number of pages
 * @param string isbnNum isbn number
 * @param float price the price of the book
 * @param int yearReleased the year the book was released
 * @pre valid entry
 * @return void 
 * @post new entry has been pushed to the front
 * 
 */
void Library::push_front(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  head.title = bookName;
  head.authorName = author;
  head.pages = numPages;
  head.isbn = isbnNum;
  head.coverPrice = price;
  head.year = yearReleased;

  myLibrary.push_front(head);
}



/**
 * Takes a new entry and add it to the back of the list
 *
 * @param string bookName name of book
 * @param string author name of the author
 * @param int numPages number of pages
 * @param string isbnNum isbn number
 * @param float price price of the book
 * @param int yearReleased year the book was released
 * @pre valid entry
 * @return void 
 * @post new entry has been added to the end of the list
 * 
 */
void Library::push_back(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  
  head.title = bookName;
  head.authorName = author;
  head.pages = numPages;
  head.isbn = isbnNum;
  head.coverPrice = price;
  head.year = yearReleased;

  myLibrary.push_back(head);
}

/**
 * Takes user entry for the file name, uses info from file to create linked list
 *
 * @param string fileName name of file
 * @pre valid filename
 * @return void 
 * @post linked ist has been created from file
 * 
 */
void Library::read_from_file(string fileName){
  ifstream myFile;
  string junk;
  string book;
  string authorName;
  int pages;
  string isbn;
  float priceOf;
  int release;
  myFile.open(fileName);
  while(!myFile.eof()){
    //getting data from file
    getline(myFile, book);
    getline(myFile, authorName);
    myFile >> pages;
    getline(myFile, junk);
    getline(myFile, isbn);
    myFile >> priceOf;
    myFile >> release;
    getline(myFile, junk);

    //putting the data in the list
    head.title = book;
    head.authorName = authorName;
    head.pages = pages;
    head.isbn = isbn;
    head.coverPrice = priceOf;
    head.year = release;
    myLibrary.push_back(head);
  }
  myFile.close();
}


/**
 * Sorts the linked list, add the new entry in the correct spot
 *
 * @param string bookName name of book
 * @param string author name of the author
 * @param int numPages number of pages
 * @param string isbnNum isbn number
 * @param float price price of the book
 * @param int yearReleased year the book released
 * @pre valid entry
 * @return void 
 * @post list has been sorted and the new entry is in the correct spot
 * 
 */
void Library::insert_sorted(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  string entryInserted = "no";
  cout << "STARTING INSERT SORTED FUNCTION" << endl;
  //getting new entry
  head.title = bookName;
  head.authorName = author;
  head.pages = numPages;
  head.isbn = isbnNum;
  head.coverPrice = price;
  head.year = yearReleased;

  myLibrary.push_back(head);
  list<Book>::iterator it;
  list<Book>::iterator ti;
  cout << "Starting Loop" << endl;
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    for(ti = it++; ti != myLibrary.end(); ti++){
    list<Book>::iterator temp;
    //do bubble sort
      if(ti != myLibrary.end()){
	if(it ->authorName > ti ->authorName){
	  temp = it;
	  cout << "Starting if statement" << endl;
	  temp ->authorName = ti ->authorName;
	  cout << "Author name moved" << endl;
	  temp ->coverPrice = ti ->coverPrice;
	  cout << "Cover price moved" << endl;
	  temp ->isbn = ti ->isbn;
	  cout << "isbn moved" << endl;
	  temp ->pages = ti ->pages;
	  cout << "pages moved" << endl;
	  temp ->title = ti ->title;
	  cout << "title moved" << endl;
	  temp ->year = ti ->year;

	  cout << "1" << endl;

	   ti ->authorName = it ->authorName;
	   ti ->coverPrice = it ->coverPrice;
	   ti ->isbn = it ->isbn;
	   ti ->pages = it ->pages;
	   ti ->title = it ->title;
	   ti ->year = it ->year;

	   cout << "2" << endl;

	   it ->authorName = temp ->authorName;
	   it ->coverPrice = temp ->coverPrice;
	   it ->isbn = temp ->isbn;
	   it ->pages = temp ->pages;
	   it ->title = temp ->title;
	   it ->year = temp ->year;

	   cout << "3" << endl;
	}
      }
    }
  }
}


/**
 * Takes an author and prints out all the books the author has written
 *
 * @param string name name of the author
 * @pre valid entry
 * @return void 
 * @post Books are printed
 * 
 */
void Library::find_author(string name){
  list<Book>::iterator it;
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    if(it ->authorName == name){
      cout << "Book: " << it ->title << endl;
      cout << "Pages: " << it ->pages << endl;
      cout << "isbn: " << it ->isbn << endl;
      cout << "Price: " << it ->coverPrice << endl;
      cout << "Year of Release: " << it ->year << endl;
      cout << endl;
    }
  }
}//lookup and print all books wtitten by author


/**
 * Takes a book name and prints info on all books with the same name
 *
 * @param string bookName name of the book
 * @pre valid list valid entry
 * @return void 
 * @post Similar books are printed
 * 
 */
void Library::find_album(string bookName){
  list<Book>::iterator it;
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    if(it ->title == bookName){
      cout << "Printing album..." << endl;
      cout << "Book: " << it ->title << endl;
      cout << "Author: " << it ->authorName << endl;
      cout << "Number of Pages: " << it ->pages << endl;
      cout << "ISBN: " << it ->isbn << endl;
      cout << "Year Released: " << it ->year << endl;
      cout << "Price: " << it ->coverPrice << endl;
      cout << endl;
    }
  }
}//reverse lookup and prints all info on all books with a given name(Books that are in a series?)


/**
 * prints the linked list to the screen
 *
 * @pre valid list
 * @return void 
 * @post list has been printed to the screen
 * 
 */
void Library::print(){
  list<Book>::iterator it;
  cout << "Printing Books..." << endl;
  for(it = myLibrary.begin(); it!= myLibrary.end(); it++){
    cout << "Title: " << it ->title << endl;
    cout << "Author: " << it ->authorName << endl;
    cout << "Number of Pages: " << it ->pages << endl;
    cout << "ISBN: " << it ->isbn << endl;
    cout << "Price: " << it ->coverPrice << endl;
    cout << "Year of Release: " << it ->year << endl;
    cout << endl << endl;
  }
  cout << "DONE PRINTING" << endl;
}


/**
 * removes an entry from the list based on the author name and the book name
 *
 * @param string authorName name of author
 * @param string bookName name of book
 * @pre valid list and valid entry
 * @return void 
 * @post entry has been removed
 * 
 */
void Library::remove(string authorName, string bookName){
  list<Book>::iterator it;
  for(it = myLibrary.begin(); it != myLibrary.end(); it++){
    if(it ->authorName == authorName && it ->title == bookName){
     it = myLibrary.erase(it);
    }
  }
}//deletes book
