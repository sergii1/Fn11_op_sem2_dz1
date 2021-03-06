#pragma once
#include "session_journal.h"
#include <cstring>
#include <fstream>
#include <iomanip>

void add_record(const char file_name[], const session& p_rec) {
	std::ofstream file(file_name , std::ios::app | std::ios::binary);
	if (file.is_open()) {
		file.write((char*)&p_rec, sizeof(p_rec));
	}
	else cout << "File not open";
}

void delete_record(const char file_name[], const char group_code[],const char record_book[], const char subj_name[]){
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

void change_record(const char file_name[], const char group_code[], const char record_book[], const char subj_name[], const session& p_rec = session() ) {
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

void find_record(const char file_name[], const char group_code[], const char record_book[], const char subj_name[]) {
	std::ofstream fileBuff("Find_Result", std::ios::out | std::ios_base::binary);
	std::ifstream file(file_name, std::ios_base::binary);
	if (file.is_open()) {
		session rec;
		while (file.read((char*)&rec, sizeof(rec))) {
			//file.read((char*)&rec, sizeof(rec));
			if ((strcmp(rec.group_code, group_code) == 0) && (strcmp(rec.record_book, record_book) == 0) && (strcmp(rec.subj_name, subj_name) == 0))
				fileBuff.write((char *)&rec, sizeof(rec));
		}
      cout << "Найденные записи выведены в файл Find_Result" << std::endl;
	}
	else std::cout << "File not found" << std::endl;
	file.close();
	fileBuff.close();
}

void toText(const char fileName[]) {
	session rec;
	std::ifstream file(fileName, std::ios_base::binary);
	std::ofstream fileText(fileName + std::string("_TEXT.txt"));
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