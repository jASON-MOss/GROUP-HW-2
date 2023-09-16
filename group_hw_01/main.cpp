/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-09-13
 * @brief Implements created class or classes in roder to carry out steganography
 * 
 * COME BACK TO THIS DESCRIPTION!!!!!!!!!!!!!!!
 */



#include "Steganography.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main() {
  string fileName;
  Steganography mySteg;
  string newFileName;
  string operation;
  string textFile;

  cout << "Would you like to endcode or decode? ";
  cin >> operation;
  cout << endl;

  if(operation == "encode"){
     cout << "Please enter PPM file name: ";
     cin >> fileName;
     cout << endl;
     
     mySteg.readCipherText(fileName);
    
  }

   if(operation == "decode"){
     cout << "Please enter PPM file name: ";
     cin >> fileName;
     cout << endl;

     mySteg.readCipherText(fileName);

  }
  
  return 0;
}
