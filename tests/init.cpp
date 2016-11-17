#include "stack.hpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
SCENARIO("count111", "[count1111]"){
  B obj("names.txt");
 ifstream file("sort.txt");
 ifstream out("out.txt");
 bool p=true;
 string s1,s2;
 while (!file.eof()&&!out.eof()){
 getline(file,s1);
  getline(out,s2);
  if (s1!=s2){
  p=false;
   break;
  }
 }
  file.close();
 out.close();
  REQUIRE(p==true);
}
