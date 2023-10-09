/**
 * @file phonebook.cpp
 * @author Jason Moss
 * @date 2023-09-25
 * @brief Method definitions for phonebook class
 * 
 * defines methods
 */

#include "phonebook.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


/**
 * Constructor for Phonebook
 *
 * @pre 
 * @post 
 * 
 */
Phonebook::Phonebook(){
  head = NULL;
}


/**
 * deconstuctor
 *
 * @pre valid linked list
 * @post linked list is destroyed
 * 
 */
Phonebook::~Phonebook(){
  while(head != NULL){
    delete head;
    head = head ->next;
  }
}


/**
 * Pushes new data to front of the list
 *
 * @param string test User first name
 * @param string newLast user last name
 * @param string newPhone user phone number
 * @pre valid linked list
 * @return void 
 * @post User has been added to front of list
 * 
 */
void Phonebook::push_front(string test, string newLast, string newPhone){
  Node *insertData = new Node;
  insertData -> next = NULL;
  insertData -> first_name = test;
  insertData ->last_name = newLast;
  insertData ->number = newPhone;
  insertData -> next = head;
  head = insertData;
}


/**
 * Pushes new user to back of the list
 *
 * @param string item user first name
 * @param string newLast user last name
 * @param string newPhone user phone number
 * @pre valid linked list
 * @return void 
 * @post user has been added to end of list
 * 
 */
void Phonebook::push_back(string item, string newLast, string newPhone){
  Node *newItem = new Node;
  newItem -> next = NULL;
  newItem -> first_name = item;
  newItem ->last_name = newLast;
  newItem ->number = newPhone;

  if(head == NULL){
    head = newItem;
  }else{
    Node *end = head;
    while(end ->next != NULL){
      end = end ->next;
    }
    end -> next = newItem;
  }
}


/**
 * reads data from file into linked list
 *
 * @param string fileName name of file
 * @pre valid file and linked list
 * @return void 
 * @post data has been read into linked list
 * 
 */
void Phonebook::read_from_file(string fileName){
  Node *read = new Node;
  ifstream myFile;
  string junk;
  string first;
  string last;
  string phoneNum;
  myFile.open(fileName);
  while(!myFile.eof()){
    if(head == NULL){
      head = read;
    }
    myFile >> first;
    //cout << first << endl;
    myFile >> last;
    //cout << last << endl;
    getline(myFile, junk);
    getline(myFile, phoneNum);
    //cout << phoneNum << endl;
    read ->first_name = first;
    read ->last_name = last;
    read ->number = phoneNum;
    if(!myFile.eof()){
      read ->next = new Node;
      read = read ->next;
    }
  }
  myFile.close();
}



/**
 * writed linked list to a file
 *
 * @param string fileName name of file
 * @pre valid linked list and file
 * @return void 
 * @post linked list has been written to a file
 * 
 */
void Phonebook::write_to_file(string fileName){
  ofstream myFile;
  Node *write;
  write = head;
  myFile.open(fileName);
  while(write ->next != NULL){
    myFile << write ->first_name << " ";
    myFile << write ->last_name << endl;
    myFile << write ->number << endl;
    write = write ->next;
  }
  if(write ->next == NULL){
    myFile << write ->first_name << " ";
    myFile << write ->last_name << endl;
    myFile << write ->number << endl;
  }

  
  myFile.close();
}


/**
 * Sorts the list in alphabetical order and inserts the new user where it is supposed to be in that list
 *
 * @param string item user first name
 * @param string lastN user last name
 * @param string phone user phone number
 * @pre valid linked list
 * @return void 
 * @post The list is now in alphabetical order and the new user is inserted into it
 * 
 */
