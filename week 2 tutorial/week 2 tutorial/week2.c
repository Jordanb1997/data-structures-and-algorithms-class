#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void option_insert(List *self, int new_data)
{
	insert_at_front(self, new_data);
}
void option_delete(List *self, int delete_data)
{
	delete_list(self, delete_data);
}
void option_print(List *self)
{
	print_list(self);
}

void main()
{
	List my_list; //initialising a new list
	int input_data = 0; //input for list node data

	//creating the new list
	my_list = new_list();

	int option;//menu item selection
	do
	{
		//int input_data = 0; //input for list node data

		//telling what is in menu 
		printf_s("-------------------\n");
		printf_s("0. quit\n");
		printf_s("1. insert to list\n");
		printf_s("2. delete from list\n");
		printf_s("3. print out list\n");
		printf_s("-------------------\n");

		//option select
		printf_s("select an option: ");
		scanf_s("%d", &option);

		switch (option) {

		case 0:
			option = 0;
			break;
		case 1:
			option = 1;

			printf_s("enter data to insert: ");
			scanf_s("%d", &input_data);

			option_insert(&my_list, input_data);
			break;
		case 2:
			option = 2;

			printf_s("enter data to delete: ");
			scanf_s("%d", &input_data);

			option_delete(&my_list, input_data);
			break;
		case 3:
			option = 3;
			option_print(&my_list);
			break;
		}
	} while (option != 0);

	destroy_list(&my_list);

}

//main from part 15
/*void main()
{
	List my_list; //initialising a new list
	int in; //stores input
	
	//creating the new list
	my_list = new_list();

	printf_s("enter integer: ");
	scanf_s("%d", &in);

	insert_at_front(&my_list,in);

	while (in != 0)
	{

		printf_s("enter next integer: ");
		scanf_s("%d",&in);

		insert_at_front(&my_list,in);

	}
	print_list(&my_list);

	destroy_list(&my_list);

	////print the list
	print_list(&my_list);
}*/