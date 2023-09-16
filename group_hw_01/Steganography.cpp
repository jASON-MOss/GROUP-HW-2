/**
 * @file Steganography.cpp
 * @author Jason Moss
 * @date 2023-09-13
 * @brief Method definitions for the Steganography class
 * 
 * Defines the methods for the Steganography class
 */

#include "Steganography.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int getNthBit(char cipherChar, int n){}

void Steganography::readImage(string fileName){}

void Steganography::printImage(string fileName){}

void Steganography::readCipherText(string fileName){
  ifstream myFile;
  myFile.open(fileName);
  getline(myFile, magicNumber);
  myFile >> height;
  myFile >> width;
  myFile >> maxColor;
  cout << "magic number: " << magicNumber << endl;
  cout << "height: " << height << endl;
  cout << "width: " << width << endl;
  cout << "max color: " << maxColor << endl;

  myFile.close();
}

void Steganography::printCipherText(string fileName){}

void Steganography::cleanImage(){}

void Steganography::encipher(){}

void Steganography::decipher(){}
