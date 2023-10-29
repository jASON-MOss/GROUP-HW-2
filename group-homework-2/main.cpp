/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-10-12
 * @brief implements files for library class and book struct
 * 
 * uses the files to create a databse of books and interact with the user
 */



#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "library.h"

using namespace std;

int main() {
  Library myLibrary;
  int num;
  string file;

  while(num != 9){
    cout << "Welcome to the library! Please select from one of these options!" << endl;
    cout << "1: Read a set of books from a file" << endl;
    cout << "2: Write the list of books to a file" << endl;
    cout << "3: Print out the list of books and their info" << endl;
    cout << "4: Look for books a certain author has written" << endl;
    cout << "5: Lookup an album" << endl;
    cout << "6: Add new book" << endl;
    cout << "7: Delete an entry" << endl;
    cout << "8: Sort the list and insert an entry into it" << endl;
    cout << "9: EXIT" << endl;
    cin >> num;

    if(num > 9){
      cout << "Invalid Choice! Please select a valid option." << endl;
    }

    //option 1
    if(num == 1){
      cout << "Please enter the name of the file you wish to use: ";
      cin >> file;
      cout << endl;
      myLibrary.read_from_file(file);
    }

    //option 2
    if(num == 2){

    }

    //option 3
    if(num == 3){
      myLibrary.print();
    }
    //option 4
    if(num == 4){
      string author;
      string trash;
      cout << "Please enter the author's name: ";
      getline(cin, trash);
      getline(cin, author);
      cout << endl;
      myLibrary.find_author(author);
    }
    //option 5
    if(num == 5){
      string BOOK;
      string trash;
      cout << "Please enter the name of the book: ";
      getline(cin, trash);
      getline(cin, BOOK);
      cout << endl;
      myLibrary.find_album(BOOK);
    }
    //option 6
    if(num == 6){
      string entry;
      string bookName;
      string author;
      int pages;
      string isbn;
      float price;
      int year;
      string junk;
      
      cout << "Pushback or Pushfront?(b or f) ";
      cin >> entry;
      if(entry == "b"){//push to back is selected
	cout << "What is the title of the book? ";
	getline(cin, junk);
	getline(cin, bookName);
	
	cout << endl << "Who is the author of the book? ";
	getline(cin, author);
	
	cout << endl << "How many pages does the book have? ";
	cin >> pages;
	cout << "What is the isbn number of the book? ";
	cin >> isbn;
	cout << endl << "What is the price of the book? ";
	cin >> price;
	cout << endl << "What year was the book released? ";
	cin >> year;
	cout << endl;
	myLibrary.push_back(bookName, author, pages, isbn, price, year);
      }
      
      if(entry == "f"){//push to front is selected
	cout << "What is the title of the book? ";
	getline(cin, junk);
	getline(cin, bookName);

        cout << endl << "Who is the author of the book? ";
        getline(cin, author);

        cout << endl << "How many pages does the book have? ";
        cin >> pages;
        cout << "What is the isbn number of the book? ";
        cin >> isbn;
        cout << endl << "What is the price of the book? ";
        cin >> price;
        cout << endl << "What year was the book released? ";
        cin >> year;
        cout << endl;
	myLibrary.push_front(bookName, author, pages, isbn, price, year);
      }
    }
    //option 7
    if(num == 7){
      string BOOKNAME;
      string AUTHOR;
      string junk;
      cout << "Please enter author: ";
      getline(cin, junk);
      getline(cin, AUTHOR);
      cout << endl << "Please enter book: ";
      getline(cin, BOOKNAME);
      cout << endl;
      myLibrary.remove(AUTHOR, BOOKNAME);
    }

    //option 8
    if(num == 8){
      string bookName;
      string author;
      int pages;
      string isbn;
      float price;
      int year;
      string junk;

       cout << "What is the title of the book? ";
       getline(cin, junk);
       getline(cin, bookName);

       cout << endl << "Who is the author of the book? ";
       getline(cin, author);

       cout << endl << "How many pages does the book have? ";
       cin >> pages;
       cout << "What is the isbn number of the book? ";
       cin >> isbn;
       cout << endl << "What is the price of the book? ";
       cin >> price;
       cout << endl << "What year was the book released? ";
       cin >> year;
       cout << endl;

       myLibrary.insert_sorted(bookName, author, pages, isbn, price, year);
    }
  }
  return 0;
}
