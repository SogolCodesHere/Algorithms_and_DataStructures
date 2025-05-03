#include "Lab1_QueueList_Template_Lib.h"

/*
This function inserts a new student in the waiting line.
If the queue is already full, the function prints a message on the console
that informs the user that no more students can be inserted in the queue.
If the queue is not full, the function asks the user for the first name, the last name, and the matriculation number.
Then, it adds this student as the last element to the queue.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
   The functions returns the first student of the waiting line.
*/
sElement* enqueue(sElement* head) {
	sElement newStudent = { 0 };
	sElement* newNode = malloc(sizeof(sElement));	//allocating memory for a new ONE student aka. a pointer to a newly created node for our list in memory
	sElement* current = NULL;

	while (1) {
		if (newNode == NULL) {
			printf("The queue is full. No more student can be inserted in the queue.\n\n");
			return head;
		}
		else {
			printf("\nPlease enter the new student's 1.First Name, 2.Last Name, 3.Matriculation Number: ");

			if (scanf("%s %s %lu", newStudent.student.firstName, newStudent.student.lastName, &newStudent.student.matNo) != 3) {
				while (getchar() != '\n');
				printf("The input is invalid. Please enter a valid one, as asked above.\n\n");
				free(newNode);
				return head;
			}
			else {
				while (getchar() != '\n');
				printf("Student %s %s, %lu was successfuly added to the queue.\n\n\n",
					newStudent.student.firstName, newStudent.student.lastName, newStudent.student.matNo);

				//Copying the new data into the new node
				newNode->student = newStudent.student;	//Take the "student" info from "newStudent" and put it into the "student" part of "newNode"
				newNode->next = NULL;	//This is the last student in the line, d.h. there's no next person after this one.

				//Checking if it's empty
				if (head == NULL) {
					head = newNode;
				}
				else {
					current = head;
					while (current->next != NULL) {
						current = current->next;
					}
					current->next = newNode;
				}
			}
		}
		return head;
	}
}


/*
This function removes the first student from the waiting line.
If the queue is empty, the function prints a message to the console
that informs the user that the waiting list does not contain any students.
If the queue is not full, the function prints the full name and matriculation number of the first student of the waiting line to the console.
Second, it removes the student from the queue and frees the memory.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
   The functions returns the first student of the waiting line.
*/
sElement* dequeue(sElement* head) {
	sElement* current = NULL;

	if (head == NULL) {
		printf("The queue is empty.\n");
		return NULL;
	}
	else {
		printf("The student %s %s %lu was successfully removed from the queue.\n", 
			head->student.firstName, head->student.lastName, head->student.matNo);
		current = head;
		head = head->next;
		free(current);
		return head;
	}
}


/*
This function checks if the waiting line is empty.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
 - If the waiting line is empty, the function returns 0.
 - If there are students in the waiting line, the function returns 1.

*/
int isEmpty(sElement* head) {
	if (head == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}


/*
This function counts the number of students in the waiting line and returns this number.

Parameters:
   head -> pointer to the first student of the waiting line

Returns:
 - Number of students in the waiting line.
 - If the waiting line is empty the function returns 0.
*/
int countElements(sElement* head) {
	int counter = 0;
	sElement* temp = head;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	return counter;
}


/*
This function prints the full names and matriculation number of all students in the waiting line to the console.
The printing starts with the first student in the waiting line and prints the other students in the order of insertion.

Parameters:
   head -> pointer to the first student of the waiting line

Returns: None
*/
void printQueue(sElement* head) {
	if (head == NULL) {
		printf("Queue is empty.\n\n");
		return;
	}

	int numberStudent = countElements(head);
	sElement* temp = head;
	for (int i = 0; i < numberStudent; i++) {
		printf("Student %3d:\t%s\t%s\t%d\n", i + 1, temp->student.firstName, temp->student.lastName, temp->student.matNo);
		temp = temp->next;
	}
	printf("\n");
	return;
}


/* ***** HELPER FUNCTIONS ***** */

/*
* Function reads a positive integer safely from the keyboard.
*
* Parameters: None.
*
* Returns: A positive integer read from the keyboard.
*/
int getInt() {
	int val = 0;
	while (1) {
		if ((scanf("%d", &val) != 1) || (val < 0)) {
			while (getchar() != '\n');
			printf("Not a valid integer.\n");
		}
		else {
			while (getchar() != '\n');
			break;
		}
	}
	return val;
}


/*
* Function reads a string safely from the keyboard.
*
* Parameters: A string in which the string read from the keyboard is stored.
*
* Returns: None
*/
void getString(char string[MAXNAME]) {
	int val = 0;
	while (1) {
		if (scanf("%s", string) != 1) {
			while (getchar() != '\n');
			printf("Not a valid string.\n");
		}
		else {
			while (getchar() != '\n');
			break;
		}
	}
	return;
}