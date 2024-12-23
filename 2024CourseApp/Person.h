#pragma once
#include<string>

using namespace std;

class Person
{
private:
	string id;
	string lastName;
	string firstName;
	string gender;
	string birthDate;
public:
	// Constructor 建構函式
	Person(const string& id, const string& lastName, const string& firstName, const string& gender, const string& birthDate);
	Person();	//同名異式

	//Getter 取值函數
	string getId() const;	// const --> 保證不會被改動
	string getLastName() const;
	string getFirstName() const;
	string getGender() const;
	string getBirthDate() const;

	//Setter 設值函數
	void setId(const string& id);
	void setLastName(const string& lastName);
	void setFirstName(const string& firstName);
	void setGender(const string& gender);
	void setBirthDate(const string& birthDate);

	void display() const;
};

