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

Library::Library(){
  head = NULL;
}

Library::~Library(){
  while(head != NULL){
    Book *temp;
    temp = head;
    head = head ->next;
    delete temp;
  }
  delete head;
}

void Library::push_front(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  Book *insertData = new Book;
  insertData ->next = NULL;
  insertData ->title = bookName;
  insertData ->authorName = author;
  insertData ->pages = numPages;
  insertData ->isbn = isbnNum;
  insertData ->coverPrice = price;
  insertData ->year = yearReleased;
  insertData ->next = head;
  head = insertData;
}

void Library::push_back(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  Book *newBook = new Book;
  newBook ->next = NULL;
  newBook ->title = bookName;
  newBook ->authorName = author;
  newBook ->pages = numPages;
  newBook ->isbn = isbnNum;
  newBook ->coverPrice = price;
  newBook ->year = yearReleased;

  if(head == NULL){
    head = newBook;
  }else{
    Book *end = head;
    while(end ->next != NULL){
      end = end ->next;
    }
    end ->next = newBook;
  }
}

void Library::read_from_file(string fileName){
  Book *read = new Book;
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
    if(head == NULL){
      head = read;
    }
    getline(myFile, book);
    getline(myFile, authorName);
    myFile >> pages;
    getline(myFile, junk);
    getline(myFile, isbn);
    myFile >> priceOf;
    myFile >> release;
    getline(myFile, junk);


    read ->title = book;
    read ->authorName = authorName;
    read ->pages = pages;
    read ->isbn = isbn;
    read ->coverPrice = priceOf;
    read ->year = release;
    if(!myFile.eof() && read ->next == NULL){
      read ->next = new Book;
      read = read ->next;
    }
  }
  myFile.close();
}

void Library::insert_sorted(string bookName, string author, int numPages, string isbnNum, float price, int yearReleased){
  string entryInserted = "no";
  cout << "STARTING INSERT SORTED FUNCTION" << endl;
  Book *inserted = new Book;
  inserted ->next = NULL;
  inserted ->title = bookName;
  inserted ->authorName = author;
  inserted ->pages = numPages;
  inserted ->isbn = isbnNum;
  inserted ->coverPrice = price;
  inserted ->year = yearReleased;

  cout << "STARTING IF CONDITIONS" << endl;
  Book *sort = head;
  if(head == NULL){
    head = inserted;
  }

  cout << "IF sort ->next == NULL" << endl;
  if(sort ->next == NULL){
    cout << "TEST" << endl;
    sort ->next = inserted;
    cout << "if sort ->next ->authorName < sort -> authorName" << endl;
    if(sort ->next ->authorName < sort ->authorName){
      head = sort ->next;
      sort ->next = sort;
    }
  }else{
      cout << "BEGINNING BUBBLE SORT" << endl;
      for(Book *i = head; i ->next != NULL; i = i ->next){
	for(Book *j = i ->next; j != NULL; j = j ->next){
	  if(i ->authorName < j ->authorName){
	    Book *tempPlace = new Book;
	    tempPlace ->title = i ->title;
	    tempPlace ->authorName = i ->authorName;
	    tempPlace ->coverPrice = i ->coverPrice;
	    tempPlace ->isbn = i ->isbn;
	    tempPlace ->pages = i ->pages;
	    tempPlace ->year = i ->year;
	    i ->authorName = j ->authorName;
	    i ->coverPrice = j ->coverPrice;
	    i ->isbn = j ->isbn;
	    i ->pages = j ->pages;
	    i ->title = j ->title;
	    i ->year = j ->year;
	    j ->authorName = tempPlace ->authorName;
	    j ->coverPrice = tempPlace ->coverPrice;
	    j ->isbn = tempPlace ->isbn;
	    j ->pages = tempPlace ->pages;
	    j ->title = tempPlace ->title;
	    j ->year = tempPlace ->year;
	  }
	}
      }
      cout << "SORTING DONE!" << endl;
      Book *list = new Book;
      list = head;
      while(list != NULL){
	cout << "SEARCHING..." << endl;
	if(list ->next != NULL){
	   if(inserted ->authorName > list ->next ->authorName && inserted ->authorName < list ->authorName){
	     cout << "SPOT FOUND! INSERTING..." << endl;
	     inserted ->next = list ->next;
	     list ->next = inserted;
	     entryInserted = "yes";
	   }
	}
	if(list ->next == NULL && entryInserted == "no"){
	  inserted ->next = list ->next;
	  list ->next = inserted;
	  list = list ->next;
	}
	list = list ->next;
      }
  }
}

void Library::find_author(string name){
  Book *find;
  find = head;
  while(find != NULL){
    if(find ->authorName == name){
      cout << "Book: " << find ->title << endl;
      cout << "Pages: " << find ->pages << endl;
      cout << "isbn: " << find ->isbn << endl;
      cout << "Price: " << find ->coverPrice << endl;
      cout << "Year of Release: " << find ->year << endl;
      cout << endl;
    }
    find = find ->next;
  }
}//lookup and print all books wtitten by author

void Library::find_album(string bookName){
  Book *album;
  album = head;
  while(album != NULL){
    if(album ->title == bookName){
      cout << "Printing album..." << endl;
      cout << "Book: " << album ->title << endl;
      cout << "Author: " << album ->authorName << endl;
      cout << "Number of Pages: " << album ->pages << endl;
      cout << "ISBN: " << album ->isbn << endl;
      cout << "Year Released: " << album ->year << endl;
      cout << "Price: " << album ->coverPrice << endl;
    }
    album = album ->next;
  }
}//reverse lookup and prints all info on all books with a given name(Books that are in a series?)

void Library::print(){
  Book *print;
  print = head;
  cout << "Books in list: " << endl;
  while(print != NULL){
    cout << "Title: " << print ->title << endl;
    cout << "Author: " << print ->authorName << endl;
    cout << "Number of pages: " << print ->pages << endl;
    cout << "ISBN: " << print ->isbn << endl;
    cout << "Price: " << print ->coverPrice << endl;
    cout << "Year of Release: " << print ->year << endl;
    if(print ->next != NULL){
      cout << "MOVING ON TO NEXT BOOK..." << endl;
      cout << endl;
    }else{
      cout << "END OF BOOK LIST" << endl;
      cout << endl;
    }
    print = print ->next;
  }
}

void Library::remove(string authorName, string bookName){
  Book *temp;
  Book *remove;
  if(head == NULL){
    return;
  }else if(head ->authorName == authorName && head ->title == bookName){
    remove = head;
    head = head->next;
    delete remove;
  }else{
    temp = head;
    while(temp->next != NULL && temp->next->authorName != authorName && temp ->title != bookName){
      temp = temp -> next;
    }
    if(temp -> next == NULL){
      return;
    }

    remove = temp -> next;
    temp -> next = remove -> next;
    delete remove;
  }

}//delete just one book or all books written by author?
