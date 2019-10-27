#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <climits>

int main(){

  std::string fileName;
  std::string line="";
  std::cout<<"Enter cpp file name (bad-code.cpp): ";

  std::cin>>fileName;
  std::ifstream fin(fileName);

  std::cout<<"BADLY INDENTED PIECE OF CODE"<<"\n";
  while(getline(fin,line)){
    std::cout<<line<<"\n";
  }

  std::cout<<"PROPERLY INDENTED PIECE OF CODE"<<"\n"<<fileReader(fileName)<<"\n";

}
