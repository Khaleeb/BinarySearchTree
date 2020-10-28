/*Note: you must create the BST.cpp file.  I'm only including a few
Otherwise, as specified in the directions, you must write the BST.cpp.
including the method definitions to accompany the method declarations
in BST.hpp
*/
#include "BST.hpp"
#include <iostream>
#include <string>


BST::BST() {
	root = NULL;
}
BST::BST(string s) {
	root = new TNode(s);
}

bool BST::insert(string s){
	if(root == NULL){
		root = new TNode(s);
		return true;
	}
	else {
		TNode *n = root;
		while (n != NULL){
			if (s.compare(n->data->phrase) < 0){
				if (n->left == NULL){
					n->left = new TNode(s);
					n->left->parent = n;
					setHeight(n);
					return true;
				} else {
					n = n->left;
				}
			} else if (s.compare(n->data->phrase) > 0){
				if (n->right == NULL){
					n->right = new TNode(s);
					n->right->parent = n;
					setHeight(n);
					return true;
				} else {
					n = n->right;
				}
			} else {
				return false;
			}
		}
	}
}

TNode *BST::find(string s){
	TNode *n = root;
	while (n){
		if (n->data->phrase == s){
			break;
		} else if (s.compare(n->data->phrase) < 0){
				n = n->left;
		} else if (s.compare(n->data->phrase) > 0){
			n = n->right;
		}
	}
	return n;

}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}


void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}


void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}
