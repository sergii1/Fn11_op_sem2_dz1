#pragma once
#include <iostream>
using namespace std;
struct session
{
	int course;
	char group_code[9];
	char student_surname[12];
	char record_book[10];
	char subj_name[20];
	int mark;

	friend std::istream& operator>>(std::istream& p_In, session& p_rec) {
		cout << "\nВведите курс : ";
		p_In >> p_rec.course;
		cout << "\nВведите код группы : ";
		p_In >> p_rec.group_code;
		cout << "\nВведите фамилию студента : ";
		p_In >> p_rec.student_surname;
		cout << "\nВведите номер зачетки : ";
		p_In >> p_rec.record_book;
		cout << "\nВведите дисциплину : ";
		p_In >> p_rec.subj_name;
		cout << "\nВведите оценку : ";
		p_In >> p_rec.mark;
		cout << "\n";
		return p_In;
	}

};