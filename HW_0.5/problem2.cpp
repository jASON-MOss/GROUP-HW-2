/**
 * @file problem2.cpp
 * @author Jason Moss
 * @date 2023-08-31
 * @brief Makeup for problems 2 and 3
 * 
 * A program that dynamically creates an array of ints. It reads from a file into an array. It then prints and finds the average.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;




/**
 * Reads info from a file into the array
 *
 * @param int* array a pointer for an int array
 * @param int MAX_ARRAY Array length
 * @pre an array has been declared. The user has been prompted for the array length
 * @return int *array
 * @post info from the file has been read into the array
 * 
 */
int arrayFill(int* array, int MAX_ARRAY);

/**
 * prints out the contents of the array to the screen
 *
 * @param int* array an array of integers
 * @param int MAX_ARRAY array length
 * @pre the user has been asked for the array length. The array has been declared.
 * @return void 
 * @post The contents are printed to the screen
 * 
 */
void arrayPrint(int* array, int MAX_ARRAY);

/**
 * finds the average of the array
 *
 * @param int* array an array of integers
 * @param int MAX_ARRAY array length
 * @pre an array of ints has been declared. The user has been asked for the array length.
 * @return float average
 * @post The average has been found
 * 
 */
float arrayAverage(int* array, int MAX_ARRAY);

int main() {
  int MAX_ARRAY = 0;
  cout << "Enter array size: ";
  cin >> MAX_ARRAY;
  cout << endl;
  int array[MAX_ARRAY];
  for(int i = 0; i < MAX_ARRAY; i++){
    array[i] = 0;
  }
  arrayFill(array, MAX_ARRAY);
  arrayPrint(array, MAX_ARRAY);
  cout << endl;
  cout << "The average is: " << arrayAverage(array, MAX_ARRAY) << endl;
  return 0;
}

int arrayFill(int* array, int MAX_ARRAY){
  ifstream myFile;
  myFile.open("probFile.txt");
  for(int i = 0; i < MAX_ARRAY; i++){
    myFile >> array[i];
  }
  myFile.close();
  return *array;
}
void arrayPrint(int* array, int MAX_ARRAY){
  for(int i = 0; i < MAX_ARRAY; i++){
    cout << array[i] << " ";
  }
}
float arrayAverage(int* array, int MAX_ARRAY){
  float sum = 0;
  float average = 0;
  for(int i = 0; i < MAX_ARRAY; i++){
    sum = sum + array[i];
  }
  average = sum / MAX_ARRAY;
  return average;
}
