#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <iterator>
#include <algorithm>
#include <cstdio>
 
  
  //WORK POS
using namespace std;

class B {
public:
	B(string name_main_file);//открываем исходный файл
	auto division()->void; // разделение файла на подфайлы
	auto file_size(string name_file)->size_t;//проверка размера файла
	auto make_file(string name_file)->void;//создание временных файлов
	auto file_sort()->void;//конечная сортировка временных файлов в выходной файл
	auto write_to_out(string line)->void;//запись в выходной файл
	auto remove_temp_files()->void;//удаление временных файлов
	~B();
private:
	fstream file;
	size_t buffer, count_of_files, closed_files;
	bool out;
	vector<string> lines;
	vector<string> file_names;//имена временных файлов
};

B::~B() {
	file_names.clear();
}

B::B(string name_main_file) :file(name_main_file), buffer(100), count_of_files(0), closed_files(0) {//TESTED
	if (file.is_open()) {
		out=true;
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

auto B::write_to_out(string line)->void {//TESTED
	ofstream out("out.txt", ios::app);
	file << line << endl;
	file.close();

}

auto B::remove_temp_files()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		if (remove(file_names[i].c_str()) == -1) {
			cout<<"Error";
		}
		else {
			cout << "Gj";
		}
	}

}


auto B::file_sort()->void {

	ifstream *files_streams = new ifstream[count_of_files];
	for (int i = 0; i < count_of_files; ++i) {
		files_streams[i].open(file_names[i]);
	}

	string *top_line = new string[count_of_files];
	for (int i = 0; i < count_of_files; ++i)
	{
		getline(files_streams[i], top_line[i]);
	}

	while (out) {
		string temp_min_line = top_line[0];
		int num_min_line = 0;

		for (int i = 0; i < count_of_files; ++i)
		{
			if (top_line[i] < temp_min_line)
			{
				temp_min_line = top_line[i];
				num_min_line = i;
			}
		}
		
		write_to_out(temp_min_line);

		if (!files_streams[num_min_line].eof())
		{
			getline(files_streams[num_min_line], top_line[num_min_line]);
		}
		else {
			
			closed_files++;
			if (closed_files == count_of_files) { out = false; };
		}

	}

	for(int i=0;i<count_of_files;++i) files_streams[i].close();

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
