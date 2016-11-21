#include "sort_test.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <locale> 
using namespace std;
 
SCENARIO("count111", "[count1111]"){
 setlocale(LC_ALL, "Russian");
 B obj("names.txt",1048576);
 ifstream file("sort.txt");
 ifstream ff("out.txt");

 bool p=true;
 string s1,s2;
 while (!file.eof()&&!ff.eof()){
 getline(file,s1);
  getline(ff,s2);
    cout<<s1<<endl;
  cout<<s2<<endl;
  if (s1!=s2){
  p=false;
   break;
  }
 }
  file.close();
 ff.close();
 
 

  REQUIRE(p==true);
}
