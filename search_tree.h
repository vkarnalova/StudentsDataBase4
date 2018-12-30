#ifndef HOMEWORK4_HOMEWORK4_SEARCH_TREE_H_
#define HOMEWORK4_HOMEWORK4_SEARCH_TREE_H_

#include <iostream>
#include <stack>
#include "student.h"
using namespace std;

struct Node {
	Student data_;
	Node* left_;
	Node* right_;
};

class SearchTree {
private:
	Node* root_;

	void DeleteTree(Node*&) const;
	void Copy(Node*&, Node* const &) const;
	void CopyTree(SearchTree const &);

	void PrintFromNode(Node*) const;//prints a tree, using pointer to its root
	void InsertFromNode(Node*&, Student const &) const; //adds element to the tree, using pointer to its root
	bool DeleteNodeFromRoot(Node* &, unsigned long long int const &); //deletes element from the tree, using pointer to its root
	void FindFromNode(Node*&, unsigned long long int const&); //finds student, using the tree's root and the student's faculty number
public:
	//constructors
	SearchTree();
	~SearchTree();
	SearchTree(SearchTree const &);
	SearchTree& operator=(SearchTree const &);

	void Traversal() const;//performs an inorder traversal

	void InsertNode(Student const &);//adds a student to the tree
	void DeleteNode(unsigned long long int const &);//deletes a student from the tree
	void FindStudent(unsigned long long int const &);//finds a student in the tree
};

#endif
