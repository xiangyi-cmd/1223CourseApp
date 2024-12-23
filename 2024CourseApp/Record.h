#pragma once
#include <iostream>
using namespace std;

class Record
{
private:
	static int nextId;
	int recordId;
	string studentId;
	string courseId;
	time_t recordDate;
public:
	Record();
	Record(const string& studentId, const string& courseId);

	int getRecordId() const;
	string getStudentId() const;
	string getCourseId() const;
	string getRecordDate() const;

	void display() const;

};

