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
	ifstream *f;
	string str;
	A(const string& s, ifstream* f_) : str(s), f(f_) {}
	bool operator < (const A& s) const
	{
		return (str > s.str);
	}
};

class B {
public:
	B(string name_main_file, string out_file, size_t buff_size);
	auto division()->void;
	auto make_file(string name_file)->void;
	auto file_sort()->void;
	auto remove_temp_files()->void;
	~B();
private:
	string s_out,s_in,str;
	size_t buffer, count_of_files, closed_files,temp_size_lines;
	vector<string> lines;
	vector<string> file_names;
	priority_queue<A> end_sorting;
};



inline B::~B() {
	file_names.clear();
}

inline B::B(string name_main_file, string out_file, size_t buff_size) :s_in(name_main_file), s_out(out_file), count_of_files(0), closed_files(0),buffer(buff_size*1024*1024),temp_size_lines(0) {
		division();
};

inline auto B::make_file(string name_file)->void {
	file_names.push_back(name_file);
	std::sort(lines.begin(), lines.end());
	ofstream temp(name_file);
	for (auto i : lines)
	{
		temp << i<<"\n";
	}
	temp.close();
	lines.clear();
}





inline auto B::remove_temp_files()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		remove(file_names[i].c_str());
	}
}


inline auto B::file_sort()->void {
	ofstream f12(s_out);
	for (int i = 0; i < count_of_files; ++i) {
		ifstream* f_ = new ifstream(file_names[i]);
		getline(*f_, str);
		A ff(str, f_);
		end_sorting.push(ff);
	}

	while (!end_sorting.empty()) {
		A ff = end_sorting.top();
		end_sorting.pop();
		if (ff.str != "") f12 << ff.str << endl;

		if (!(*ff.f).eof())
		{
			getline(*ff.f, ff.str);
			end_sorting.push(ff);
		}else{
			(*(ff.f)).close();
		}
	}
	f12.close();

	for (int i = 0; i < file_names.size(); ++i) {
		remove(file_names[i].c_str());
	}

}


inline auto B::division()->void {
	ifstream file(s_in);
	while (!file.eof()) {
		getline(file, str);
		temp_size_lines += str.size();


		if (temp_size_lines <= buffer) {
			lines.push_back(str);
		}
		else {
			count_of_files++;
			make_file(to_string(count_of_files));
			lines.push_back(str);
			temp_size_lines = str.size();
		}
	}
	file.close();


	if (lines.size()) {
		count_of_files++;
		make_file(to_string(count_of_files));
	}
	file_sort();
}
