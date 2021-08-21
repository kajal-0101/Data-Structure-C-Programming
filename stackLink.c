#include <stdio.h>
#include <stdlib.h>

// defining the structure of the Linked List Node
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}node;

node *top; // top node of the linked list
int count=0; // global varriable storing the no. of data within the stack Linked List

node *createNode();
void push();
void pop();
void display();
void info();
int isEmpty();
void searchAndUpdate();
int checkDuplicateNode(int );

// function for creating the node of the linked list
node *createNode()
{
	node *p, *q; // node type variables
	p = (node *)malloc(sizeof(node)); // creating memory allocation for the node
	int temp; // to store the input data
	int check = 0; // a flag variable used to check if the entered input already exists within the stack
	printf("Enter the data to be pushed into the stack\n");
	scanf("%d", &temp);
	
	if(top == NULL) // in case the top is NULL, it resembles this is the first node of the stack Linked List
	{
		p->data = temp; // putting the data into the node
		p->next = NULL; // since, there is no next node, making the next as NULL
	}
	else
	{
		check = checkDuplicateNode(temp); // checking if the data exists
		while (check != 1) // until the entered input is unique to the stack, users must be prompt to provide the input value
		{
			check = 0; // re-initialising the variable for the purpose of storing new value
			printf("The entered data already exists\nPlease enter a new data to be pushed into the stack\n");
			scanf("%d", &temp);
			check = checkDuplicateNode(temp); // checking if the data is unique
		}
		p->data = temp;
		p->next = NULL;
	}
	return (p); // returning the node
}

// function for checking if the data entered by the user already exists within the stack Linked List
int checkDuplicateNode(int value)
{
	node *q; // node variable
	int flag = 0; // setting off the flag
	q = top; // making the node pointer variable point to the top pointer
	// iterating throughout the list to check if the data matches
	while(q!=NULL)
	{
		if (q->data == value)
		{
			flag = 1; // the flag is set to 1, in case a data match is found
		}
		q = q->next;
	}
	if (flag == 1) // if a data match is found 0 is returned indicating the user must re-enter the value
		return 0;
	else
		return 1; // if the data is unique to stack Linked List then 1 is returned
}

// function to push the data into the stack Linked List
void push()
{
	node *p; // declaring a node type variable
	p = createNode(); // fetching the created node
	if(top == NULL) // if the top is NULL indicating the stack is empty, then this node is the top
	{
		top = p; // the top pointer points towards the new node
	}
	else
	{
		p->next = top; // the next link of the new node points towards the current top pointer
		top = p; // the new node is the top pointer
	}

	count++; // icrementing the count of the stack
	display(); // displaying the current stack
}

// function to pop value out of the stack - LIFO format
void pop()
{
	node *p; // a node pointer variable
	int r=0; // variable to retrieve the result of the isEmpty() function
	r = isEmpty(); // fetching the result of the isEmpty() function
	if(r == 1) // in case the retrieved value is 1, then the stack is empty.
	{
		printf("The stack is empty\nNo data to be popped\nStack Underflow!\n");
	}
	else
	{
		p = top; // setting the node pointer variable to point towards the current pointer
		top = p->next; // setting the node after the top node as the new node
		printf("The element popped out is %d\n", p->data); // showing the data of the node which is getting freed
		free(p); // freeing the memory
		count--; // decrementing the count of the nodes in the stack Linked List
	}
	display(); // displaying the current stack
}

// function to display the stack Linked List
void display()
{
	node *p; // node pointer variable
	int r=0; // variable to store the result retrieved from the isEmpty() function
	r=isEmpty(); // retrieving the data from teh function
	if(r==1) // in case the retrieved value is 1, then the stack is empty
	{
		printf("\nStack is empty!\n");
	}
	else
	{
		p = top; // pointing the pointer towards the top		
		printf("\nDisplaying the stack\n");
		// iterating through out the whole stack and printing the data of the node 
		while(p != NULL)
		{
			printf("%d\t", p->data);
			p=p->next;
		}
		printf("\n");
	}	
}

