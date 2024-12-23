#include <iostream>
#include <string>
#include <vector>
#include "Record.h"
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include "Teacher.h"
#include "2024CourseApp.h"
using namespace std;

vector<Record> records;
vector<Student> students;
vector<Course> courses;
vector<Teacher> teachers;



int main()
{
    InitializeData();
	DisplayMenu();
}

void InitializeData()
{
	courses.push_back(Course("C001", "C++ Programming", "這門課程教授C++程式語言"));
	courses.push_back(Course("C002", "Java Programming", "這門課程教授Java程式語言"));
	courses.push_back(Course("C003", "Python Programming", "這門課程教授Python程式語言"));
	courses.push_back(Course("C004", "C# Programming", "這門課程教授C#程式語言"));
	courses.push_back(Course("C005", "Visual Basic Programming", "這門課程教授Visual Basic程式語言"));

	//新增5筆學生資料
	students.push_back(Student("A123321", "陳", "小明", "男", "1999-05-05", "S001", Department::ComputerSciece, ClassName::_1A));
	students.push_back(Student("B234567", "林", "小華", "男", "1999-06-06", "S002", Department::ElectricalEngineering, ClassName::_1A));
	students.push_back(Student("C345678", "黃", "小美", "女", "1999-07-07", "S003", Department::ElectronicEngineering, ClassName::_1A));
	students.push_back(Student("D456789", "張", "小強", "男", "1999-08-08", "S004", Department::InformationManagement, ClassName::_1A));
	students.push_back(Student("E567890", "王", "小菁", "女", "1999-09-09", "S005", Department::MechanicalEngineering, ClassName::_1A));

	//新增2筆教師資料
	vector<Course> teacher1_courses = { courses[0], courses[1], courses[2] };
	teachers.push_back(Teacher("032", "阿益", "張", "男", "1949-02-28", "A301", Department::ComputerSciece, ClassName::_4A, teacher1_courses));
	vector<Course> teacher2_courses = { courses[3], courses[4] };
	teachers.push_back(Teacher("033", "阿貴", "李", "男", "1950-03-01", "A302", Department::ComputerSciece, ClassName::_3A, teacher2_courses));

	//新增10筆選課紀錄
	records.push_back(Record("S001", "C001"));
	records.push_back(Record("S001", "C002"));
	records.push_back(Record("S001", "C003"));
	records.push_back(Record("S002", "C001"));
	records.push_back(Record("S002", "C002"));
	records.push_back(Record("S002", "C003"));
	records.push_back(Record("S003", "C001"));
	records.push_back(Record("S003", "C002"));
	records.push_back(Record("S003", "C003"));
	records.push_back(Record("S004", "C001"));




}

void DisplayMenu()
{
	int choice;
	do
	{
		Signature();
		cout << "1. 顯示所有學生資料" << endl;
		cout << "2. 顯示所有課程資料" << endl;
		cout << "3. 顯示所有教師資料" << endl;
		cout << "4. 顯示所有選課紀錄" << endl;
		cout << "5. 查詢學生資料" << endl;
		cout << "6. 查詢課程資料" << endl;
		cout << "7. 查詢教師資料" << endl;
		cout << "8. 查詢選課紀錄" << endl;
		cout << "9. 新增學生資料" << endl;
		cout << "10. 新增課程資料" << endl;
		cout << "11. 新增教師資料" << endl;
		cout << "12. 新增選課紀錄" << endl;
		cout << "0. 結束" << endl;
		cout << "請輸入選項：";
		cin >> choice;
		system("CLS"); // 清空畫面
		switch (choice)
		{
		case 1:
			listStudents();
			break;
		case 2:
			listCourses();
			break;
		case 3:
			listTeachers();
			break;
		case 4:
			listRecords();
			break;
		case 5:
			queryStudent();
			break;
		case 6:
			queryCourse();
			break;
		case 7:
			queryTeacher();
			break;
		case 8:
			queryRecord();
			break;
		case 9:
			addStudent();
			break;
		case 10:
			addCourse();
			break;
		case 11:
			addTeacher();
			break;
		case 12:
			addRecord();
			break;
		case 0:
			cout << "程式結束！" << endl;
			break;
		default:
			cout << "輸入錯誤！" << endl;
			break;
		}
	} while (choice != 0);
}

