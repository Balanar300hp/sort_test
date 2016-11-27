#include "sort_test.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <locale> 
using namespace std;
 
SCENARIO("32mb", "[32mb]"){
 setlocale(LC_ALL, "Russian");
 B obj("32","out",17);
 ifstream hay("out");
ifstream file("sort32");

int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
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

SCENARIO("15mb", "[15mb]"){
 setlocale(LC_ALL, "Russian");
 B obj("15","out2",4);
 ifstream hay("out2");
ifstream file("sort15");

int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
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

SCENARIO("8mb", "[8mb]"){
 setlocale(LC_ALL, "Russian");
 B obj("8","out8",1);
 ifstream hay("out3");
ifstream file("sort2");

int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
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