// function to provide information on the stack Linked List
void info()
{
	printf("\nDisplaying the data related to the stack\n");
	if(top == NULL) // if the top is NULL, it must be informed
	{
		printf("Stack Top = NULL\n");
	}
	else // the value of the top pointer is printed
	{
		printf("Stack top = %d\n", top->data);	
	} // the no. of entries within the stack Linked List also gets printed
	printf("Stack count = %d\n", count);
	display(); // the stack is displayed
}

// function used to check if the stack Linked List is empty
int isEmpty()
{
	int i=0;
	if(top == NULL) // if the top is NULL 1 is returned indicating the stack is empty else 0 is returned indicating the stack is not empty
	{
		i=1;
	}
	return i;
}

// this function searches for an element within the stack and also provides the opportunity to update it
void searchAndUpdate()
{
	int key, option, update;
	// key stores the value to be searched within the stack LinkedList
	// option stores the value used to decide if the value needs to be updated or not
	// update store the updated value
	int i=0, check=0; // i = variable to track the position of the node, check = variable used to signal if duplicate data is being entered 
	int flag=0;
	node *p, *q; // node pointer variables
	if(top == NULL) // if the stack is empty then no search or update operations can be performed withn the stack
	{
		printf("The stack is empty, so neither data can be searched nor data can be updated\n");
	}
	else
	{
		printf("Enter the data to be searched\n");
		scanf("%d", &key); // the data to be searched is received from the user
		p = top;
		while(p!=NULL) // iterating throughout the stack to look for the value
		{
			if(p->data == key) // if the match is found, the user gets informed
			{
				printf("The entered data %d has been found at position %d\n", key, (i+1));
				flag = 1; // flag is set to 1 indicating that the match has been found
				printf("Do you want to update the value?\n1) Yes\t2) No\n");
				scanf("%d", &option);
				switch(option)
				{
					case 1: printf("Enter the new data\n"); // if the value needs to be updated the value is taken from the user
						scanf("%d", &update);
						printf("Showing the stack before updating the data\n");
						display(); // showing the stack once before updating the value
						q = top; // checking if the entered data already exists within the stack
						while(q != NULL)
						{	
							if(q->data == update)
							{
								while (check != 1) // until the entered input is unique to the stack, users must be prompt to provide the input value
								{
									check = 0; // re-initialising the variable for the purpose of storing new value
									printf("The entered data already exists\nPlease enter a new data to be pushed into the stack\n");
									scanf("%d", &update);
									check = checkDuplicateNode(update); // checking if the data is unique
								}
							}
							q = q->next;
						}
						p->data = update;
						printf("\nData updated successfully\n");
						display(); // displaying the data after updating the stack
						break;

					case 2: printf("No data updated\n"); // no data gets updated
						display();
						break;
				
					default: printf("Wrong option\n"); // in case of wrong option
				}
				break;			
			}
			else
			{
				flag = 0;
			}
			i++;
			p = p->next;
		}
		if(flag == 0) // if match not found
		{
			printf("The data wasn't found, so can't be updated\n");
			display();
		}	
	}
}


int main()
{
	int option; // to store the option given as input by the user
	int m = 5; // counter to be deducted if wrong choice entered
	int r = 0; // for checking if the stack is Empty
	printf("\nImplementation of stack using Linked list\nSince this is a linked list implementation, therefore stack overflow cannot be checked\nThis stack does take duplicate data\n");
	do
	{
		printf("\nChoose among the following\n");
		printf("1) Push()\n");
		printf("2) Pop()\n");
		printf("3) Information on the stack\n");
		printf("4) Check whether the stack is empty\n");
		printf("5) Search and update\n");
		printf("6) Exit\n");
		scanf("%d", &option);
		system("cls");
		switch(option)
		{
			case 1: push();
			break;

			case 2: pop();
			break;

			case 3: info();
			break;

			case 4: r = isEmpty();
			if(r==1)
			{
				printf("The stack is empty\n");
			}
			else
			{
				printf("The stack is not empty\nNo. of entries in the stack: %d\n", count);
			}
			break;

			case 5: searchAndUpdate();
			break;
			
			case 6: printf("Thank you for executing the program\nThank you!\n");
			exit(0);
			break;
			
			default: printf("Wrong choice\n");
			m-=1;
			if(m==0)
			{
				printf("Your chances are over\nExiting the system\nThank you\n");
				exit(1);
			}

		}
	}while(1);
	return 0;
}


