#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <locale> 
#include <iterator> 
#include <algorithm> 
#include <cstdio> 
#include <stdlib.h> 
#include <windows.h> 
#include <queue> 

using namespace std;

struct A {
public:
	int index;
	string str;
};





struct Compare {
	bool operator()(const A& a, const A& b) {
		return a.str>b.str;
	}
};

class B {
public:
	B(string name_main_file);
	auto division()->void;
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto file_sort()->void;
	auto write_to_out(string line)->void;
	auto remove_temp_files()->void;
	~B();
private:
	fstream file;
	size_t buffer, count_of_files, closed_files;
	bool out;
	vector<string> lines;
	vector<string> file_names;
	priority_queue<A,vector<A>,Compare> end_sorting;
};



B::~B() {
	file_names.clear();
}

B::B(string name_main_file) :file(name_main_file), buffer(100), count_of_files(0), closed_files(0) {
	if (file.is_open()) {
		out = true;
		division();
	}
};

auto B::make_file(string name_file)->void {
	file_names.push_back(name_file);
	std::sort(lines.begin(), lines.end());
	ofstream temp(name_file);
	for (auto i : lines)
	{
		temp << i;
		if (i != *(--lines.end())) temp << endl;
	}
	temp.close();
	lines.clear();
}

auto B::file_size(string name_file)->size_t { 
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;

}

auto B::write_to_out(string line)->void {
	ofstream file("out.txt", ios::app);
	file << line << endl;
	file.close();

}

auto B::remove_temp_files()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		if (remove(file_names[i].c_str()) == -1) {
			throw;
		}
		else {
			cout << "Gj";
		}
	}

}




auto B::file_sort()->void {
	
	A *mass = new A[count_of_files];
	ifstream *streams = new ifstream[count_of_files];
	for (int i = 0; i < count_of_files; ++i) {
		streams[i].open(file_names[i]);
		getline(streams[i], mass[i].str);
		mass[i].index = i;
		end_sorting.push(mass[i]);
	}
	
	while (out) {
		
		int t_in = end_sorting.top().index;
 		write_to_out(end_sorting.top().str);
		
		if (!streams[t_in].eof()) {
			getline(streams[t_in],mass[t_in].str);
			end_sorting.pop();
			end_sorting.push(mass[t_in]);
		}
		else {
			closed_files++;
			streams[t_in].close();
			end_sorting.pop();
			
			if (closed_files == count_of_files) { out = false; };

		}
	}
	remove_temp_files();
}


auto B::division()->void {//TESTED 
	string line_of_file;
	size_t temp_size_files = 0;
	while (!file.eof()) {
		getline(file, line_of_file);
		temp_size_files += line_of_file.size();


		if (temp_size_files <= buffer) {
			lines.push_back(line_of_file);
		}
		else {
			count_of_files++;

			make_file(to_string(count_of_files) + ".txt");
			lines.push_back(line_of_file);
			temp_size_files = line_of_file.size();
		}
	}
	file.close();

	if (lines.size()) {
		count_of_files++;
		make_file(to_string(count_of_files) + ".txt");
	}


	file_sort();
};


/*int main()
{
	setlocale(LC_ALL, "Russian");
	B obj("names.txt");




	system("pause");
	return 0;
}*/
