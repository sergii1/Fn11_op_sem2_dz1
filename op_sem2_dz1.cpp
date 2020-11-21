#include "pch.h"
#include <iostream>
#include "part1.h"
#include <conio.h>
#include "part2.h"
#include "part2V2.h"
using namespace std;
int main()
{
	//const string filename2 = "oops";
	//CreateData_i(filename2);
	//outputData(filename2);
	//vector<int>fromf;
	///*LoadData_s(fromf, filename2);*/
	//LoadData_i(fromf, filename2);
	//cout << "\n";
	//outputVector(fromf);
	//const string filename3 = "m4";
	////Modify_1(fromf);
	////Modify_3(fromf);
	////Modify_2( fromf.begin(), fromf.end());
	//Modify_4(filename3, fromf.begin(), fromf.end());
	//OutputResult_s(filename3, fromf);

	//////OutputResult_i(filename2, fromf);
	////OutputResult_s(filename2, fromf);
	//session p{ 3,"FN11-32B","CHEPURNOI","11111111","MATAN",4 };
	setlocale(0, "RUSSIAN");

	/*add_record("data", { 3,"fn11-32b","chepurnoi","11111111","matan",4 });
	add_record("data", { 3,"fn11-33b","petrov","11112222","linal",4 });
	add_record("data", { 3,"fn11-33b","shamshidov","1123112","angem",5 });
	add_record("data", { 3,"fn11-31b","prusov","1123119","c++",5 });
	find_record("data", "fn11-31b", "1123119", "c++");
	toText("data");
	toText("find_result");
	delete_record( "data","fn11-32b", "11111111", "matan");
	toText("BUFFER");*/
	
	/*char f[] = "data";
	file_work fw(f);
	fw.add_record("data", { 1,"fn11-32b","chepurnoi","11111111","matan",4 });
	fw.add_record("data", { 2,"fn11-33b","petrov","11112222","linal",4 });
	fw.add_record("data", { 4,"fn11-33b","shamshidov","1123112","angem",5 });
	fw.add_record("data", { 5,"fn11-31b","prusov","1123119","c++",5 });
	cout << std::boolalpha;
	fw.search_element([](session el, session el2) {
		bool a = el.course >el2.course;
		cout << a <<endl;
		return a; },1);
	fw.toText("data");
	fw.toText("Find_Result");
	fw.delete_record("fn11-32b", "11111111", "matan");
	fw.toText( "BUFFER");*/
	char f[] = "data";
	file_work fw(f);
	int ch = 1;
	while (ch != 0) {
		system("cls");
		cout << "0 - выход" << endl;
		cout << "1 - первая часть дз" << endl;
		cout << "2 - вторая часть дз" << endl;
		cin >> ch;
		vector<int> vect;
		switch (ch){
		
		case 1: {
			while (ch != 0) {
				system("cls");
				cout << "0 - выход " << endl;
				cout << "1 - createData() v1 - файловые потоки" << endl;
				cout << "2 - createData() v2 - потоковые итераторы " << endl;
				cout << "3 - loadData() v1 - файловые потоки" << endl;
				cout << "4 - loadData() v2 - потоковые итераторы " << endl;
				cout << "5 - modify1 " << endl;
				cout << "6 - modify2 " << endl;
				cout << "7 - modify3 " << endl;
				cout << "8 - modify4 " << endl;
				cout << "9 - OutputResult() v1 - файловые потоки" << endl;
				cout << "10 - OutputResult() v2 - потоковые итераторы " << endl;
				cin >> ch;
				switch (ch) {
				case 1: {
					CreateData_s("file1");
				}
						break;

				case 2: {
					CreateData_i("file2");
				}
						break;

				case 3: {
					LoadData_i(vect, "file1");
					outputVector(vect);
					_getch();
				}
						break;

				case 4: {
					LoadData_i(vect, "file1");
					outputVector(vect);
					_getch();
				}
						break;

				case 5: {
					Modify_1(vect);
					outputVector(vect);
					_getch();
				}
						break;

				case 6: {
					Modify_2(vect.begin(), vect.end());
					outputVector(vect);
					_getch();
				}
						break;

				case 7: {
					Modify_3(vect);
					outputVector(vect);
					_getch();
				}
						break;

				case 8: {
					Modify_4("modif_4", vect.begin(), vect.end());
					OutputResult_i("modif_4", vect);
					_getch();
				}
						break;

				case 9: {
					OutputResult_s("result1", vect);
				
					_getch();
				}
						break;

				case 10: {
					OutputResult_i("result1", vect);
					
					_getch();
				}
						 break;

				}
			}
		}
		break;

		case 2: {
			while (ch != 0) {
				system("cls");
				cout << "0 - выход" << endl;
				cout << "1 - добавить запись" << endl;
				cout << "2 - удалить запись " << endl;
				cout << "3 - изменить запись " << endl;
				cout << "4 - поиск " << endl;
				cout << "5 - вывод в файл" << endl;
				cout << "6 - печать на консоль" << endl;
				cin >> ch;
				switch (ch) {
				case 1: {
					session tmp;
					cin >> tmp;
					fw.add_record(f,tmp);
					_getch();
				}
						break;

				case 2: {
					char group_code[9];
					char record_book[10];
					char subj_name[20];
					cout << "введите код группы : ";
					cin >> group_code;
					cout << endl;

					cout << "введите номер зачетки : ";
					cin >> record_book;
					cout << endl;
					
					cout << "введите название предмета : ";
					cin >> subj_name;
					cout << endl;

					fw.delete_record(group_code,record_book,subj_name);
					_getch();
				}
						break;

				case 3: {
					char group_code[9];
					char record_book[10];
					char subj_name[20];
					cout << "введите код группы изменяемого товарища: ";
					cin >> group_code;
					cout << endl;

					cout << "введите номер зачетки изменяемого товарища: ";
					cin >> record_book;
					cout << endl;

					cout << "введите название предмета изменяемого товарища: ";
					cin >> subj_name;
					cout << endl;

					cout << "введите новые данные" << endl;
					session tmp;
					cin >> tmp;
					fw.change_record("data", group_code, record_book, subj_name, tmp);
					_getch();
				}
						break;

				case 4: {

					fw.search_element([](session el, session el2) {
						bool a = el.course > el2.course;
						//cout << a << endl;
						return a; }, 1);
					_getch();
				}
						break;

				case 5: {
					fw.toText("data");
					_getch();
				}
						break;

				case 6: {
					fw.toConsole("data");
					_getch();
				}
						break;
				}
			}
		}
		}
	}
	_getch();
	return 0;
}


