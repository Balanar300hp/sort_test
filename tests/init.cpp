#include "sort_test.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
 
SCENARIO("32mb", "[32mb]"){
 bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
 B obj("32","out",17);
 end = std::chrono::system_clock::now();
	cout <<"32MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}

SCENARIO("15mb", "[15mb]"){
 bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
B obj("15","out2",4);
 end = std::chrono::system_clock::now();
	cout <<"15MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}

SCENARIO("8mb", "[8mb]"){
bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
  B obj("8","out8",1);
 end = std::chrono::system_clock::now();
	cout <<"8MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}