void Signature()
{
	cout << "-----------------------------------" << endl;
	cout << "南台科大 4B0G0035吳庠逸 程式作業" << endl;
	cout << "學生選課系統(Part 4: 查詢與新增功能)" << endl;
	cout << "-----------------------------------" << endl;
}

void listRecords()
{
	cout << "選課紀錄總共有" << records.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto record : records) {
		record.display();
		cout << endl;
	}
	cout << endl;
}

void listTeachers()
{
	cout << "教師資料總共有" << teachers.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto teacher : teachers) {
		teacher.display();
		cout << endl;
	}
	cout << endl;
}

void listCourses()
{
	cout << "課程資料總共有" << courses.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto course : courses) {
		course.display();
		cout << endl;
	}
	cout << endl;
}

void listStudents()
{
	cout << "學生資料總共有" << students.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto student : students) {
		student.display();
		cout << endl;
	}
	cout << endl;
}

void queryStudent()
{
	string studentId;
	cout << "請輸入學生學號：";
	cin >> studentId;
	cout << "----------------" << endl;
	for (auto student : students) {
		if (student.getStudentId() == studentId) {
			student.display();
			cout << endl;
			return;
		}
	}
	cout << "找不到學號為" << studentId << "的學生!" << endl;
	cout << endl;
}

void queryCourse()
{
	string courseId;
	cout << "請輸入課程代碼：";
	cin >> courseId;
	cout << "----------------" << endl;
	for (auto course : courses) {
		if (course.getcourseId() == courseId) {
			course.display();
			cout << endl;
			return;
		}
	}
	cout << "找不到課程代碼為" << courseId << "的課程!" << endl;
	cout << endl;
}

void queryTeacher()
{
	string teacherId;
	cout << "請輸入教師編號：";
	cin >> teacherId;
	cout << "----------------" << endl;
	for (auto teacher : teachers) {
		if (teacher.getTeacherId() == teacherId) {
			teacher.display();
			cout << endl;
			return;
		}
	}
	cout << "找不到教師編號為" << teacherId << "的教師!" << endl;
	cout << endl;
}

void queryRecord()
{
	int choice;
	cout << "請選擇查詢方式：" << endl;
	cout << "1. 根據學生學號查詢" << endl;
	cout << "2. 根據課程代碼查詢" << endl;
	cout << "請輸入選項：";
	cin >> choice;

	switch (choice)
	{
	case 1:
		queryRecordByStudentId();
		break;
	case 2:
		queryRecordByCourseId();
		break;
	default:
		cout << "輸入錯誤！" << endl;
		break;
	}
}

