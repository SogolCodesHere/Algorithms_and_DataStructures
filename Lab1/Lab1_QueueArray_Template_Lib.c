#define _CRT_SECURE_NO_WARNINGS

#include "Lab1_QueueArray_Template_Lib.h"

/*
This function inserts a new student in the waiting line.
If the queue is already full, the function prints a message to the console
that informs the user that no more students can be inserted in the queue.
If the queue is not full, the function asks the user for the first name, the last name, and the matriculation number.
Then, it adds this student as last element to the queue.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void enqueue(sStudent waitingLine[]) {
	sStudent newStudent = { 0 };			//To prevent getting errors of uninitialized variable ==> set it to { 0 }, though it is a struct with "3" members
	int index = countElements(waitingLine); // check again later

	while (1) {
		if (index == MAXARRAY) {
			printf("The queue is full. No more student can be inserted in the queue.\n\n");
			break;
		}
		else {
			printf("\nPlease enter the new student's 1.First Name, 2.Last Name, 3.Matriculation Number: ");

			if (scanf("%s %s %lu", newStudent.firstName, newStudent.lastName, &newStudent.matNo) != 3) {
				while (getchar() != '\n');
				printf("The input is invalid. Please enter a valid one, as asked above.\n\n");
				break;
			}
			else {
				while (getchar() != '\n');
				printf("Student %s %s, %lu was successfuly added to the queue.\n\n\n", newStudent.firstName, newStudent.lastName, newStudent.matNo);
				waitingLine[index] = newStudent;	// ??
				index++;
				break;
			}
		}
	}
}


/*
This function removes the first student from the waiting line.
If the queue is empty, the function prints a message to the console
that informs the user that the waiting list does not contain any students.
If the queue is not full, the function first prints the full name and matriculation number of the first student of the waiting line to the console.
Second, it removes the student from the queue by moving all students forward one place in the array.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void dequeue(sStudent waitingLine[]) {
	return;
}


/*
This function checks if the waiting line is empty.

Parameters:
   waitingLine -> Array storing the students

Returns:
 - If the waiting line is empty, the function returns 0.
 - If there are students in the waiting line, the function returns 1.

*/
int isEmpty(sStudent waitingLine[]) {
	if (countElements == 0)
		printf("The queue is empty.\n");

	return 0;
}


/*
This function counts the number of students in the waiting line and returns this number.

Parameters:
   waitingLine -> Array storing the students

Returns:
 - Number of students in the waiting line.
 - If the waiting line is empty the function returns 0.
*/
int countElements(sStudent waitingLine[]) {
	int counter = 0;
	for (counter = 0; counter < MAXARRAY; counter++) {
		if (waitingLine[counter].matNo == 0)
			break;
	}
	return counter;
}


/*
This function prints the full names and matriculation number of all students in the waiting list to the console.
The printing starts with the first student in the waiting line and prints the other students in the order of insertion.

Parameters:
   waitingLine -> Array storing the students

Returns: None
*/
void printQueue(sStudent waitingLine[]) {
	int numberStudents = countElements(waitingLine);
	for (int i = 0; i < numberStudents; i++) {
		printf("Student %3d:\t%s\t%s\t%ld\n", i + 1, waitingLine[i].firstName, waitingLine[i].lastName, waitingLine[i].matNo);
	}
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