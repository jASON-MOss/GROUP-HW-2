#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int arrayFill(int* array, int MAX_ARRAY);
void arrayPrint(int* array, int MAX_ARRAY);
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
