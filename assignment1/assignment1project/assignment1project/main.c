#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringlist.h"
#include "bst.h"

/*
	This function adds a new student to the tree
	takes the student BST and a student id as parameters
	the student BST is the tree of current students
	the student id is the new student to add to the tree
*/
void add_student(BST *self, long student_id)
{
	int id = student_id;

	insert_bst(self, id);
}
/*
	This function removes a user defined student from the tree
	takes the student BST and a student id as parameters
	the student BST is the tree of current students
	the student id is the student to remove
*/
void remove_student(BST *self, long student_id)
{
	free(find_bst(self, student_id));
	delete_bst(self, student_id);
}
/*
	This function enrols a student into a course
	takes the student BST, student id and course name as parameters
	the student BST is the tree of current students
	the student id is the student to add to the course
	the course name is the course to assign
*/
void enrol_student(BST *self, long student,char *course)
{
	//find corresponding node in tree then its list
	BSTNodePtr student_node = find_bst_node(self->root, student);
	List *course_list = &student_node->courses;

	//insert the course into the list
	insert_at_front(course_list, course);
	
}
/*
	This function enenrols a student from a course
	takes the student BST, student id and course name as parameters
	the student BST is the tree of current students
	the student id is the student to unenroll course
	the course name is the course to unenroll from
*/
void unenrol_student(BST *self, long student, char *course)
{
	//find corresponding node in tree then its list
	BSTNodePtr student_node = find_bst_node(self->root, student);
	List *course_list = &student_node->courses;

	//delete and free the course from the list
	free(course);
	delete_list(course_list, course);
	
}
/*
	This function prints a summary of courses
	and enrolled students
	takes the student tree and sumarrises it
*/
void course_summary(BST *self)
{
	//commented out to remove warning
	//temp list
	//List summary = new_list();

	//access the node where root is then access that list to compare data in the list nodes
	BSTNodePtr student_node = self->root;
	List *course_list = &student_node->courses;
	ListNodePtr course_entry = course_list->head;
	
	//meant to traverse the tree 
	//add each unique course to the summary list
	//increment a number in the list for each time a course is found
	if (self != NULL)
	{

	}
	else if (student_node->left != NULL)
	{
		student_node->left = self->root;
	}
	else if (student_node->right != NULL)
	{
		student_node->right = self->root;
	}

	
}
/*
	This function prints an ordered list of students enrolled 
	in specified course

	takes the student BST and course name as parameters
	the student BST is the tree of current students
	the course name is the course to list

	currently is not traversing tree, just shows enrollment for the root of the tree

*/
void course_enrolment(BST *self,char *course)
{
	//access the node where root is then access that list to compare data in the list nodes
	BSTNodePtr student_node = self->root;
	List *course_list = &student_node->courses;
	ListNodePtr course_entry = course_list->head;

	//going through tree finding each instance of defined course
	if (self != NULL)
	{
		
		//testing if course parameter is in the course list for that tree node
		if (course_entry->data == course)
		{
			printf_s("%d", student_node->data);
		}
		else
		{
			course_entry->next;
		}

	}
	else if (student_node->left != NULL) 
	{
		student_node->left = self->root;
		//testing if course parameter is in the course list for that tree node
		if (course_entry->data == course)
		{
			printf_s("%d", student_node->data);
		}
		else
		{
			course_entry->next;
		}
	}
	else if (student_node->right != NULL)
	{
		student_node->right = self->root;
		//testing if course parameter is in the course list for that tree node
		if (course_entry->data == course)
		{
			printf_s("%d", student_node->data);
		}
		else
		{
			course_entry->next;
		}
	}

}
/*
	This function prints a students enrolment

	takes the student BST and course name as parameters
	the student BST is the tree of current students
	the student id is user input
*/
void student_course(BST *self, long student)
{
	//making output look nice
	printf_s("printing selected enrollment:");
	//printf_s(student_id);
	printf_s("\n");

	//find corresponding node in tree then its list
	BSTNodePtr student_node = find_bst_node(self->root, student);
	List *course_list = &student_node->courses;

	print_list(&student_node->courses);

}
void terminate_program(BST *self)
{
	//free(self);
	//exit(0);
}


void main() 
{
	//initialise the student tree
	BST student_tree;
	List list_courses;//this ones for testing
	
	long student_id;//holds input student id
	char new_course[100];

	student_tree = new_bst();
	list_courses = new_list();//also testing
	//select an option
	int option;//menu item selection
	do
	{
		//telling what is in menu 
		printf_s("\n-------------------\n");
		printf_s("0. quit\n");
		printf_s("1. add a student\n");
		printf_s("2. remove a student\n");
		printf_s("3. enrol a student\n");
		printf_s("4. un-enrol a student\n");
		printf_s("5. course summary\n");
		printf_s("6. course enrollment\n");
		printf_s("7. student courses\n");
		printf_s("-------------------\n");

		//option select
		printf_s("select an option: ");
		scanf_s("%d", &option);
		
		//menu switch
		switch (option) {

		case 0:
			option = 0;
			terminate_program(&student_tree);
			break;
		//adding a student
		case 1:
			option = 1;
			//collecting the student id
			printf_s("enter student id: ");
			scanf_s("%d", &student_id);
			//using the add function to add to the bst
			add_student(&student_tree, student_id);
			break;
		//removing a student
		case 2:
			option = 2;
			//grab the id to delete
			printf_s("enter id to delete");
			scanf_s("%d", &student_id);
			//delete using delete_student function
			remove_student(&student_tree, student_id);
			break;
		//enrolling a student into a course
		case 3:
			option = 3;
			//what student to enroll into the course
			printf_s("enter id: ");
			scanf_s("%d", &student_id);
			//get the course to enroll in
			printf_s("enter course: ");
			scanf_s("%s", new_course, 100);
			//enrol a student
			enrol_student(&student_tree, student_id, new_course);
			break;
		//unenrol a student from a course
		case 4:
			printf_s("enter a id to unenrol: ");
			scanf_s("%d", &student_id);
			
			printf("enter course to delete: ");
			scanf_s("%s", new_course, 100);

			unenrol_student(&student_tree, student_id, new_course);
			option = 4;
			break;
		//print summary of courses and students enrolled in courses
		case 5:
			option = 5;
			printf_s("current enrolments: ");
			course_summary(&student_tree);
			break;
		//print ordered list of students enrolled in a course
		case 6:
			option = 6;
			printf_s("enter a course: ");
			scanf_s("%s", new_course, 100);

			course_enrolment(&student_tree, new_course);
			break;
		//print courses that a student is enrolled in
		case 7:
			option = 7;
			printf_s("enter the student id: ");
			scanf_s("%d", &student_id);

			student_course(&student_tree, student_id);
			break;
		}
	} while (option != 0);

}
