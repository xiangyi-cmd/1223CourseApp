#pragma once
#include "Person.h"
#include "Utility.h"
#include <iostream>
using namespace std;

class Student :
    public Person
{
private:
    string studentId;
    Department department;
    ClassName className;

public:
    Student(const string& id, const string& lastName, const string& firstName, const string& gender, const string& birthDate, const string& studentId, Department department, ClassName className);

    //Getter 取值函數
    string getStudentId() const;
    Department getdepartment() const;
    ClassName getclassName() const;

    //Setter 設值函數
    void setStudentId(const string& studentId);
    void setdepartment(Department departmant);
    void setClassName(ClassName ClassName);

    void display() const;
};

