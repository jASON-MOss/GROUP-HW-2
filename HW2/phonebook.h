/**
 * @file phonebook.h
 * @author Jason Moss
 * @date 2023-09-25
 * @brief Contains the prototypes for the Phonebook class
 *
 * lists the prototypes for the Phonebook class
 */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Node{
  Node *next;

  string first_name;
  string last_name;
  string number;
};

class Phonebook{
 private:
  Node *head;
 public:
  Phonebook();
  ~Phonebook();
  void push_front(string test, string newLast, string newPhone);
  void push_back(string item, string newLast, string newPhone);
  void read_from_file(string fileName);
  void write_to_file(string fileName);
  void insert_sorted(string item, string lastN, string phone);
  string lookup(string name);
  string reverse_lookup(string phoneNum);
  void print();
  void delete_user(string firstName);
};
#endif
