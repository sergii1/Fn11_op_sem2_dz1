#pragma once
#include <string>
#include <iostream>
#include "session_journal.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iomanip>


class file_work{

	char file_name[20];
public:
	file_work(char* p_file_name) {

		for (int i = 0; i < strlen(p_file_name); ++i)
			file_name[i] = p_file_name[i];
		file_name[strlen(p_file_name)] = '\0';
		std::cout << file_name;
	}

	template <typename Pred>
	vector<session> search_element(Pred pred,int find_id){

		vector<session> res;
		std::ofstream fileBuff("Find_Result", std::ios::out | std::ios_base::binary);
		std::ifstream file(file_name, std::ios_base::binary);
		if (!file.is_open())
			return res;
		session rec;
		session tmp;
		switch (find_id)
		{
		
		//поиск по курсу
		case 1: {
			cout << "введите номер курса : ";
			cin>>tmp.course;
			//cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec,tmp))
					res.push_back(rec);
			}
		}
		break;
		
		//поиск по коду группы
		case 2: {
			cout << "введите код группы : ";
			cin >> tmp.group_code;
			cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec, tmp))
					res.push_back(rec);
			}
		}
		break;
		
		//поиск по фамилии
		case 3: {
			cout << "введите фамилию : ";
			cin >> tmp.student_surname;
			cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec, tmp))
					res.push_back(rec);
			}
		}
		break;

		//поиск по зачетке
		case 4: {
			cout << "введите номер зачетки : ";
			cin >> tmp.record_book;
			cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec, tmp))
					res.push_back(rec);
			}
		}
		break;
		
		//поиск по предмету
		case 5: {
			cout << "введите дисциплину : ";
			cin >> tmp.subj_name;
			cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec, tmp))
					res.push_back(rec);
			}
		}
		break;
		
		//поиск по оценке		
		case 6: {
			cout << "введите оценку : ";
			cin >> tmp.mark;
			cout << endl;
			while (file.read((char*)&rec, sizeof(rec))) {
				if (pred(rec, tmp))
					res.push_back(rec);
			}
		}
		
		break;
		default:
			break;
		}
		
		for (auto& a : res) {
			fileBuff.write((char *)&a, sizeof(a));
		}
		file.close();
		fileBuff.close();
		return res;
	}

	void add_record(const char file_name[], const session& p_rec) {
		std::ofstream file(file_name, std::ios::app | std::ios::binary);
		if (file.is_open()) {
			file.write((char*)&p_rec, sizeof(p_rec));
		}
		else cout << "File not open";
		file.close();
	}

	void change_record(const char file_name[], const char group_code[], const char record_book[], const char subj_name[], const session& p_rec = session()) {
		std::ofstream fileBuff("BUFFER", std::ios::out | std::ios_base::binary);
		std::ifstream file(file_name, std::ios_base::binary);
		if (file.is_open()) {
			session rec;
			while (!file.eof()) {
				file.read((char*)&rec, sizeof(rec));
				if ((strcmp(rec.group_code, group_code) != 0) || (strcmp(rec.record_book, record_book) != 0) || (strcmp(rec.subj_name, subj_name) != 0))
					fileBuff.write((char *)&rec, sizeof(rec));
				else
					fileBuff.write((char *)&p_rec, sizeof(p_rec));
			}
			remove("file_name");
			rename("BUFFER", "file_name");
		}
		else std::cout << "File not found" << std::endl;
		file.close();
		fileBuff.close();
	}


	void delete_record( const char group_code[], const char record_book[], const char subj_name[]) {
		std::ofstream fileBuff("BUFFER", std::ios::out | std::ios_base::binary);
		std::ifstream file(file_name, std::ios_base::binary);
		if (file.is_open()) {
			session rec;
			while (file.read((char*)&rec, sizeof(rec))) {
				if ((strcmp(rec.group_code, group_code) != 0) || (strcmp(rec.record_book, record_book) != 0) || (strcmp(rec.subj_name, subj_name) != 0))
					fileBuff.write((char *)&rec, sizeof(rec));
			}
			file.close();
			fileBuff.close();
			remove("file_name");
			rename("BUFFER", file_name);
		}
		else std::cout << "File not found" << std::endl;
		file.close();
		fileBuff.close();
	}

	void toText(const char p_file_name[]) {
		session rec;
		std::ifstream file(p_file_name, std::ios_base::binary);
		std::ofstream fileText(p_file_name + std::string("_TEXT.txt"));
		if (file.is_open()) {
			fileText.width(92);
			fileText.fill('-');
			fileText << "\n";
			fileText.fill(' ');
			fileText << std::setw(10) << std::left << "course";
			fileText << "|";
			fileText << std::setw(15) << std::left << "group_code";
			fileText << "|";
			fileText << std::setw(20) << std::left << "student_surname";
			fileText << "|";
			fileText << std::setw(10) << std::left << "record_book";
			fileText << "|";
			fileText << std::setw(20) << std::left << "subj_name";
			fileText << "|";
			fileText << std::setw(10) << std::left << "mark";
			fileText << "|";
			fileText << std::right << "\n";
			fileText.width(92);
			fileText.fill('-');
			fileText << std::right << "\n";
			while (file.read((char*)&rec, sizeof(rec))) {
				//file.read((char*)&rec, sizeof(rec));
				fileText.fill(' ');
				fileText << std::setw(10) << std::left << rec.course;
				fileText << "|";
				fileText << std::setw(15) << std::left << rec.group_code;
				fileText << "|";
				fileText << std::setw(20) << std::left << rec.student_surname;
				fileText << "|";
				fileText << std::setw(10) << std::left << rec.record_book;
				fileText << "|";
				fileText << std::setw(20) << std::left << rec.subj_name;
				fileText << "|";
				fileText << std::setw(10) << std::left << rec.mark;
				fileText << "|";
				fileText << std::setw(10) << std::endl;
			}
			fileText.width(92);
			fileText.fill('-');
			fileText << std::right << "\n";
			fileText.close();
		}
		else std::cout << "File not found" << std::endl;
	}

	void toConsole(const char p_file_name[]) {
		session rec;
		std::ifstream file(p_file_name, std::ios_base::binary);
		if (file.is_open()) {
			cout.width(92);
			cout.fill('-');
			cout << "\n";
			cout.fill(' ');
			cout << std::setw(10) << std::left << "course";
			cout << "|";
			cout << std::setw(15) << std::left << "group_code";
			cout << "|";
			cout << std::setw(20) << std::left << "student_surname";
			cout << "|";
			cout << std::setw(10) << std::left << "record_book";
			cout << "|";
			cout << std::setw(20) << std::left << "subj_name";
			cout << "|";
			cout << std::setw(10) << std::left << "mark";
			cout << "|";
			cout << std::right << "\n";
			cout.width(92);
			cout.fill('-');
			cout << std::right << "\n";
			while (file.read((char*)&rec, sizeof(rec))) {
				//file.read((char*)&rec, sizeof(rec));
				cout.fill(' ');
				cout << std::setw(10) << std::left << rec.course;
				cout << "|";
				cout << std::setw(15) << std::left << rec.group_code;
				cout << "|";
				cout << std::setw(20) << std::left << rec.student_surname;
				cout << "|";
				cout << std::setw(10) << std::left << rec.record_book;
				cout << "|";
				cout << std::setw(20) << std::left << rec.subj_name;
				cout << "|";
				cout << std::setw(10) << std::left << rec.mark;
				cout << "|";
				cout << std::setw(10) << std::endl;
			}
			cout.width(92);
			cout.fill('-');
			cout << std::right << "\n";
		}
		else std::cout << "File not found" << std::endl;
	}
};