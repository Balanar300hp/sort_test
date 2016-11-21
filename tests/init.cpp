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
 ifstream hay("out.txt"),file("sort.txt");
 if (!file.is_open()||!hay.is_open()){
 cout<<"FUCK YOU"<<endl;
 }
int i=0;
 bool p=true;
 string s1,s2;
 while (!file.eof()&&!hay.eof()){
 getline(file,s1);
 getline(hay,s2);
  i++;
  if (s1!=s2){
  p=false;
   cout<<i<<endl;
   cout<<s1<<endl;
   cout<<s2<<endl;
   break;
  }
 }
  file.close();
 hay.close();
 
 

  REQUIRE(p==true);
}
