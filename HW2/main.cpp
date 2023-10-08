/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-09-25
 * @brief implements the files for phonebook class
 * 
 * interacts with user and uses the phonebook class
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "phonebook.h"
using namespace std;

int main() {
  int num;
  string file;
  Phonebook myPhonebook;
  while(num != 8){
    cout << "Welcome to the UTM Phonebook! You may select one of the following options: " << endl;
    cout << "1 Read a phonebook from a file" << endl;
    cout << "2 Write the phonebook to a file" << endl;
    cout << "3 Print the phonebook" << endl;
    cout << "4 Search for a user's phone number" << endl;
    cout << "5 Reverse lookup by phone number" << endl;
    cout << "6 Add a user" << endl;
    cout << "7 Delete a user" << endl;
    cout << "8 Exit this program" << endl;
    cout << endl;
    cout << "Please enter your choice now: ";
    cin >> num;
    if(num > 8){
      cout << "invalid number! Please try again." << endl;
    }
    if(num == 1){
      cout << "Please enter file name: ";
      cin >> file;
      cout << endl;
      myPhonebook.read_from_file(file);
    }

    if(num == 2){
      string file;
      cout << "Please Enter File Name: ";
      cin >> file;
      cout << endl << "WRITING..." << endl;
      myPhonebook.write_to_file(file);
    }

    if(num == 3){
      myPhonebook.print();
    }

    if(num == 4){
      string lookupName;
      cout << "Please enter user name: ";
      cin >> lookupName;
      cout << endl;
      myPhonebook.lookup(lookupName);
    }

    if(num == 5){
      string lookupPhone;
      cout << "Please enter phone number: ";
      string junk;
      getline(cin,junk);
      getline(cin,lookupPhone);
      cout << endl;
      myPhonebook.reverse_lookup(lookupPhone);
    }

    if(num == 6){
      string newUser;
      string newLast;
      string newUserPhone;
      string push;
      string sort;

      cout << "Would you like to sort the list and insert into the sorted list? yes or no?";
      cin >> sort;
      cout << endl;
      if(sort == "yes"){
	cout << "Add user first name: ";
	cin >> newUser;
	cout << endl << "Add user last name: ";
	cin >> newLast;
	cout << endl << "Add user phone number: ";
	cin >> newUserPhone;
	cout << endl;
	myPhonebook.insert_sorted(newUser, newLast, newUserPhone);
      }
      if(sort == "no"){
	 //asking user to push to front or back
	cout << "push_back or push_front? ";
	cin >> push;
	cout << endl;

	//if user wants to push to back
	if(push == "push_back"){
	  cout << "Add new user: ";
	  cin >> newUser;
	  cout << endl;
	  cout << "Add user last name: ";
	  cin >> newLast;
	  cout << endl << "New user phone: ";
	  cin >> newUserPhone;
	  cout << endl;
	  myPhonebook.push_back(newUser, newLast, newUserPhone);
	}
	//if user wants to push to front
	if(push == "push_front"){
	  cout << "Add new user: ";
	  cin >> newUser;
	  cout << endl;
	  cout << "Add user last name: ";
	  cin >> newLast;
	  cout << endl << "New user phone: ";
	  cin >> newUserPhone;
	  cout << endl;
	  myPhonebook.push_front(newUser, newLast, newUserPhone);
	}
      }
    }

    if(num == 7){
      cout << "Which user shall be deleted?(Enter first name) ";
      string deadUserFirst;
      cin >> deadUserFirst;
      
      cout <<endl << "DELETING..." << endl;
      myPhonebook.delete_user(deadUserFirst);
    }
  }
  
  return 0;
}
