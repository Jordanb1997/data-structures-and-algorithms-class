#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *String;

void main()
{
	
	String* strings;
	
	int count;
	

	
	printf_s("enter num of strings: ");
	scanf_s("%d", &count);

	strings = malloc(sizeof(String) * count);
	
	char buffer [100];

	for(int i = 0; i < count; i++)
	{
		printf_s("enter a string: ");
		scanf_s("%s",buffer, 100);

		strings[i] = (String)malloc(strlen(buffer) + 1);
		strcpy(strings[i], buffer);
	}

	for(int i = 0; i < count; i++)
	{ 
		printf_s(strings[i]);
		printf_s("\n");
	}
}