#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <sstream>

std::string removeLeadingSpaces(std::string line);
//int countChar(std::string line, char c);
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

  return indent(output);
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

//Task B
/*int countChar(std::string line, std::string c){
  int counter=0;
  for(int i = 0; i< line.length(); i++){
    if(line[i]==c){
      counter++;
    }
  }
  return counter;
}*/

std::string indent(std::string unindented){
  std::cout<<unindented;
  std::istringstream f(unindented);
  std::string line;
  std::string indented;
  int counter;
  while(std::getline(f,line)){
    indented+=stringCreator("\t",counter)+line+"\n";
    if(checkChar(line,'{')){
    //  std::cout<<counter;
      counter++;
    }
    else if (checkChar(line,'}')){
      //std::cout<<counter;
      counter--;
    }
  }
  return indented;
}

bool checkChar(std::string str, char c){
  for(int i =0; i<str.length(); i++){
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
