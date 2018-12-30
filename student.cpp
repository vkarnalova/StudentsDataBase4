#include "student.h"

Student::Student(const unsigned long long int fac_num, const string first_name, const string last_name) {
	fac_num_ = fac_num;
	first_name_ = first_name;
	last_name_ = last_name;
}

unsigned long long int Student::GetFacNum() const
{
	return fac_num_;
}

string Student::GetFirstName() const
{
	return first_name_;
}

string Student::GetLastName() const
{
	return last_name_;
}
void Student::SetFirstName(const string first_name)
{
	first_name_ = first_name;
}
void Student::SetLastName(const string last_name)
{
	last_name_ = last_name;
}

bool operator<(Student const& st1, Student const& st2) {
	return st1.fac_num_ < st2.fac_num_;
}

bool operator>(Student const& st1, Student const& st2) {
	return st1.fac_num_ > st2.fac_num_;
}

bool operator==(Student const& st1, Student const& st2) {
	return st1.fac_num_ == st2.fac_num_;
}

istream& operator>>(istream& is, Student & st)
{
	is >> st.fac_num_ >> st.first_name_ >> st.last_name_;
	return is;
}

ostream & operator<<(ostream & os,Student const & st)
{
	os << st.fac_num_ << " " << st.first_name_ << " " << st.last_name_ << endl;
	return os;
}
