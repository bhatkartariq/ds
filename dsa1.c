// Include standard input output library for printf and scanf
#include <stdio.h>
// Define a constant size as 10 for the array
#define size 10
// Declare a global integer array of size 10
int arr[size];

// Function prototype for insertion function
void insertion();
// Function prototype for deletion function
void deletion();
// Function prototype for display function
void display();
// Main function where program execution begins
int main()
{
	// Declare integer variables for user choice, element to insert, and index
	int choice,element,index;

	// Infinite loop to keep the menu running until exit
	while(1)
	{
		// Print the menu header
		printf("------MENU------ \n");
		// Print the menu options
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit ");
		// Print prompt for user choice
		printf("\nEnter your choice:-");
		// Read the user's choice from input
		scanf("%d",&choice);
		// Switch statement to handle different choices
		switch(choice) {
		case 1:
			// Prompt user to enter the position for insertion
			printf("Enter position:-");
			// Read the index from input
			scanf("%d",&index);
			// Prompt user to enter the element to insert
			printf("Element to be inserted:-");
			// Read the element from input
			scanf("%d",&element);
			// Call the insertion function with index and element
			insertion(index,element);
			break;
		case 2:
			// Prompt user to enter the position for deletion
			printf("Enter position:-");
			// Read the index from input
			scanf("%d",&index);
			// Call the deletion function with index
			deletion(index);
			break;
		case 3:
			// Call the display function to show the array
			display();
			break;
		case 4:
		    // Print program end message
			printf("program end");
			// Return 0 to indicate successful program termination
			return 0;
		default:
			// Print message for invalid choice
			printf("Invalid choice !!!\n");
		}
	}

}
// Function to insert an element at a given index
void insertion(int index,int element)
{
	// Check if the index is out of bounds (less than 0 or greater than 10)
	if(index<0 || index>10)
	{
		// Print error message for invalid position
		printf("Invalid position !!! \n");
	}
	else {
		// Adjust index to 0-based indexing
		index=index-1;
		// Assign the element to the array at the adjusted index
		arr[index]=element;
	}
}
// Function to delete an element at a given index (set to 0)
void deletion(int index)
{
	// Check if the index is out of bounds
	if(index<0 || index>10)
	{
		// Print error message for invalid position
		printf("Invalid position !!!\n");
	}
	else {
		// Adjust index to 0-based
		index=index-1;
		// Set the array element to 0 (simulating deletion)
		arr[index]=0;
	}
	// Return from the function (optional in void functions)
	return;
}
// Function to display the array elements
void display()
{
	// Declare loop variable i
	int i;
	// Print the label for the array
	printf("Array=");
	// Print opening bracket
	printf("[");
	// Loop through the array to print each element
	for(i=0; i<10; i++)
	{
		// Print the current element followed by a comma
		printf("%d,",arr[i]);
	}
	// Print closing bracket and newline
	printf("]\n");
	// Return from the function
	return;
}
