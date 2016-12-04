#include "sort_test.cpp"
#include "time.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
SCENARIO("32mb", "[32mb]"){
 
 double startTime, endTime;

startTime = getCPUTime( );
 B obj("32","out",17);
 endTime = getCPUTime( );
 fprintf( stderr, "CPU time used for 32mb = %lf\n", (endTime - startTime) );
 
 
 endTime = getCPUTime( );
 
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
 // p=false;
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
 
 
  double startTime, endTime;

startTime = getCPUTime( );
 
  B obj("15","out2",4);
 endTime = getCPUTime( );
 fprintf( stderr, "CPU time used for 32mb = %lf\n", (endTime - startTime) );

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
  //p=false;
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
 
 
  double startTime, endTime;

startTime = getCPUTime( );
  B obj("8","out8",1);
 endTime = getCPUTime( );
 fprintf( stderr, "CPU time used for 32mb = %lf\n", (endTime - startTime) );

 ifstream hay("out8");
ifstream file("sort8");

int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
getline(file,s1);
 getline(hay,s2);
  i++;
  if (s1!=s2){
 // p=false;
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


