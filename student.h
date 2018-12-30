#ifndef HOMEWORK4_HOMEWORK4_STUDENT_H_
#define HOMEWORK4_HOMEWORK4_STUDENT_H_
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	unsigned long long int fac_num_;
	string first_name_;
	string last_name_;
public:
	//Constructor
	Student(const unsigned long long int = 0, const string = "", const string = "");

	//Getters that return the value of all Student's variables
	unsigned long long int	GetFacNum() const;
	string GetFirstName() const;
	string GetLastName() const;

	//Setters
	void SetFirstName(const string);
	void SetLastName(const string);

	//Overloaded operators
	friend bool operator<(Student const &, Student const &);
	friend bool operator>(Student const &, Student const &);
	friend bool operator==(Student const &, Student const &);
	
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student const &);
};


#endif



