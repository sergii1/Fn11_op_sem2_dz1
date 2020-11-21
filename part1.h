#pragma once
#include <stdio.h>
#include <time.h>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>                          
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void outputData(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	char c;
	while (file.get(c))cout.put(c);

}
void outputVector(vector<int>fromf) {
	vector<int> ::const_iterator Citer;
	for (Citer = fromf.cbegin(); Citer != fromf.cend(); ++Citer) {
		cout << *Citer << " ";
	}
	cout << "\n";
}


//1.1.	Функция, выгружающая данные с использованием файловых потоков
void CreateData_s(const string& filename) {
	srand(time(NULL));
	ofstream file(filename);
	if (!file) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 100; ++i) {
		int a = rand() % 101 - 50;
		file << a << " ";
	}
}

//1.2.	Функция, использующая алгоритм generate для инициализации вспомогательного контейнера 
//и алгоритм copy для вывода его содержимого в файл с использованием потоковых итераторов
void CreateData_i(const string& filename) {
	vector<int> tofile(100);
	generate(tofile.begin(), tofile.end(), []() {return  rand() % 101 - 50; });
	/*for (auto iv : tofile) {
		std::cout << iv << " ";
	}
	std::cout << "\n";*/
	ofstream file2(filename);
	if (!file2) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	copy(tofile.begin(), tofile.end(), ostream_iterator<int>(file2, " "));

}

//2.1.	Функция, загружающая данные с использованием файловых потоков.
template<typename ContainerType>
void LoadData_s(ContainerType& container, const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	int n;
	while (!file.eof())
	{
		file >> n;
		container.push_back(n);

	}
}

//2.2 Функция, загружающая данные с использованием потоковых итераторов и алгоритма copy
template<typename ContainerType>
void LoadData_i(ContainerType& container, const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	copy(istream_iterator<ContainerType::value_type>(file), istream_iterator<ContainerType::value_type>(), back_inserter(container));
}


//3.1 шаблонная функция, принимающая последовательный контейнер данного типа. Должна добавлять в конец контейнера результата сумму и 
//среднее арифметическое элементов контейнера по абсолютной величине
template <class Type>
void Modify_1(Type& container) {
	int maximum = *max_element(container.begin(), container.end());
	int minimum = *min_element(container.begin(), container.end());
	int raznost = maximum - minimum;
	auto iter_1 = container.begin();
	while (iter_1 != container.end()) {
		if (*(iter_1) % 2 == 0)
			*iter_1 = raznost;
		iter_1++;
	}
	int sum = 0;
	float sr = 0;
	iter_1 = container.begin();
	while (iter_1 != container.end()) {
		sum += abs(*iter_1);
		iter_1++;
	}
	sr = float(sum) / 100.0;
	container.push_back(sum);
	container.push_back(sr);
}
//3.2 функция, принимающая аргументы-итераторы
template <typename IteratorType>
void Modify_2(IteratorType begin, IteratorType end)
{
	auto maximum = *begin;
	IteratorType iter = begin;
	while (iter != end) {
		if (maximum <= *iter)
			maximum = *begin;
		++iter;
	}
	iter = begin;
	auto minimum = *begin;
	while (iter != end) {
		if (minimum > *iter)
			minimum = *iter;
		++iter;
	}
	iter = begin;
	
	typename IteratorType::value_type raznost = maximum - minimum;
	while (iter != end) {
		if (*(iter) % 2 == 0)
			*iter = raznost;
		iter++;
	}
}
//3.3 функция, использующая алгоритм for_each(). Конкретную операцию передавать в виде функционального объекта
// или лямбда-функции
template <class Type>
void Modify_3(Type& container) {
	int maximum = *max_element(container.begin(), container.end());
	int minimum = *min_element(container.begin(), container.end());
	int raznost = maximum - minimum;
	for_each(container.begin(), container.end(), [&](auto &cur) { if (cur % 2 == 0) { cur = raznost; }});

}

//4.1 функция, использующая алгоритм transform() и потоковые итераторы для одновременного считывая данных из файла, их преобразования и 
// вывода в файл результата
template <typename IteratorType>
void Modify_4(const string& fileName, IteratorType begin, IteratorType end) {

	auto maximum = *begin;
//	int maximum = *max_element(begin(), end());

	IteratorType iter = begin;
	while (iter != end) {
		if (maximum <= *iter)
			maximum = *begin;
		++iter;
	}
	iter = begin;
	auto minimum = *begin;
	while (iter != end) {
		if (minimum > *iter)
			minimum = *iter;
		++iter;
	}
	iter = begin;
	int raznost = maximum - minimum;

	auto file = std::ofstream(fileName);
	transform(begin, end, std::ostream_iterator<int>(file, " "), [raznost](auto& i)
	{
		if ((i % 2) == 0)
			return i = raznost;
		return i;
	});




}
//4.1 Функция, выгружающая данные с использованием файловых потоков.
template<typename ContainerType>
void OutputResult_s(const string& filename, ContainerType& container) {
	srand(time(NULL));
	ofstream file(filename);
	if (!file) {
		cerr << " file can not be opened\"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	for (auto &a : container)
		file << a << ' ';
	file.close();

	cout << " Resalt " << endl;
	file.open(filename, ios::in);
	cout << file.rdbuf();
	file.close();
}

//4.2.	Функция, использующая алгоритм copy для вывода контейнера в файл с использованием потоковых итераторов
template <typename ContainerType>
void OutputResult_i(const string& filename, ContainerType& container)
{
	auto file = std::ofstream(filename);
	std::copy(container.begin(), container.end(), std::ostream_iterator<int>(file, " "));
	file.close();
	cout << " Resalt " << endl;
	ostream_iterator <int> input(cout, " ");
	copy(container.begin(), container.end(), input);
}
