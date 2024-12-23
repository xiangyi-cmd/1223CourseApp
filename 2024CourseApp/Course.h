#pragma once
#include<iostream>
using namespace std;

class Course
{
private:
	string courseId;
	string courseName;
	string courseDescription;

public:
	Course(const string& courseId, const string& courseName, const string& courseDescription); Course();
	string getcourseId() const;
	string getcourseName() const;
	string getcourseDescription() const;

	void setcourseId(const string& courseId);
	void setcourseName(const string& courseName);
	void setcourseDescription(const string& courseDescription);

	void display() const;
};

