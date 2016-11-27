#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 

#include <iterator> 
#include <algorithm> 
#include <queue> 
#include <memory>



using namespace std;

struct person {
	string surname, name;
	short age;
	size_t size() const
	{
		return (name.size() + surname.size() + sizeof(short)+2*sizeof(" "));
	}
};

bool operator <(const person& s1, const person& s2)
{
	return (s1.name < s2.name);
}

bool operator >(const person& s1, const person& s2)
{
	return (s1.name > s2.name);
}

istream & operator >> (istream & in, person & s)
{
	in >> s.surname >> s.name >> (short)s.age;
	return in;
}
ostream & operator<<(ostream & out, person const & s)
{
	out << s.surname << " " << s.name << " "  << s.age;
	return out;
}



struct A {
public:
	ifstream *f;
	person s;
	A(const person& s_, ifstream* f_) : s(s_), f(f_) {}
};

bool operator < (const A& s1, const A& s2)// оператор для структуры А 
{
	return (s1.s > s2.s);
}


class B {
public:
	B(string name_main_file, string out_file, size_t buff_size);
	auto division()->void;
	auto make_file(string name_file)->void;
	auto file_sort()->void;
	~B();
private:
	string s_out, s_in, str;
	size_t count_of_files;
	vector<string> file_names;
	vector<person> pers;
	uint_fast64_t buffer;
};



inline B::~B() {
	file_names.clear();
}

inline B::B(string name_main_file, string out_file, size_t buff_size) :s_in(name_main_file), s_out(out_file), count_of_files(0), buffer(buff_size * 1024 * 1024*0.8) {
	division();
};

inline auto B::make_file(string name_file)->void {
	file_names.push_back(name_file);
	std::sort(pers.begin(), pers.end(), [&](person &A, person &B) {
		if (A.name == B.name) {
			return A.surname < B.surname;
		}
		return A.name < B.name;
	});
	ofstream temp(name_file, ios::binary);
	for (auto i : pers)
	{
		if (i.surname != "") temp << i << endl;
	}
	temp.close();
	pers.shrink_to_fit();
	pers.clear();
}





inline auto B::file_sort()->void {
	priority_queue<A> end_sorting;

	for (int i = 0; i < count_of_files; ++i) {
		ifstream* f_ = new ifstream(file_names[i], ios::binary);
		person temp_s;
		*f_ >> temp_s;
		A ff(temp_s, f_);
		end_sorting.push(ff);
	}

	ofstream f12(s_out, ios::binary);
	while (!end_sorting.empty()) {
		A ff = end_sorting.top();
		end_sorting.pop();
		if (ff.s.surname != "") f12 << ff.s << endl;

		if (!(*ff.f).eof())
		{
			*ff.f >> ff.s;
			end_sorting.push(ff);
		}
		else {
			(*(ff.f)).close();
		}
	}
	f12.close();


	for (int i = 0; i < file_names.size(); ++i) {
		remove(file_names[i].c_str());
	}

}



inline auto B::division()->void {
	size_t i(0);
	person chel;
	ifstream file(s_in, ios::binary);
	while (!file.eof()) {
		file >> chel;
		i += chel.size();
		if (i<buffer) {
			pers.push_back(chel);
		}else {
			count_of_files++;
			make_file(to_string(count_of_files));
			pers.push_back(chel);
			i = chel.size();
		}
	}
	file.close();
	if (!pers.empty()) {
		count_of_files++;
		make_file(to_string(count_of_files));
	}
	file_sort();
}

