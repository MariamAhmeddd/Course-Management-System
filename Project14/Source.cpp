#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>

using namespace std;

//data of student
struct student
{
	string name;
	int id = 0;
}student;


//data of course
struct data_of_course
{
	int id = 0;
	string name;
	string instractor_name;
	int course_grade = 0;
}course;

void main_menu();

//functions of the student
void student_menu();
void course_menu();
void add_student();
void display_student();
void modify_student();
void search_student();
void delet_student();

//functions of the course
void add_courses();
void display_courses();
void modify_courses();
void search_courses();
void delet_courses();
void add_student_to_spacefic_course();


int main()
{
	main_menu();

	return 0;
}


void main_menu()
{
	system("cls");
	int num;
	cout << "\t\t\t\t\t\t Welcome To Our Project \n";
	cout << "\n";
	cout << "1. Student \n";
	cout << "2. Courses \n";
	cout << "Enter your Choice : ";
	cin >> num;
	switch (num)
	{
	case 1:
		student_menu();
		break;
	case 2:
		course_menu();
		break;
	default:
		cout << "Invaliad Number Please try again... \n";
		break;
	}
}

/********************************************""""""""""""""functions of student"""""""************************************************/

void student_menu()
{
menustart:
	int choice;
	system("cls");
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t ------------------------Student Menu---------------------- \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t 1. Enter new student \n";
	cout << "\t\t\t\t 2. Display student data \n";
	cout << "\t\t\t\t 3. Modify student \n";
	cout << "\t\t\t\t 4. Search student \n";
	cout << "\t\t\t\t 5. Delete student \n";
	cout << "\t\t\t\t 6. Exit \n";
	cout << "\t\t\t\t 7. Back to main menu \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t ------------Choice Operation [1, 2 , 3 , 4 , 5 , 6 , 7]----------- \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "Enter your Choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		add_student();
		break;
	case 2:
		display_student();
		break;
	case 3:
		modify_student();
		break;
	case 4:
		search_student();
		break;
	case 5:
		delet_student();
		break;
	case 6:
		cout << "We Hope You Found It Useful :)" << endl;
		exit(0);
	case 7:
		main_menu();
		break;
	default:
		cout << "Invaild Number Please try again...";
		break;
	}
	_getch();
	goto menustart;
}


void add_student()
{
	system("cls");
	fstream file;
	cout << "Enter Student Name : ";
	cin >> student.name;
	cout << "Enter Student ID : ";
	cin >> student.id;
	file.open("student_data.txt", ios::app | ios::out);
	file << student.name << " " << student.id << " " <<  endl;
	file.close();
	display_courses();
}


void display_student()
{
	system("cls");
	fstream file;
	int counter = 0;
	cout << "\t\t\t\t\t\t -Student Data- \n";
	file.open("student_data.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		file >> student.name >> student.id;
		while (!file.eof())
		{
			counter += 1;
			cout << "\n\nStudent Number : " << counter << endl;
			cout << "Student Name : " << student.name << endl;
			cout << "Student ID : " << student.id << endl;
			file >> student.name >> student.id;
		}
		if (counter == 0)
		{
			cout << "No Data \n";
		}
	}
	file.close();
}


