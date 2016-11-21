#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <locale> 
#include <iterator> 
#include <algorithm> 
#include <cstdio> 
#include <queue> 

using namespace std;

struct A {
public:
	int index;
	string str;
	A(const string s, const size_t i) : str(s), index(i) {}
	bool operator < (const A& s) const
	{
		return (str > s.str);
	}
};

class B {
public:
	B(string name_main_file,string out_file,size_t buff_size);
	auto division()->void;
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto file_sort()->void;
	auto remove_temp_files()->void;
	~B();
private:
	fstream file;
	string s_out;
	size_t buffer, count_of_files, closed_files;
	vector<string> lines;
	vector<string> file_names;
	priority_queue<A> end_sorting;
};



inline B::~B() {
	file_names.clear();
}

inline B::B(string name_main_file,string out_file,size_t buff_size) :file(name_main_file), s_out(out_file), count_of_files(0), closed_files(0) {
	buffer=buff_size*1024*1024;
	if (file.is_open()) {
		division();
	}
};

inline auto B::make_file(string name_file)->void {
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

inline auto B::file_size(string name_file)->size_t {
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;
}



inline auto B::remove_temp_files()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		if (remove(file_names[i].c_str()) == -1) {
			throw;
		}
		else {
			cout << "Gj";
		}
	}

}




inline auto B::file_sort()->void {
	ofstream f12(s_out);
	string str;
	ifstream *streams = new ifstream[count_of_files];
	for (int i = 0; i < count_of_files; ++i) {
		streams[i].open(file_names[i]);
		getline(streams[i], str);
		A ff(str, i);
		end_sorting.push(ff);
	}
	
	while (!end_sorting.empty()) {
		A ff = end_sorting.top();
		end_sorting.pop();
		if (ff.str != "") f12 << ff.str << endl;

		if (!streams[ff.index].eof())
		{
			getline(streams[ff.index], ff.str);
			end_sorting.push(ff);
		}
	}
	
	for (int i = 0; i < count_of_files; ++i) streams[i].close();
	f12.close();
	remove_temp_files();
	
}


inline auto B::division()->void {
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
}
