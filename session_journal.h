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
		cout << "\n������� ���� : ";
		p_In >> p_rec.course;
		cout << "\n������� ��� ������ : ";
		p_In >> p_rec.group_code;
		cout << "\n������� ������� �������� : ";
		p_In >> p_rec.student_surname;
		cout << "\n������� ����� ������� : ";
		p_In >> p_rec.record_book;
		cout << "\n������� ���������� : ";
		p_In >> p_rec.subj_name;
		cout << "\n������� ������ : ";
		p_In >> p_rec.mark;
		cout << "\n";
		return p_In;
	}

	friend std::ifstream& operator>>(std::ifstream& p_In, session& p_rec) {
		cout << "\n������� ���� : ";
		p_In >> p_rec.course;
		cout << "\n������� ��� ������ : ";
		p_In >> p_rec.group_code;
		cout << "\n������� ������� �������� : ";
		p_In >> p_rec.student_surname;
		cout << "\n������� ����� ������� : ";
		p_In >> p_rec.record_book;
		cout << "\n������� ���������� : ";
		p_In >> p_rec.subj_name;
		cout << "\n������� ������ : ";
		p_In >> p_rec.mark;
		cout << "\n";
		return p_In;
	}

	/*friend std::ofstream& operator <<(std::ofstream& p_out, const session& p_rec) {
		p_out << p_rec.course << p_rec.group_code << p_rec.student_surname << p_rec.record_book << p_rec.subj_name << p_rec.mark;
		return p_out;
	}*/
};