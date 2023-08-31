/**
 * @file problem1.cpp
 * @author Jason Moss
 * @date 2023-08-31
 * @brief makup for problem 5
 * 
 * A program that declares an array with a static variable. It reads info from a file into an array. It then prints and finds the average of the array.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ARRAY = 1000;


/**
 * Reads info from a file into the array
 *
 * @param int* array a pointer for an int array
 * @pre A array has been declared
 * @return int *array
 * @post Information from the file has been read into the array
 * 
 */
int arrayFill(int* array);

/**
 * prints out the contents of the array to the screen
 *
 * @param int* array an array of integers
 * @pre an int array has been declared ad has content inside it.
 * @return void 
 * @post The array has been printed to the screen
 * 
 */
void arrayPrint(int* array);

/**
 * finds the average of the array
 *
 * @param int* array an array of integers
 * @pre a array of integers have been declared
 * @return float average
 * @post the average has been found
 * 
 */
float arrayAverage(int* array);

int main() {
  int array[MAX_ARRAY];
  for(int i = 0; i < MAX_ARRAY; i++){
    array[i] = 0;
  }
  arrayFill(array);
  arrayPrint(array);
  cout << endl;
  cout << "The average is: " << arrayAverage(array) << endl;
  return 0;
}

int arrayFill(int* array){
  ifstream myFile;
  myFile.open("probFile.txt");
  int count = 0;
  string num;
  while(!myFile.eof()){
    myFile >> array[count];
    count++;
  }
  myFile.close();
  return *array;
}
void arrayPrint(int* array){
  for(int i = 0; i < MAX_ARRAY; i++){
    cout << array[i] << " ";
  }
}
float arrayAverage(int* array){
  float sum = 0;
  float average = 0;
  for(int i = 0; i < MAX_ARRAY; i++){
    sum = sum + array[i];
  }
  average = sum / MAX_ARRAY;
  return average;
}
