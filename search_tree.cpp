#include "search_tree.h"

void SearchTree::DeleteTree(Node*& root_tree) const
{
	if (!root_tree) {
		return;
	}
	DeleteTree(root_tree->left_);
	DeleteTree(root_tree->right_);
	delete root_tree;
	root_tree = NULL;
}

void SearchTree::Copy(Node*& dest, Node* const & source_root) const
{
	dest = NULL;
	if (source_root) {
		dest = new Node;
		dest->data_ = source_root->data_;
		Copy(dest->left_, source_root->left_);
		Copy(dest->right_, source_root->right_);
	}
}

void SearchTree::CopyTree(SearchTree const & source_tree)
{
	Copy(root_, source_tree.root_);
}

void SearchTree::PrintFromNode(Node* root) const
{
	stack<Node*> stack_nodes;
	Node* current_node = root;
	while (!stack_nodes.empty() || current_node != NULL) {
		if (current_node != NULL) {
			stack_nodes.push(current_node);
			current_node = current_node->left_;
		}
		else {
			current_node = stack_nodes.top();
			stack_nodes.pop();
			//if there is only one node that have to be printed
			if (!current_node->right_ && stack_nodes.size() == 0) {
				cout << current_node->data_.GetFacNum();
				break;
			}
			cout << current_node->data_.GetFacNum() << ", ";
			current_node = current_node->right_;
		}
	}
}

void SearchTree::InsertFromNode(Node*& root_tree, Student const & inf) const
{
	if (!root_tree) {
		root_tree = new Node;
		root_tree->data_ = inf;
		root_tree->left_ = NULL;
		root_tree->right_ = NULL;
		return;
	}
	//if the student already exists, first and last names are updated
	if (root_tree->data_ == inf) {
		root_tree->data_.SetFirstName(inf.GetFirstName());
		root_tree->data_.SetLastName(inf.GetLastName());
		return;
	}
	if (inf < root_tree->data_) {
		InsertFromNode(root_tree->left_, inf);
	}
	else {
		InsertFromNode(root_tree->right_, inf);
	}
}

void SearchTree::FindFromNode(Node*& root_tree, unsigned long long int const & student_num)
{
	if (!root_tree) {
		cout << "Record not found! \n";
		return;
	}
	unsigned long long int current_fac_num = root_tree->data_.GetFacNum();
	if (current_fac_num == student_num) {
		cout << root_tree->data_;
		return;
	}
	if (current_fac_num > student_num) {
		FindFromNode(root_tree->left_, student_num);
	}
	else {
		FindFromNode(root_tree->right_, student_num);
	}
}

SearchTree::SearchTree()
{
	root_ = NULL;
}

SearchTree::~SearchTree()
{
	DeleteTree(root_);
}

SearchTree::SearchTree(SearchTree const & sourceTree)
{
	CopyTree(sourceTree);
}

SearchTree& SearchTree::operator=(SearchTree const & sourceTree)
{
	if (this != &sourceTree) {
		DeleteTree(root_);
		CopyTree(sourceTree);
	}
	return *this;
}

void SearchTree::Traversal() const
{
	PrintFromNode(root_);
}

void SearchTree::InsertNode(Student const & inf)
{
	InsertFromNode(root_, inf);
}

void SearchTree::DeleteNode(unsigned long long int const & fac_num)
{
	if (DeleteNodeFromRoot(root_, fac_num)) {
		cout << "Record deleted! \n";
	}
	else {
		cout << "Record not found! \n";
	}
}

bool SearchTree::DeleteNodeFromRoot(Node*& root, unsigned long long int const & x)
{
	if (!root) return false;
	if (x < root->data_) {
		return DeleteNodeFromRoot(root->left_, x);
	}
	else if (x > root->data_) {
		return DeleteNodeFromRoot(root->right_, x);
	}
	else {
		Node* temp_pointer_root;
		if (!(root->left_)) {
			temp_pointer_root = root;
			root = root->right_;
			delete temp_pointer_root;
			return true;
		}
		else if (!(root->right_)) {
			temp_pointer_root = root;
			root = root->left_;
			delete temp_pointer_root;
			return true;
		}
		else {
			temp_pointer_root = root->right_;
			while (temp_pointer_root->left_) {
				temp_pointer_root = temp_pointer_root->left_;
			}
			root->data_ = temp_pointer_root->data_;
			return DeleteNodeFromRoot(root->right_, temp_pointer_root->data_.GetFacNum());
		}
	}
}

void SearchTree::FindStudent(unsigned long long int const & student_num)
{
	FindFromNode(root_, student_num);
}