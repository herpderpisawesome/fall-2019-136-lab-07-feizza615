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
  std::cout<<removeLeadingSpaces("       int x = 1;  ")+"\n";
  std::cout<<fileReader("bad-code.cpp");
}
