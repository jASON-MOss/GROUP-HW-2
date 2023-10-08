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

Phonebook::Phonebook(){
  head = NULL;
}

Phonebook::~Phonebook(){
  
}

void Phonebook::push_front(string test, string newLast, string newPhone){
  Node *insertData = new Node;
  insertData -> next = NULL;
  insertData -> first_name = test;
  insertData ->last_name = newLast;
  insertData ->number = newPhone;
  insertData -> next = head;
  head = insertData;
}

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

void Phonebook::read_from_file(string fileName){//delete test couts
  Node *read = new Node;
  ifstream myFile;
  string junk;
  string first;
  string last;
  string phoneNum;
  myFile.open(fileName);
  while(!myFile.eof()){
    if(head == NULL){
      cout << "HELLO WORLD" << endl;
      head = read;
    }
    cout << "DOING FIRST" << endl;
    myFile >> first;
    cout << first << endl;
    myFile >> last;
    cout << last << endl;
    getline(myFile, junk);
    getline(myFile, phoneNum);
    cout << phoneNum << endl;
    read ->first_name = first;
    cout << "first name: " << read ->first_name << endl;
    read ->last_name = last;
    cout << "last name: " << read ->last_name << endl;
    read ->number = phoneNum;
    cout << "number: " << read -> number << endl;
    if(!myFile.eof()){
      read ->next = new Node;
      read = read ->next;
    }
    //myFile >> first;
  }
  myFile.close();
  }

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

void Phonebook::insert_sorted(string item, string lastN, string phone){
  Node *inserted = new Node;
  inserted ->next = NULL;
  inserted ->first_name = item;
  inserted ->last_name = lastN;
  inserted ->number = phone;

  Node *sort = head;
  if(head == NULL){
    head = inserted;
    cout << "DONE" << endl;
  }
  if(sort ->next == NULL){
    sort -> next = inserted;
    if(sort ->next ->last_name < sort ->last_name){
      head = sort ->next;
      sort ->next = sort;
    }
  }else{
    for(Node *i = head; i ->next != NULL; i = i ->next){
      for(Node *j = i ->next; j != NULL; j = j ->next){//j = i ->next
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
	  cout << "new last name: " << i ->last_name << endl;
	  cout << "j last name: " << j ->last_name << endl;
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
