#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringlist.h"

/*
	this file gives the code for the functions of the student record list
*/

//generate the list head for a new list
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

//print what is in the list
void print_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf_s("%s \n", current->data);
		current = current->next;
	}
	printf("\n");
}
//insert at the front of the list
void insert_at_front(List *self, char *data) {
	int length = strlen(data);
	
	ListNodePtr new_node = malloc(sizeof *new_node);
	new_node->data = malloc(sizeof length+1);
	
	strcpy_s(new_node->data, length + 1, data);

	new_node->data = data;

	new_node->next = self->head;
	self->head = new_node;
}
//insert in list order
void insert_in_order(List *self, char *data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof *new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}
//search for data in list
char *search_list(List *self, char *data)
{
	ListNodePtr current = self->head;
	while (current->data != data) {

		current = current->next;
	}
	return data;
	//there incase bst code can be used
	/*if (self == NULL || (n == self->data)) {
		return self;
	}*/

}
//delete a value from the list
void delete_list(List *self, char *data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {          // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

//clear the list and its allocated memory
void destroy_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}