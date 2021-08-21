#include <stdio.h>
#include <stdlib.h>

#define MAX 15
int stack[MAX]; // initiating the stack array
int count = 0; // setting the global count variable 
int top = -1; // initiating the top of the stack

void push(); // function to push value into the stack
void pop(); // function to pop value out of the stack
void display(); // function to display the contents of the stack
void info(); // function to view the information related to the stack, not the same as the display function
int isEmpty(); // a function to check if the stack is empty
int isFull(); // a function to check of the stack is full
void searchAndUpdate(); // a functioin that searched for a vaue within the stack and also provides an option to update the value

// function to display the contents of the file
void display(){
	int i; // loop variable
	int r = 0; // variable to store the result of the isEmpty() function
	r = isEmpty(); // retrieving the result
	// if the stack os empty then there will be nothing to display
	if(r==1){
		printf("Nothing to display, the stack is empty\n");
	}
	else // display the contents of the stack
	{
		for(i=top; i>=0; i--)
		{
			printf("%d\t", stack[i]);
		}
		printf("\n");
		printf("Top at index: %d\n", top);
	}
}

int isEmpty(){
    // if the returned value of i is 0 then the stack is not empty, if its 1 then the stack is empty
	int i=0;
	// checking if the stack is empty
	if(top == -1){
		i = 1;
	}
	return i;
}

// function to pop value out of the stack
void pop(){
	int r = 0; // variable to store the result of isEmpty() function
	r = isEmpty(); // retrieving the result
	// if the stack is empty, i.e. the value retrieved is 1, then pop operation cannot be executed
	if(r == 1){
		printf("Data cannot be popped as the stack is empty\n");
	}
	else // the last entered value is popped out from the stack
	{
		// showing the element getting popped out
		printf("The elements being popped of is %d\n", stack[top]);
		// decrementing the top pointer
		top = top - 1;
		// decrementing the count value
		count --;
		// displaying the stack contents after the current operation
		display();
	}
}

// function to check if the stack is ful
int isFull(){
	int i=0; // variable to store the value that wil be returned by this function
	// if the stack is full return 1, else 0
	if(top == MAX-1){
		i = 1;
	}
	return i;
}

// function to push value into the stack
void push(){
	int i, j=0;
	int r = 0; // variable to store the value of the isFull() function
	int value;
	r = isFull(); // retrieving the value
	if(r == 1) // if the stack is full, no more entries can be pushed in
	{
		printf("Data cannot be added as the stack is full\n");
	}
	else
	{
		r = 0; // required to check if the stack is empty and going to have its first entry
		printf("Enter the element to be added into the stack\n");
		scanf("%d", &value);
		r = isEmpty(); // checking if the stack is empty
		if (r == 1) // first element pushed into the empty stack
		{
			printf("The first element is being added into the stack\n");
		}
		// incrementing the top pointer, pushing the value into the stack and incrementing the counter	
		top = top + 1;
		stack[top] = value;
		count ++;
		// displaying the result after the operation
		display();
	}
}

