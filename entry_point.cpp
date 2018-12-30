#include <iostream>
#include "student.h"
#include "search_tree.h"
#include "functions.h"

using namespace std;

int main() {
	string operation;
	cin >> operation;
	SearchTree students_tree;
	while (operation != "exit") {
		if (operation == "insert") {
			Insert(students_tree);
		}
		else if (operation == "delete") {
			DeleteStudent(students_tree);
		}
		else if (operation == "find") {
			Find(students_tree);
		}
		else if (operation == "traverseInorder") {
			students_tree.Traversal(); 
			cout << endl;
		}
		else {
			cout << "Invalid operation! \n";
		}
		cin >> operation;
	}
	return 0;
}