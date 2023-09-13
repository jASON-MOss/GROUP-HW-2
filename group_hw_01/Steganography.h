/**
 * @file Steganography.h
 * @author Jason Moss
 * @date 2023-09-13
 * @brief the protoypes for the Steganography class
 * 
 * Lists the prototypes for the Steganography class
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Steganography{
 private:
  string magicNumber;
  int width;
  int height;
  int macColor;
  vector<int> colorData;
  string cipherText;
  int getNthBit(char cipherChar, int n);
 public:
  void readImage(string fileName);
  void printImage(string fileName);
  void printCipherText(string fileName);
  void cleanImage();
  void encipher();
  void decipher();
};
#endif