void Phonebook::insert_sorted(string item, string lastN, string phone){
  Node *inserted = new Node;
  inserted ->next = NULL;
  inserted ->first_name = item;
  inserted ->last_name = lastN;
  inserted ->number = phone;

  Node *sort = head;
  if(head == NULL){
    head = inserted;
  }
  if(sort ->next == NULL){
    sort -> next = inserted;
    if(sort ->next ->last_name < sort ->last_name){
      head = sort ->next;
      sort ->next = sort;
    }
  }else{
    for(Node *i = head; i ->next != NULL; i = i ->next){
      for(Node *j = i ->next; j != NULL; j = j ->next){
	if(i ->last_name > j ->last_name){
	  Node *tempPlace = new Node;
	  tempPlace ->first_name = i ->first_name;
	  tempPlace ->last_name = i ->last_name;
	  tempPlace ->number = i ->number;
	  i ->first_name = j ->first_name;
	  i ->last_name = j ->last_name;
	  i ->number = j ->number;
	  j ->first_name = tempPlace ->first_name;
	  j ->last_name = tempPlace ->last_name;
	  j ->number = tempPlace ->number;
	}
      }
    }
    Node *list = new Node;
    list = head;
    while(list != NULL){
      if(inserted ->last_name > list ->last_name && inserted ->last_name < list ->next ->last_name){
	inserted ->next = list ->next;
	list ->next = inserted;
      }
      list = list ->next;
    }
  }
}


/**
 * Looks up a user's phone number by last name
 *
 * @param string name user first name
 * @pre valid linked list and last name
 * @return string phone number
 * @post phone number has been found
 * 
 */
string Phonebook::lookup(string name){
  Node *look;
  look = head;
  if(look ->first_name == name){
    string val = look ->number;
    cout << "The phone number of " << name << " is " << val << endl;
    return val;
  }else{
    look = look ->next;
    string val2 = look ->first_name;
    while(val2 != name){
      look = look ->next;
      val2 = look ->first_name;
    }
    val2 = look ->number;
    cout << "The phone number of " << name << " is " << val2 << endl;
    return val2;
  }
}


/**
 * Looks up user based on phone number
 *
 * @param string phoneNum user phone number
 * @pre valid linked list and user
 * @return string user name
 * @post user name is given
 * 
 */
string Phonebook::reverse_lookup(string phoneNum){
  Node *phoneSearch;
  phoneSearch = head;
  if(phoneSearch ->number == phoneNum){
    string val = phoneSearch ->first_name;
    cout << "The phone number "<< phoneNum << " belongs to " << val << endl;
    return val;
  }else{
    phoneSearch = phoneSearch ->next;
    string val2 = phoneSearch ->number;
    while(val2 != phoneNum){
      phoneSearch = phoneSearch ->next;
      val2 = phoneSearch ->number;
    }
    val2 = phoneSearch ->first_name;
    cout << "The phone number " << phoneNum << " belongs to " << val2 << endl;
    return val2;
  }
}


/**
 * prints the the contents of the linked list
 *
 * @pre valid linked list
 * @return void 
 * @post linked list has been printed
 * 
 */
void Phonebook::print(){
  Node *print;
  cout << "Head-->";
  print = head;
  while(print != NULL){
    cout << print -> first_name << " " << print -> last_name << " " << print -> number;
    if(print ->next != NULL){
      cout << "-->";
    }else{
      cout << endl;
    }
    print = print -> next;
  }
}


/**
 * deletes a user
 *
 * @param string firstName user first name
 * @pre valid user and linked list
 * @return void 
 * @post user has been deleted
 * 
 */
void Phonebook::delete_user(string firstName){//use similar thing for lookup stuff
  Node *temp;
  Node *remove;
  if(head == NULL){
    return;
  }else if(head ->first_name == firstName){
    remove = head;
    head = head->next;
    delete remove;
  }else{
    temp = head;
    while(temp->next != NULL && temp->next->first_name != firstName){
      temp = temp -> next;
    }
    if(temp -> next == NULL){
      return;
    }

    remove = temp -> next;
    temp -> next = remove -> next;
    delete remove;
  }
}
