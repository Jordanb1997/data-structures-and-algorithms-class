#include <stdio.h>
#include "list.h"
#include "hashtable.h"

int main(){
	int command = 1;
	HashTable table = create_hashtable(11);
	char buffer[100];

	while (command){
		scanf("%d", &command);
		switch (command){
		case 1:
			scanf("%s", buffer);
			hash_insert(&table, buffer);
			break;
		case 2: // TODO: remove
			break;
		case 3: // TODO: print
			break;
		}
		printf_s("\n");
	}
	// TODO: destroy
}