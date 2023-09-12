/**
 * @file Vector.h
 * @author Jason Moss
 * @date 2023-09-05
 * @brief Contains the prototypes for the vector class
 * 
 * lists the prototypes for the vector class
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <fstream>
using namespace std;

class Vector {
 private:
  int *vec_ptr;
  int vec_size;
  int vec_capacity;
 public:

/**
 * constructor for the Vector class
 *
 * @pre a valid vector variable 
 * @post ptr set to null, size and capacity set to 0
 * 
 */
  Vector();

/**
 * A copy constructor that copies the data from other to the current vector
 *
 * @param const Vector &other a valid vector
 * @pre a valid vector has been set
 * @post the current vector contains other's data
 * 
 */
  Vector(const Vector &other);

/**
 * Deconstructor for Vector class
 *
 * @pre constructor has been used
 * @post ptr is deallocated, size and capacity set to 0
 * 
 */
  ~Vector();

/**
 * uses size and capacity variable to put data into the ptr
 *
 * @param int size  variable for size
 * @param int capacity variable for capacity
 * @pre user input has been taken for size and capacity
 * @return Vector
 * @post Vector is now set
 * 
 */
  Vector setVect(int size, int capacity);

/**
 * assignment operator
 *
 * @param const Vector &other other vector to be copied
 * @pre another vector has been set
 * @return Vector& 
 * @post new vector is set
 * 
 */
  Vector& operator=(const Vector &other);

/**
 * returns size
 *
 * @pre valid vector
 * @return int size
 * @post size has been returned
 * 
 */
  int size();

/**
 * returns capacity
 *
 * @pre valid vector set
 * @return int capacity
 * @post capacity is returned
 * 
 */
  int capacity();

/**
 * stores element at end of vector
 *
 * @param int element number to be stored
 * @pre valid vector set
 * @return void 
 * @post element has been stored at the end of the vector, size has increased
 * 
 */
  void push_back(int element);

/**
 * Resizes vector to contain n elements
 *
 * @param int n new capacity
 * @pre valid vector set
 * @return void 
 * @post vector can contain n items
 * 
 */
  void reserve(int n);

/**
 * returns reference at position index
 *
 * @param unsigned int index position
 * @pre valid vector set
 * @return int& reference at index
 * @post postion at index is returned
 * 
 */
  int& operator[](unsigned int index);

/**
 * prints vector
 *
 * @param ostream& ostr 
 * @param const Vector& other vector
 * @pre valid vector is set
 * @return friend ostr
 * @post vector has been printed
 * 
 */
  friend ostream& operator <<(ostream& ostr, const Vector& other);
};
#endif
