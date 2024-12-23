#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(const string& courseId, const string& courseName, const string& courseDescription) :courseId(courseId), courseName(courseName), courseDescription(courseDescription)
{
}

Course::Course()
{
}

string Course::getcourseId() const
{
	return courseId;
}

string Course::getcourseName() const
{
	return courseName;
}

string Course::getcourseDescription() const
{
	return courseDescription;
}

void Course::setcourseId(const string& courseId)
{
	this->courseId = courseId;
}

void Course::setcourseName(const string& courseName)
{
	this->courseName = courseName;
}

void Course::setcourseDescription(const string& courseDescription)
{
	this->courseDescription = courseDescription;
}

void Course::display() const
{
	cout << "課程ID: " << courseId << endl;
	cout << "課程名稱: " << courseName << endl;
	cout << "課程簡介: " << courseDescription << endl;
}
