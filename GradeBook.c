// Jared Adamson
// Program to hold and compute student grades

#include <stdio.h>
#include <string.h>
#include <stdlib.h>		// used by malloc
#include <ctype.h>

#pragma warning(disable: 4996)

typedef enum{Final=0, Midterm, Homework, Quiz} Category;

struct Entry {			// a node to hold personal details
	Category type;
	char name[1024];
	float points;
	float possible_points;
	struct contact* next;
} *head = NULL;

void flush();			// forward declaration of functions
void branching(char c);
int remove_entry();
int insert_entry();
int average();
char* category_name(Category type);
void delete_list(struct Entry *temp);

int main() {		// print a menu for selection
	char ch = 'i';
	ungetc('\n', stdin);	// inject input buffer with a return character
	do {
		printf("Enter your selection\n");
		printf("\ta: insert a new entry\n");
		printf("\td: delete an entry\n");
		printf("\tp: compute average\n");
		printf("\tq: quit \n");
		flush();					// flush input buffer
		ch = tolower(getchar());	// see tutorial
		branching(ch);
	} while (ch != 113);

	delete_list(head);

	return 0;
}

void flush() {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void branching(char c) {		// branch to different tasks
	char sname[30];

	switch (c)  {
	case 'a':
		insert_entry();
		break;
	case 'd':
		remove_entry();
		break;
	case 'p':
		average();
		break;
	default:
		printf("Invalid input\n");
	}
}

int insert_entry()
{
	struct Entry *new_entry = (struct Entry *) malloc(sizeof(struct Entry));

	if (new_entry != NULL)
	{
		printf("Please enter name: ");
		scanf("%s", new_entry->name);

		printf("Please enter grade category: (Final=0, Midterm=1, Homework=2, Quiz=3)\n");
		scanf("%d", &new_entry->type);

		printf("Please enter possible points for this assignment: ");
		scanf("%f", &new_entry->possible_points);

		printf("Please enter points earned for this assignment: ");
		scanf("%f", &new_entry->points);

		new_entry->next = head;
		head = new_entry;

		printf("Entry was added successfully!\n");
		return 0; 
	}
	else
	{
		printf("Insufficient Memory\n");
		return -1;
	}
}

int remove_entry()
{
	struct Entry *navi, *prev, *temp; 
	char item[1024];

	printf("Please enter the name of the entry you wanted to delete: ");
	scanf("%s", item);

	if (head == NULL) {
		printf("No records found.\n");
		return 0; 
	}
	else if (head != NULL && strcmp(head->name, item) == 0)
	{
		temp = head; 
		head = head->next; 

		free(head);

		return 0;
	}
	else if (head != NULL)
	{
		navi = prev = head; 

		while (navi->next != NULL) {
			if (strcmp(navi->name, item) == 0) {

				temp = navi; 
				prev->next = navi->next;

				free(temp);

				return 0;
			}
			else {
				prev = navi;
				navi = navi->next;
			}
		}

		if (strcmp(navi->name, item) == 0)
		{
			temp = prev; 
			prev->next = NULL;

			free(navi);
		}
	}

	return 0;
}

int average()
{
	struct Entry *temp; 

	if (head == NULL)
	{
		printf("No records found.\n");
		return -1;
	}
	else
	{
		float possible_points = 0.0; 
		float earned_points = 0.0;

		temp = head; 

		while (temp != NULL)
		{
			printf("\n\nName: %s\n", temp->name);
			printf("Category: %s\n", category_name(temp->type));
			printf("Possible Points: %f\n", temp->possible_points);
			printf("Points Earned: %f\n", temp->points);
			
			possible_points += temp->possible_points;
			earned_points += temp->points;

			temp = temp->next;
		}

		if (possible_points != 0)
			printf("\n\nAverage Grade: %0.2f%%\n\n", (earned_points / possible_points) * 100);

		return 0; 
	}
}

void delete_list(struct Entry *temp)
{
	if (temp != NULL) {
		delete_list(temp->next);
		free(temp);
	}
}

char* category_name(Category type) {
	switch (type)
	{
		case Midterm: 
			return "Midterm";

		case Final:
			return "Final Exam";

		case Homework:
			return "Homework";

		case Quiz:
			return "Quiz";

		default:
			return "Invalid Selection";
	}
}
