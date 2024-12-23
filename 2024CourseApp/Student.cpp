#include "Student.h"
#include <iostream>
#include "Utility.h"
using namespace std;

Student::Student(const string& id, const string& lastName, const string& firstName, const string& gender, const string& birthDate, const string& studentId, Department department, ClassName className) :Person(id, lastName, firstName, gender, birthDate), studentId(studentId), department(department), className(className)
{
}

string Student::getStudentId() const
{
	return studentId;
}

Department Student::getdepartment() const
{
	return department;
}

ClassName Student::getclassName() const
{
	return className;
}

void Student::setStudentId(const string& studentId)
{
	this->studentId = studentId;
}

void Student::setdepartment(Department departmant)
{
	this->department = department;
}

void Student::setClassName(ClassName ClassName)
{
	this->className = className;
}

void Student::display() const
{
	Person::display();
	cout << "學號: " << studentId << endl;
	cout << "科系: " <<Utility::toString  (department) << endl;
	cout << "班級: " << Utility::toString (className) << endl;
}
