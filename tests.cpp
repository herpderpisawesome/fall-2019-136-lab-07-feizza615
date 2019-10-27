
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "funcs.h"
#include <string>




TEST_CASE("Single line Function"){
  CHECK(fileReader("test1.cpp").compare("int main(){\n\tcout << i;\n}\n")==0);
}

TEST_CASE("Multiple Function File"){
  std::string str="int main(){\n\t// Hi, I'm a program!\n\tint x = 1;\n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}\n";
  std::cout<<str;
  CHECK(fileReader("tests2.cpp").compare(str)==0);
}
