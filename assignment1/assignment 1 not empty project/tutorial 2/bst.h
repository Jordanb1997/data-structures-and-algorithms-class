#pragma once
#include "stringlist.h"

/*
	defines structs and functions for the student binary search tree
*/

//the tree node struct
typedef struct bstNode {
	long data;
	List courses;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

//struct for the actual tree
typedef struct bst {
	BSTNodePtr root;
} BST;

BST new_bst();
BSTNodePtr find_bst_node(BSTNodePtr self, int n);
BSTNodePtr find_bst(BST *self, int n);
BSTNodePtr insert_bst_node(BSTNodePtr self, int n);
void insert_bst(BST *self, int n);
BSTNodePtr min_node(BSTNodePtr self);
BSTNodePtr delete_bst_node(BSTNodePtr self, int n);
void delete_bst(BST *self, int n);
void print_in_order_bst_node(BSTNodePtr self);
void print_in_order_bst(BST *self);
