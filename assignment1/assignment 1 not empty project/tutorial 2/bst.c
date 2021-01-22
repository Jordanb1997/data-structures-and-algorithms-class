#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


/*
	this file gives the code for bst functions
*/

//creates the root node for a new tree
BST new_bst() {
	BST temp;

	temp.root = NULL;

	return temp;
}

//finds indicated node
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {
	if (self == NULL || (n == self->data)) {
		return self;
	}
	else if (n < self->data) {
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

//finds bst root
BSTNodePtr find_bst(BST *self, int n) {
	return find_bst_node(self->root, n);
}

//inserts a node
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	if (self == NULL) { /* found where to put it*/
		self = malloc(sizeof *self);
		self->data = n;
		self->courses = new_list();
		self->left = self->right = NULL;
	}
	else if (n < self->data) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n >self->data) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
}

void insert_bst(BST *self, int n) {
	self->root = insert_bst_node(self->root, n);
}


BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

//delete a node
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (n == self->data) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->data = successor->data;
				self->right = delete_bst_node(self->right, self->data);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (n < self->data) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

//deletes root and tree
void delete_bst(BST *self, int n) {
	self->root = delete_bst_node(self->root, n);
}

//print pre order nodes
void print_in_order_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		printf("(");
		
		print_in_order_bst_node(self->left);
		printf(" %d ", self->data);
		print_in_order_bst_node(self->right);
		printf(")");
	}
	else {
		printf("_");
	}
}
//print from root in preorder
void print_in_order_bst(BST *self) {
	print_in_order_bst_node(self->root);
}