void modify_student()
{
	system("cls");
	fstream file, file1;
	long long id;
	int founded = 0;
	string a;
	int b = 0;
	cout << "\t\t\t\t\t\t -Modify Student Data- \n";
	file.open("student_data.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		cout << "Enter Student ID : ";
		cin >> id;
		file1.open("stu_data.txt", ios::app | ios::out);
		file >> student.name >> student.id;
		while (!file.eof())
		{
			if (student.id != id)
			{
				file1 << student.name << " " << student.id << endl;
			}
			else
			{
				cout << "Student Name : " << endl;
				cin >> student.name;
				a = student.name;
				cout << "Student ID : " << endl;
				cin >> student.id;
				b = student.id;
				file1 << student.name << " " << student.id << endl;
				founded++;
			}
			file >> student.name >> student.id;
		}
		if (founded == 0)
		{
			cout << "This ID Is Not Found \n";
		}
		file1.close();
		file.close();
		remove("student_data.txt");
		rename("stu_data.txt", "student_data.txt");

	}

	if (founded > 0)
	{
		fstream fs, fm;
		fs.open("all_data.txt", ios::in);
		if (!fs)
		{
			cout << "No Data \n";
			file.close();
		}
		else
		{
			fm.open("all_data_modify.txt", ios::app | ios::out);
			fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			while (!fs.eof())
			{
				if (student.id != id)
				{
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				else
				{
					student.name = a;
					student.id = b;
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			}
			fm.close();
			fs.close();
			remove("all_data.txt");
			rename("all_data_modify.txt", "all_data.txt");
		}
	}
}


void search_student()
{
	system("cls");
	fstream file;
	int founded = 0;
	file.open("all_data.txt", ios::in);
	if (!file)
	{
		cout << "\t\t\t\t\t\t -Search student Data- \n";
		cout << "No Data \n";
	}
	else
	{
		long long ide;
		cout << "\t\t\t\t\t\t -Search student Data- \n";
		cout << "Enter student ID : ";
		cin >> ide;
		file >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
		while (!file.eof())
		{
			if (student.id == ide)
			{
				cout << "course : " << course.name << endl;
				cout << "Course Grade : " << course.course_grade << endl;
				founded++;
			}
			file >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
		}
		if (founded == 0)
		{
			fstream f;
			int founded2 = 0;
			f.open("student_data.txt", ios::in);
			if (!f)
			{
				cout << "\t\t\t\t\t\t -Search student Data- \n";
				cout << "No Data \n";
			}
			else
			{
				f >> student.name >> student.id;
				while (!f.eof())
				{
					if (student.id == ide)
					{
						cout << "Student is not enrolled in any course" << endl;
						founded2++;
					}
					f >> student.name >> student.id;
				}
			}
			if (founded2 == 0)
			{
				cout << "Student Data Not Found \n";
			}
		}
		file.close();
	}
}


void delet_student()
{
	system("cls");
	fstream file, file1;
	long long id;
	int founded = 0;
	cout << "\t\t\t\t\t\t -Modify Student Data- \n";
	file.open("student_data.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		cout << "Enter Student ID : ";
		cin >> id;
		file1.open("stu_data.txt", ios::app | ios::out);
		file >> student.name >> student.id;
		while (!file.eof())
		{
			if (student.id != id)
			{
				file1 << " " << student.name << " " << student.id << endl;
			}
			else
			{
				founded++;
			}
			file >> student.name >> student.id;
		}
		if (founded == 0)
		{
			cout << "ID is wrong \n";
		}
		file1.close();
		file.close();
		remove("student_data.txt");
		rename("stu_data.txt", "student_data.txt");

	}

	if (founded > 0)
	{
		fstream fs, fm;
		fs.open("all_data.txt", ios::in);
		if (!fs)
		{
			cout << "No Data \n";
			file.close();
		}
		else
		{
			fm.open("all_data_modify.txt", ios::app | ios::out);
			fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			while (!fs.eof())
			{
				if (student.id != id)
				{
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			}
			fm.close();
			fs.close();
			remove("all_data.txt");
			rename("all_data_modify.txt", "all_data.txt");
		}
	}
}

/********************************************""""""""""""""functions of course"""""""************************************************/

void course_menu()
{
menustart:
	int choice;
	char x;
	system("cls");
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t ------------------------Courses Menu---------------------- \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t 1. Enter new course \n";
	cout << "\t\t\t\t 2. Display courses \n";
	cout << "\t\t\t\t 3. Modify course \n";
	cout << "\t\t\t\t 4. Search for course \n";
	cout << "\t\t\t\t 5. Delete course \n";
	cout << "\t\t\t\t 6. Exit \n";
	cout << "\t\t\t\t 7. Back to main menu \n";
	cout << "\t\t\t\t 8. Add student to spacifec course \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "\t\t\t\t ------------Choice Operation [1, 2 , 3 , 4 , 5]----------- \n";
	cout << "\t\t\t\t ---------------------------------------------------------- \n";
	cout << "Enter your Choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		add_courses();
		break;
	case 2:
		display_courses();
		break;
	case 3:
		modify_courses();
		break;
	case 4:
		search_courses();
		break;
	case 5:
		delet_courses();
		break;
	case 6:
		cout << "We Hope You Found It Useful :)" << endl;
		exit(0);
	case 7:
		main_menu();
		break;
	case 8 :
		add_student_to_spacefic_course();
		break;
	default:
		cout << "Invaild Number Please try again...";
		break;
	}
	_getch();
	goto menustart;
}

void add_courses()
{
	system("cls");
	fstream file_course;
	cout << "Enter Course ID : "<<endl;
	cin >> course.id;
	cout << "Enter Course Name : " << endl;
	cin >> course.name;
	cout << "Enter course instractor : "<<endl;
	cin >> course.instractor_name;
	file_course.open("onlycourses.txt", ios::app | ios::out);
	file_course << course.id << " " << course.name << " " << course.instractor_name << endl;
	file_course.close();
}

void display_courses()
{
	system("cls");
	fstream file;
	int counter = 0;
	cout << "\t\t\t\t\t\t -Course Data- \n";
	file.open("onlycourses.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		file >> course.id >> course.name >> course.instractor_name;
		while (!file.eof())
		{
			counter++;
			cout << counter << " )" << " " << "Course ID : " << course.id << endl;
			cout << "Course Name : " << course.name << endl;
			cout << "Instrctoe Name : " << course.instractor_name << endl;
			file >> course.id >> course.name >> course.instractor_name;
		}
	}
	file.close();
}


void modify_courses()
{
	system("cls");
	fstream file, file1;
	long long id;
	int founded = 0;
	string a, c;
	int b = 0;
	cout << "\t\t\t\t\t\t -Modify Course Data- \n";
	file.open("onlycourses.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		cout << "Enter Course ID : ";
		cin >> id;
		file1.open("course_modify.txt", ios::app | ios::out);
		file >> course.id >> course.name >> course.instractor_name;
		while (!file.eof())
		{
			if (course.id != id)
			{
				file1  << course.id << " " << course.name<<" " << course.instractor_name << endl;
			}
			else
			{
				cout << "Course Name : " << endl;
				cin >> course.name;
				a = course.name;
				cout << "Course ID : " << endl;
				cin >> course.id;
				b = course.id;
				cout << "Course Instrctor Name : " << endl;
				cin >> course.instractor_name;
				c = course.instractor_name;
				file1 << course.id << " " << course.name <<" "<< course.instractor_name << endl;
				founded++;
			}
			file >> course.id >> course.name >> course.instractor_name;
		}
		if (founded == 0)
		{
			cout << "This ID Is Not Found \n";
		}
		file1.close();
		file.close();
		remove("onlycourses.txt");
		rename("course_modify.txt", "onlycourses.txt");

	}

	if (founded > 0)
	{
		fstream fs, fm;
		fs.open("all_data.txt", ios::in);
		if (!fs)
		{
			cout << "No Data \n";
			file.close();
		}
		else
		{
			fm.open("all_data_modify.txt", ios::app | ios::out);
			fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			while (!fs.eof())
			{
				if (course.id != id)
				{
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				else
				{
					course.name = a;
					course.id = b;
					course.instractor_name = c;
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			}
			fm.close();
			fs.close();
			remove("all_data.txt");
			rename("all_data_modify.txt", "all_data.txt");
		}
	}
}


void search_courses()
{
	system("cls");
	fstream file;
	int founded = 0;
	file.open("all_data.txt", ios::in);
	if (!file)
	{
		cout << "\t\t\t\t\t\t -Search course Data- \n";
		cout << "No Data \n";
	}
	else
	{
		long long ide;
		cout << "\t\t\t\t\t\t -Search Course Data- \n";
		cout << "Enter Course ID : ";
		cin >> ide;
		file >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
		while (!file.eof())
		{
			if (course.id == ide)
			{
				cout << "Student Name : " << student.name << endl;
				cout << "Course Grade : " << course.course_grade << endl;
				founded++;
			}
			file >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
		}
		if (founded == 0)
		{
			fstream f;
			int founded2 = 0;
			f.open("onlycourses.txt", ios::in);
			if (!f)
			{
				cout << "\t\t\t\t\t\t -Search student Data- \n";
				cout << "No Data \n";
			}
			else
			{
				f >> course.id >> course.name >> course.instractor_name;
				while (!f.eof())
				{
					if (course.id == ide)
					{
						cout << "There is no students in this course" << endl;
						founded2++;
					}
					f >> course.id >> course.name >> course.instractor_name;
				}
			}
			if (founded2 == 0)
			{
				cout << "course Data Not Found \n";
			}
		}
		file.close();
	}
}


void delet_courses()
{
	system("cls");
	fstream file, file1;
	long long id;
	int founded = 0;
	cout << "\t\t\t\t\t\t -Modify Course Data- \n";
	file.open("onlycourses.txt", ios::in);
	if (!file)
	{
		cout << "No Data \n";
		file.close();
	}
	else
	{
		cout << "Enter Course ID : ";
		cin >> id;
		file1.open("course_modify.txt", ios::app | ios::out);
		file >> course.id >> course.name >> course.instractor_name;
		while (!file.eof())
		{
			if (course.id != id)
			{
				file1 << course.id << " " << course.name << " " << course.instractor_name << endl;
			}
			else
			{
				founded++;
			}
			file >> course.id >> course.name >> course.instractor_name;
		}
		if (founded == 0)
		{
			cout << "ID is wrong \n";
		}
		file1.close();
		file.close();
		remove("onlycourses.txt");
		rename("course_modify.txt", "onlycourses.txt");

	}

	if (founded > 0)
	{
		fstream fs, fm;
		fs.open("all_data.txt", ios::in);
		if (!fs)
		{
			cout << "No Data \n";
			file.close();
		}
		else
		{
			fm.open("all_data_modify.txt", ios::app | ios::out);
			fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			while (!fs.eof())
			{
				if (course.id != id)
				{
					fm << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
				}
				fs >> student.name >> student.id >> course.id >> course.name >> course.instractor_name >> course.course_grade;
			}
			fm.close();
			fs.close();
			remove("all_data.txt");
			rename("all_data_modify.txt", "all_data.txt");
		}
	}
}


void add_student_to_spacefic_course()
{
	system("cls");
	fstream file;
	file.open("student_data.txt", ios::in);
	if (!file)
	{
		cout << "\t\t\t\t\t\t -Search Student Data- \n";
		cout << "No Data \n";
	}
	else
	{
		cout << "Enter the ID of the student" << endl;
		int idee; cin >> idee;
		bool student_found = false;
		file >> student.name >> student.id;
		while (!file.eof())
		{
			if (idee == student.id)
			{
				fstream file1;
				file1.open("onlycourses.txt", ios::in);
				if (!file1)
				{
					cout << "\t\t\t\t\t\t -Search Student Data- \n";
					cout << "No Data \n";
				}
				else
				{
					student_found = true;
					bool course_found = false;
					cout << "Enter the ID of the course" << endl;
					int iid; cin >> iid;
					file1 >> course.id >> course.name >> course.instractor_name;
					while (!file1.eof())
					{
						if (iid == course.id)
						{
							cout << "Enter grade of student" << endl;
							cin >> course.course_grade;
							fstream file2;
							file2.open("all_data.txt", ios::app);
							file2 << student.name << " " << student.id << " " << course.id << " " << course.name << " " << course.instractor_name << " " << course.course_grade << endl;
							file2.close();
							course_found = true;
						}
						file1 >> course.id >> course.name >> course.instractor_name;
					}
					file1.close();
					if (course_found == false)
					{
						cout << "Course ID is wrong" << endl;
					}
				}
			}
			file >> student.name >> student.id;

		}
		file.close();
		if (student_found == false)
		{
			cout << "Student ID is wrong" << endl;
		}
	}
}