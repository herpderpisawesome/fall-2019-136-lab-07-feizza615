#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <sstream>

std::string removeLeadingSpaces(std::string line);
std::string indent(std::string line);
std::string stringCreator(std::string c, int times);
bool checkChar(std::string str, char c);

//Leading Function

std::string fileReader(std::string fileName){
  std::string output="";
  std::string line="";

  std::ifstream fin(fileName);
  while(getline(fin,line)){
    output+=removeLeadingSpaces(line)+"\n";
  }

  return indent(output);;
}

//Task A
std::string removeLeadingSpaces(std::string line){
  for(int i = 0; i < line.length(); i++){
    if(isspace(line[i])==0){
      return line.substr(i);
    }
  }
  return "";
}


std::string indent(std::string unindented){
  std::istringstream f(unindented);
  std::string line;
  std::string indented;
  int counter=0;
  while(std::getline(f,line)){
    if(checkChar(line,'{')){
      indented+=stringCreator("\t",counter)+line+"\n";
      counter++;
    }
    else if (checkChar(line,'}')){
      counter--;
      indented+=stringCreator("\t",counter)+line+"\n";
    }
    else{
      indented+=stringCreator("\t",counter)+line+"\n";
    }
  }
  return indented;
}

bool checkChar(std::string str, char c){
std::string x{""};
  for(int i =0; i<str.length(); i++){
    if(str[i]==char(34)){
      for(int j=i+1; j<str.length();j++){
        if(str[j]==char(34)){
          x=str.substr(i,j-i);
          for(int z=0; z<x.length();z++){
            if(x[z]==c){
              return false;
            }
          }
        }
      }
      
    }
    if(str[i]==c){
      return true;
    }
  }
  return false;
}

std::string stringCreator(std::string c, int times){
  std::string str="";
  for(int i =0;i<times;i++){
    str+=c;
  }
  return str;
}
