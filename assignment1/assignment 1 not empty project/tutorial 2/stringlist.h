#pragma once

/*
	this header defines the components of the list used to store student records
	and related functions
*/

//defining a node struct for a list
typedef struct listNode {
	char *data;
	struct listNode *next;
} *ListNodePtr;

//the list struct itself
typedef struct list {
	ListNodePtr head;
} List;

//list function headers
List new_list();
void print_list(List *self);
void insert_at_front(List *self, char *data);
void insert_in_order(List *self, char *data);
char *search_list(List *self, char *data);
void delete_list(List *self, char *data);
void destroy_list(List *self);