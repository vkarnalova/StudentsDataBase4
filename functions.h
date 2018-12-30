#ifndef HOMEWORK4_HOMEWORK4_FUNCTION_H_
#define HOMEWORK4_HOMEWORK4_FUNCTION_H_
#include "student.h"
#include "search_tree.h"

void Insert(SearchTree& students_tree) {
	Student temp;
	cin >> temp;
	students_tree.InsertNode(temp);
	cout << "Record inserted! \n";
}
void DeleteStudent(SearchTree& student_tree) {
	unsigned long long int fac_num;
	cin >> fac_num;
	student_tree.DeleteNode(fac_num);
}
void Find(SearchTree& student_tree) {
	unsigned long long int fac_num;
	cin >> fac_num;
	student_tree.FindStudent(fac_num);
}
#endif
