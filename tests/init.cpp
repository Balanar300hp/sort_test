#include "sort_test.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <locale> 
using namespace std;
 
SCENARIO("count111", "[count1111]"){
 setlocale(LC_ALL, "Russian");
  B obj("names.txt");
 ifstream file("sort.txt");
 ifstream out("out.txt");
 bool p=true;
 string s1,s2;
 while (!file.eof()&&!out.eof()){
 getline(file,s1);
  getline(out,s2);
    cout<<s1<<endl;
  cout<<s2<<endl;
  if (s1!=s2){
  p=false;
   break;
  }
 }
  file.close();
 out.close();
 
 
 string vld;
 ifstream ff("1.txt");
 while (!ff.eof()){
 getline (ff,vld);
  cout<<vld<<endl;
 }
  REQUIRE(p==true);
}