void queryRecordByStudentId()
{
	string studentId;
	cout << "請輸入學生學號：";
	cin >> studentId;
	cout << "----------------" << endl;
	bool found = false;
	for (const auto& record : records) {
		if (record.getStudentId() == studentId) {
			record.display();
			cout << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "找不到學號為" << studentId << "的選課紀錄!" << endl;
	}
	cout << endl;
}

void queryRecordByCourseId()
{
	string courseId;
	cout << "請輸入課程代碼：";
	cin >> courseId;
	cout << "----------------" << endl;
	bool found = false;
	for (const auto& record : records) {
		if (record.getCourseId() == courseId) {
			record.display();
			cout << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "找不到課程代碼為" << courseId << "的選課紀錄!" << endl;
	}
	cout << endl;
}

void addStudent()
{
	string id, lastName, firstName, gender, birthDate, studentId;
	int departmentChoice, classNameChoice;
	cout << "請輸入身分證字號：";
	cin >> id;
	cout << "請輸入姓：";
	cin >> lastName;
	cout << "請輸入名：";
	cin >> firstName;
	cout << "請輸入性別：";
	cin >> gender;
	cout << "請輸入生日：";
	cin >> birthDate;
	cout << "請輸入學號：";
	cin >> studentId;
	cout << "系所： " << endl;
	for (int i = 0; i < static_cast<int>(Department::Last); i++)
	{
		cout << i << "." << Utility::toString(static_cast<Department>(i)) << endl;
	}
	cout << "請輸入系所: ";
	cin >> departmentChoice;
	cout << "班級: " << endl;
	for (int i = 0; i < static_cast<int>(ClassName::Last); i++)
	{
		cout << i << "." << Utility::toString(static_cast<ClassName>(i)) << endl;
	}
	cout << "請輸入班級: ";
	cin >> classNameChoice;
	cout << "新增學生資料成功!!" << endl;
	Department department = static_cast<Department>(departmentChoice);
	ClassName className = static_cast<ClassName>(classNameChoice);
	students.push_back(Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
}

void addCourse()
{
	string courseId, courseName, courseDescription;
	cout << "請輸入課程代碼：";
	cin >> courseId;
	cout << "請輸入課程名稱：";
	cin >> courseName;
	cout << "請輸入課程簡介：";
	cin >> courseDescription;
	cout << "新增課程資料成功!!" << endl;
	courses.push_back(Course(courseId, courseName, courseDescription));
}

void addTeacher()
{
	string id, lastName, firstName, gender, birthDate, teacherId;
	int departmentChoice, classNameChoice;
	cout << "請輸入身分證字號：";
	cin >> id;
	cout << "請輸入姓：";
	cin >> lastName;
	cout << "請輸入名：";
	cin >> firstName;
	cout << "請輸入性別：";
	cin >> gender;
	cout << "請輸入生日：";
	cin >> birthDate;
	cout << "請輸入教師編號：";
	cin >> teacherId;
	cout << "系所： " << endl;
	for (int i = 0; i < static_cast<int>(Department::Last); i++)
	{
		cout << i << "." << Utility::toString(static_cast<Department>(i)) << endl;
	}
	cout << "請輸入系所: ";
	cin >> departmentChoice;
	cout << "班級: " << endl;
	for (int i = 0; i < static_cast<int>(ClassName::Last); i++)
	{
		cout << i << "." << Utility::toString(static_cast<ClassName>(i)) << endl;
	}
	cout << "請輸入班級: ";
	cin >> classNameChoice;
	Department department = static_cast<Department>(departmentChoice);
	ClassName className = static_cast<ClassName>(classNameChoice);
	teachers.push_back(Teacher(id, lastName, firstName, gender, birthDate, teacherId, department, className, {}));
	cout << "請輸入教師所授課程: " << endl;
	for (auto course : courses) {
		course.display();
	}
	cout << "請輸入課程代碼(輸入0結束): " << endl;
	string courseId;
	vector<Course> teacher_courses;
	do
	{
		cin >> courseId;
		if (courseId != "0") {
			for (auto course : courses) {
				if (course.getcourseId() == courseId) {
					teacher_courses.push_back(course);
				}
			}
		}
	} while (courseId != "0");
	teachers[teachers.size() - 1].setCourses(teacher_courses);
	cout << "新增教師資料成功!!" << endl;

}

void addRecord()
{
	string studentId, courseId;
	cout << "請輸入學號：";
	cin >> studentId;
	cout << "課程代碼：" << endl;
	for (auto course : courses) {
		course.display();
	}
	cout << endl;
	cout << "請輸入課程代碼：";
	cin >> courseId;
	cout << "新增選課紀錄成功!!" << endl;
	records.push_back(Record(studentId, courseId));
}