/**
 * @file Vector.cpp
 * @author Jason Moss
 * @date 2023-09-05
 * @brief Method definitions for the vector class
 * 
 * Defines the methods for the vector class
 */

#include "Vector.h"
#include <iostream>
#include <fstream>
using namespace std;

Vector::Vector(){
  int *vec_ptr = NULL;
  int vec_size = 0;
  int vec_capacity = 0;
}

Vector::Vector(const Vector &other){
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];
  for(int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
}


Vector::~Vector(){
  vec_ptr = NULL;
  vec_size = 0;
  vec_capacity = 0;
}

Vector Vector::setVect(int size, int capacity){
  vec_size = size;
  vec_capacity = capacity;
  vec_ptr = new int[capacity];
  for(int i = 0; i < vec_size; i++){
    cout << "Please enter a number: ";
    cin >> vec_ptr[i];
    cout << endl;
  }
}

Vector& Vector::operator=(const Vector &other){
  delete[] vec_ptr;
  vec_ptr = new int[other.vec_capacity];
  for(int i = 0; i < other.vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
  vec_capacity = other.vec_capacity;
  vec_size = other.vec_size;
  return *this;
}

int Vector::size(){
  int size = vec_size;
  return size;
}

int Vector::capacity(){
  int capacity = vec_capacity;
  return capacity;
}

void Vector::push_back(int element){
  if(vec_capacity == vec_size){
    vec_capacity = vec_capacity * 2;
    vec_size = vec_size + 1;
    vec_ptr[vec_size - 1] = element;
  }else{
    vec_size = vec_size + 1;
    vec_ptr[vec_size - 1] = element;
  }
}

void Vector::reserve(int n){
  if(n < vec_capacity){
    
  }else{
     while(vec_capacity != n){
       vec_capacity = vec_capacity + 1;
     }
  }
}

int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}
ostream& operator <<(ostream& ostr, const Vector& other){
  ostr << other;

  return ostr;
}
