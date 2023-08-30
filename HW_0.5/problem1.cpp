#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ARRAY = 1000;

int arrayFill(int* array);
void arrayPrint(int* array);
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
