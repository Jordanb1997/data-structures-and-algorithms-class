#include <stdio.h>
#include <string.h>
#include "list.h"


void print_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf_s("%s", current->data);
		current = current->next;

		if (current != NULL)
			printf_s(", ");
	}
	printf_s("\n");
}

// -- allocate just enough memory for newNode->data (malloc)
// -- copy string from parameter into newNode->data (strcpy)
void insert_at_front(List *self, char *data) {
	int length = strlen(data);

	ListNodePtr new_node = malloc(sizeof *new_node);
	new_node->data = malloc(sizeof length + 1);

	strcpy_s(new_node->data ,length+1,data);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;

}

// -- change test in if statement to string compare (strcmp)
// -- free current->data (memory allocated for string) before freeing current
void delete_list(List *self, char *data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (strcmp(current->data, data)) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current->data);
				free(current);
				current = self->head;
			} else {                    // middle of list
				prev->next = current->next;
				free(current->data);
				free(current);
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

// after changing to char*:
// -- need to free memory allocated for string before freeing node
void destroy_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(current->data);
		free(to_free);
	}
	self->head = NULL;
}