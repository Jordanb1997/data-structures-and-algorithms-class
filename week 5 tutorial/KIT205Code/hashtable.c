#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"

HashTable create_hashtable(int n){
	HashTable newtable;

	newtable.size = n;
	newtable.table = malloc(n * sizeof(List ));

	for (int i = 0; i < n; i++) {
		newtable.table[i].head = NULL;
	}

	return newtable;
}

int hash(char* key, int size){
	unsigned long h = 0; // unsigned long, so that when it wraps it's still positive
	int n = strlen(key);

	for (int i = 0; i < n; i++){
		// multiply by 32 (<<5) and add ascii value
		h = (h << 5) + (int)(key[i]);
	}
	return h%size;
}

void hash_insert(HashTable *self, char* key){
	// TODO
}

void hash_remove(HashTable *self, char* key){
	// TODO
}

void hash_print(HashTable *self){
	for (int i = 0; i < self->size; i++){
		printf("%d: ", i);
		print_list(&(self->table[i]));
	}
}

void hash_destroy(HashTable *self){
	// TODO
}