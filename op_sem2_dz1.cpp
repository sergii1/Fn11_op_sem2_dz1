#include <iostream>
#include "part1.h"
//#include <conio.h>
#include "part2.h"
#include "part2V2.h"
using namespace std;
int main()
{

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
					CreateData_i("file1");
				}
						break;

				case 3: {
					LoadData_s(vect, "file1");
					outputVector(vect);
					getchar();
				}
						break;

				case 4: {
					LoadData_i(vect, "file1");
					outputVector(vect);
					getchar();
				}
						break;

				case 5: {
					Modify_1(vect);
					outputVector(vect);
					getchar();
				}
						break;

				case 6: {
					Modify_2(vect.begin(), vect.end());
					outputVector(vect);
					getchar();
				}
						break;

				case 7: {
					Modify_3(vect);
					outputVector(vect);
					getchar();
				}
						break;

				case 8: {
					Modify_4("modif_4", vect.begin(), vect.end());
					OutputResult_i("modif_4", vect);
					getchar();
				}
						break;

				case 9: {
					OutputResult_s("result1", vect);
				
					getchar();
				}
						break;

				case 10: {
					OutputResult_i("result1", vect);
					
					getchar();
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
					getchar();
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
					getchar();
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
					getchar();
				}
						break;

				case 4: {

					fw.search_element([](session el) {
						bool a = el.course > 1;
						return a; });

					getchar();
				}
						break;

				case 5: {
					fw.toText("data");
					getchar();
				}
						break;

				case 6: {
					fw.toConsole("data");
					getchar();
				}
						break;
				}
			}
		}
		}
	}
	getchar();
	return 0;
}