void searchAndUpdate()
{
	int search; // variable to store the value to be searched within the stack
	int stackindexes[count]; 
	// search = element to be searched
	int occurence = 0, temp_flag=0;
	// occurence = variable to check the no. of searches found, the value 0 indicates that no searches were found, also loop variable required for stackindexes array
	// temp_flag must be used for checking if the given index for the purpose of update exists or not
	int j, index, update;
	// j = loop variable, index = to fetch the index from the user if more than search match found for updation
	// update = to store the value to be updated
	int choice;
	// variable to store choice on whether to update or not
	int isEmp; // variable to retrieve the detail on whether the stack is empty
	
	isEmp = isEmpty(); //getting the details
	// in case the received value is 1, the operations of this function cannot be executed
	if(isEmp == 1)
	{
		printf("Cannot perform search and update operation on an empty stack\n");
	}
	else // executing the operations of the function
	{
		printf("Enter the element to be searched: ");
		scanf("%d", &search);
		for (j=0; j<=top; j++)
		{
			if(stack[j] == search) // if match found
			{
				printf("Element found at %d index\n", j); // printing the index location
				stackindexes[occurence] = j; // storing the index where the search has been 
				occurence += 1; // incrementing the variable value of occurence by 1
			}
		}
		if (occurence==0) // in case the element was not found
		{
			printf("Element not found\n");
		}
		printf("Total search matches: %d\n", occurence); // showing the no. of times the element searched was found
		if(occurence!=0) // in case the element was found
		{
			printf("Do you want to update the value: 1) Yes 2) No\n"); // choice if the value needs to be updated
			printf("Choice: ");
			scanf("%d", &choice);
			switch(choice){
				case 1: printf("Enter the updated value: ");
					scanf("%d", &update);
					if (occurence > 1) // in case the occurence is greater than 1
					{
						printf("Enter the index whose value needs to be updated: ");
						scanf("%d", &index); // getting the index where the value needs to be updated
						for (j =0; j<occurence; j++)
						{
							if (stackindexes[j] == index) // if the enetered index matches the index value stored ih the stackindexes stack
							// then the value is updated and the temp_flag is set
							{
								printf("Printing the original stack once, before updating the values: \n");
								display(); // displaying the stack before updating it
								stack[index] = update; // updating the value
								temp_flag = 1; // setting the temp_flag
							}
						}
						if (temp_flag == 1) // in case of successful update
						{
							printf("Stack has been updated successfully!\n");
						}
						else// there can be two types of wrong index input, one less than 0 or >= 0 (the index is not present with the stackindexes stack)
						{
							if (index < 0) // if the entered index is less than 0
							{
								printf("Please check your value and retry, index can't be less than 0!\n");
							}
							else // for other cases
							{
								printf("The given index is not currently available or allowed!\n");
							}
						}
					}
					else if (occurence == 1) // if the no. of occurence is only 1
					{
						printf("Printing the original stack once, before updating the values: \n");
						display(); // displaying the stack before updating it
						index = stackindexes[0];
						stack[index] = update;
						printf("\nStack updated successfully\n");
					}
			
					printf("Printing the current stack\n");
					display();
					break;
					
				case 2: printf("Printing the stack, no updation\n"); // if there is no stack update only searching
					display();
					break;
				
				default: printf("Wrong choice\n"); // for wrong choice
			}		
		}
	}
	
}

void info()
{
	int r = 0; // variable for storing the value obtained from the isEmpty() and isFull() stack
	printf("\nDisplaying the data related to the stack\n");
	r = isEmpty();
	if(r == 1) // f the stack is empty
	{
		printf("Stack is Empty\n");
	}
	else
	{
		r = isFull();
		if (r == 1) // if the stack is full
		{
			printf("Stack is Full\n");
		}
		printf("Stack top = %d\n", stack[top]);	// printing the stack top value
	}
	printf("Stack count = %d\n", count); // printing the no. of values within the stack
	// displaying the stack
	display();
}



int main()
{
	int option; // variable to store the option entered by the user
	int m = 5; // no. of chances in case wrong choices are selected
	int r = 0; // varaible for executing teh isEmpty() and isFull() functions
	printf("\nImplementation of stack using Array\n");
	printf("You have %d chances left to perform executions on the stack, in case of wrong choice\n", m);
	do
	{
		printf("\nChoose among the following\n");
		printf("1) Push()\n");
		printf("2) Pop()\n");
		printf("3) Information on the stack\n");
		printf("4) Check whether the stack is empty\n");
		printf("5) Check whether the stack is full\n");
		printf("6) Search and Update value\n");
		printf("7) Exit\n");
		scanf("%d", &option);
		system("cls"); // to clear the screen, (Windows OS)
		switch(option)
		{
			case 1: push(); // performing the push operation
			break;

			case 2: pop(); // performing the pop operation
			break;

			case 3: info(); // showing the information
			break;

			case 4: r = 0; // checking if the stakc is empty
			r = isEmpty();
			if(r==1)
			{
				printf("The stack is empty\n");
			}
			else
			{
				printf("The stack is not empty\nNo. of entries in the stack: %d\n", count);
			}
			break;

			case 5: r = 0; // checking if the stack is full
			r = isFull();
			if(r==1)
			{
				printf("The stack is full\n");
			}
			else
			{
				printf("The stack is not full\nNo. of entries in the stack: %d\n", count);
			}
			break;
			
			case 6: searchAndUpdate(); // performing search and update related tasks
			break;
			
			case 7: printf("Thank you for executing the program\nBye!\n");  // exiting from the program
			exit(0);
			break;
			
			default: printf("Wrong choice\n"); // in case of wrong choice
			m-=1; // chances deducted
			// informing the user about deducting a chance
			printf("You have entered a wrong choice so you have %d chances left to perform executions on the stack\n", m);
			if(m==0) // if no more chances are left the program gets over
			{
				printf("Your chances are over\nExiting the system\nThank you\n");
				exit(1);
			}

		}
	}while(1); // the program executes in a do-while infinite loop
	return 0; 
}



