/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-09-05
 * @brief Implements the vector class
 * 
 * implements the files for the vector class
 */


#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;

int main() {
  int size = 0;
  int capacity;
  cout << "Please enter a size: ";
  cin >> size;
  cout << endl;
  cout << "Please enter a capacity: ";
  cin >> capacity;
  cout << endl;
  Vector other;
  other.setVect(size, capacity);
  for(int i = 0; i < size; i++){
    cout << other[i];
    cout << endl;
  }
  cout << endl;
  Vector myVec(other);//uses copy constructor
  int num = 6;
  myVec.push_back(num);
  myVec.push_back(9);
  myVec.push_back(7);
  cout<< endl;
  cout << "Size: " << myVec.size();//shows size of new vector
  cout << endl;
  cout << "Capacity: " << myVec.capacity();//shows the capacity of new vector
  cout << endl;
  for(int i = 0; i < myVec.size(); i++){//prints contents of new vector including numbers pushed using .pushBack
    cout << myVec[i];
  }
  cout << endl;
  myVec.reserve(10);//shows that you can not decrease the capacity 
  cout << "New Capacity: " << myVec.capacity() << endl;
  myVec.reserve(40);//increases the capacity to 40
  cout << "New Capacity: " << myVec.capacity() << endl;
  return 0;
}
