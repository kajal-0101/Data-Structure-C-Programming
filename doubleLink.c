#include <stdio.h>
#include <stdlib.h>

// structure of the double linked list node, one pointer to the previous node, data, pointer that points to the next node
typedef struct Dnode
{
	struct Dnode *prev;
	int data;
	struct Dnode *next;
}node;

node *start; // node pointer that points to the start of the linked list
int count; // node that keeps a track of the no. of nodes within the linked list

node *createNode(); // creates new unique node
node *insertFirst(node *); // for inserting the node in the beginning of the list
node *insertLast(node *); // for inserting the node at the end of the list
node *deleteFirst(node *); // for deleting the first node of the list
node *deleteLast(node *); // for deleting the last node of the list
node * searchAndUpdate(node *); // for searching a node within the list and according to choice performing updates
node *display(node *); // for displaying the double linked list
int checkExistNode(int ); // checks if the value already exists, used for entering new data as well as to check if the node exists
node *getLastNode(node *); // for retrieving the tail or last node of the list
void showLLInfo(node *); // for getting double link list related informations, start data, tail data, total no. of nodes in the list and displaying the list

// this function creates a new node
node *createNode()
{
	node *p; // node variable
	int temp, check=0; // temp stores the input value and check is a flag to check if the value already exists in the list
	p = (node *)malloc(sizeof(node)); // allocating memory for the node
	printf("Enter the data of the node\n");
	scanf("%d", &temp); // taking the input
	check = checkExistNode(temp); // checking if the data exists
		while (check != 1) // until the entered input is unique to the stack, users must be prompt to provide the input value
		{
			check = 0; // re-initialising the variable for the purpose of storing new value
			printf("The entered data already exists\nPlease enter a new data for the node\n");
			scanf("%d", &temp);
			check = checkExistNode(temp); // checking if the data is unique
		}
	p->prev = NULL; //  making the prev pointer NULL to avoid making it a dangling pointer
	p->next = NULL; //  making the next pointer NULL to avoid making it a dangling pointer
	p->data = temp; // putting the input value within the node
	return (p); // returning the node
}

// this function checks if the entered value already exists in the list or not
// it takes an input value as its input
int checkExistNode(int value)
{
	node *q; // node variable
	int flag = 0; // setting off the flag
	q = start; // making the node pointer variable point to the top pointer
	// iterating throughout the list to check if the data matches
	while(q!=NULL)
	{
		if (q->data == value)
		{
			flag = 1; // the flag is set to 1, in case a data match is found
		}
		q = q->next;
	}
	if (flag == 1) // if a data match is found 0 is returned 
		return 0;
	else
		return 1; // if the data is unique to the Double Linked List then 1 is returned
}

// this function enters the new node at the beginning of the list
node *insertFirst(node *s)
{
	node *p, *q, *i; // node variables
	i = s; // i points towards the start
	p = createNode(); // creating a new node
	if(i == NULL) // if the list is empty then this is the first node of the list
	{
		i = p;
	}
	else  
	{
		p->next = i; // the new node points towards the current start node
		i = p; // the new node becomes the start node
		p->prev = NULL; // making the prev pointer NULL
	}
	
	count++; // incrementing the count
	display(i); // displaying the list
	return (i);	
}

// this function enters the new node at the end of the list
node *insertLast(node *s)
{
	node *p, *q, *i; // node variables
	int j = 0; // count variable to count the no. of nodes traversed in the list
	i = s; // i points towards the start
	p = createNode(); // creating a new node
	if(i == NULL) // if the list is empty then this is the first node of the list
	{
		i = s;
	}
	else
	{
		q = i;	//node variable pointing towards the start node	
		while(q->next != NULL) // interating until the last node of the list is reached
		{
			q = q->next;
			j++; // incrementing the count
		}
		// placing the node at the last
		p->next = q->next; // the new pointer's next link points where the present last node's next pointer points
		p->prev = q; // the new node's prev pointer points at the previous last node
		q->next = p; // the previous last node points towards the new last node
		printf("The node has been inserted after %d nodes\n", (j+1));
	}
	count++; // incrementing the count
	display(i); // displaying the list
	return (i);		
}

// function to inserts a new node at a particular location, the index counting begins at 0
node *insertParticular(node *s)
{
	node *i, *p, *q, *r; // node variables
	int index, j=0; // to store the index value retrieved as input, j = loop variable
	i = s; // i points towards the start
	printf("Enter the index no. where the new node needs to be placed: ");
	scanf("%d", &index); // taking the index as the input
	if (index <0 || index > count) // the index won't be feasible if the value is less than 0 or more than the present no. of nodes
	{
		printf("The entered index cannot be accessed\n");
	}
	else
	{
		if (index ==0) // if the entered index is 0, the node is entered at the beginning of the list
		{
			printf("Displaying the list before entering the new value\n");
			display(i);
			i = insertFirst(i);
		}
		else if (index == count) // if it is equal to the count value, the new node is entered at the end
		{
			printf("Displaying the list before entering the new value\n");
			display(i);
			i = insertLast(i);
		}
		else // to eneter at a particular index
		{
			p = createNode(); // creating the new node
			printf("Displaying the Double Linked List before inserting the new node: \n"); // display the current list
			display(i);
			q = i; // q node varaible points to the start
			while(q->next != NULL) // iterating until the last node is reached
			{
				r = q; // r pointer points at the present node q pointer is pointing at 
				q = q->next; // q pointer points at the next node
				j++; // incrementing the counter variable
				if (j==index) // if the value of the counter variable is equal to the entered index
				{
					printf("The node after this node: %d\n", q->data);
					printf("The node before this node: %d\n", r->data);
					p->next = q; // the new node's next pointer points at the node which should be at its right
					p->prev = r; // the new node's prev pointer points at the node which should be at its left
					r->next = p; // the left node's next pointer points at the new node
					q->prev = p; // the right node's prev pointer points at the new node
				}
			}
			printf("The new node has been inserted\n");
			count ++; // incrementing the counter
			display(i);
		}
	}
	return (i);
}

// function to delete the first node of the list
node *deleteFirst(node *s)
{
	node *p, *i; // node variables
	i = s; // i points towards the start
	if(i == NULL) // if the list is empty then this is the first node of the list
	{
		printf("The list is empty\nSo nothing to delete!\n");
	}
	else if(i->next == NULL) // in case this is the only node in the list
	{
		printf("The deleted info is : %d\n", i->data);		
		i = NULL;
	}
	else
	{ // deleting the first node of the list
		p = i; // pointing towards the start pointer
		i = p->next; // the start pointer points towards its next pointer
		p->next->prev = NULL; // Nullifying the next node's prev pointer
		printf("The deleted data is %d\n", p->data);
		free(p); // removing the old start pointer
	}
	count--; // decrementing count
	display(i);
	return (i);	
}

// this function deletes the last node of the linked list
node *deleteLast(node *s)
{
	node *p, *q, *i; // node variables
	i = s; // i points towards the start
	if(i == NULL) // if the list is empty then this is the first node of the list
	{
		printf("No such node to delete\n");
	}
	else if(i->next == NULL) // in case this is the only node in the list
	{
		printf("The linked list is getting empty\nThe first node is getting deleted\nDeleted ifo: %d\n", i->data);
		i = NULL;
	}
	else
	{
		p = i; // pointing towards the start node
		while(p->next != NULL) // iterating until the last node is reached
		{			
			q = p;			
			p = p->next;
		}
		q->next = NULL; // making the next pointer null
		p->prev = NULL; // detaching the last node
		printf("The deleted data is %d\n", p->data);
		free(p);
	}
	count--; // decrementing the count
	display(i); // displaying the linked list
	return (i);
}

node *deleteParticular(node *s)
{
	node *p, *i, *q, *r; // node variables
	int key, j=0, check=0; // key = variable that stores the value to be deleted
	// j = count variable used to get the location value of nodes
	// check = variable that is used to check if the entered key exists within the double linked list or not
	i = s; // i points towrads s
	printf("Enter the key to be deleted\n");
	scanf("%d", &key);
	check = checkExistNode(key); // checking if the node exists
	if  (check != 0) // node does not exist
	{
		printf("No such data exists thus this data cannot be deleted\n");
	}
	else
	{
		if(i == NULL) // list is empty
		{
			printf("No nodes are there to be deleted in the linked list\n");
		}
		else
		{
			if(i->data == key) // if the start key is to be deleted
			{
				if(i->next == NULL)
				{
					printf("The linked list is getting empty\nThe first node is getting deleted\nDeleted info: %d\n", i->data);
					i = NULL;
				}
				else
				{
					p = i;
					i = p->next;
					p->next->prev = NULL;
					printf("The deleted data is %d\nThe first node got deleted\n", p->data);
					free(p);
				}
			}
			else
			{
				p = i;
				while(p->next!= NULL)
				{
					q = p;
					p = p->next;
					j++;
					if (p->data == key)
					{
						if (p->next != NULL) // deleting any node within the lsit except the first and  the last node
						{
							r = p->next;
							printf("The next node of the deleted node: %d\n", r->data);
							printf("The previous node of the deleted node: %d\n", q->data);
							printf("The node at %d location got deleted\n", (j+1));
							r->prev = q;
							q->next = r;
							printf("The deleted data is %d\n", p->data);
							
							free(p);
						}
						else // deleting the last node of the linked list
						{
							q->next = NULL;
							p->prev = NULL;
							printf("The last node got deleted\n");
							printf("The deleted data is %d\n", p->data);
							free(p);	
						}		
					}
				}
			}
		}
	}
	count--;
	display(i);
	return (i);
} 

// function to search value within the double linked list
// ths function provodes an option to update the node's value if the search matches
node * searchAndUpdate(node *s)
{
	node *p, *q, *i; // node variables
	int key, option, update; 
	// key = the value to be searched within the double linked list
	// option = variable to store value that helps the program to decide if the user wishes to update the data if search match is found
	// update = this variable takes the updated data from the user
	int flag = 0, check=0; // flag = variables; check = to check if the data match has been found (to find out duplicate values)
	int j = 0; // count variable that gives the location details
	i = s; // i points towards the start
	if(i == NULL) // no search operation can be performed if the double linked list is empty
	{
		printf("The linked list is empty, thus, neither the search nor update operation can be done\n");
	}
	else
	{
		printf("Enter the data\n");
		scanf("%d", &key); // takes in the value to be searched within the double linked list
		p = i; 
		while(p != NULL) // iterating throughout the loop
		{
			if(p->data == key)
			{
				printf("The key %d had been found at index %d\n", key, (j+1));
				printf("Do you want to continue?\n1) Yes\t2)No\n");
				scanf("%d", &option);
				system("cls");
				switch(option)
				{
					case 1: printf("Enter the data to be updated\n");
						scanf("%d", &update);
						check = checkExistNode(update); // checking if the data exists
						while (check != 1) // until the entered input is unique to the stack, users must be prompt to provide the input value
						{
							check = 0; // re-initialising the variable for the purpose of storing new value
							printf("The entered data already exists\nPlease enter a new data to be pushed into the stack\n");
							scanf("%d", &update);
							check = checkExistNode(update); // checking if the data is unique
						}
						printf("Displaying the list before updating it: \n");
						display(i); // displaying the data
						p->data = update; // updating the data
						printf("The data has been updated successfully\n");
						display(i);
						break;
		
					case 2: printf("No data was updated\n"); // no data update took place
						display(i); 
						break;

					default: printf("Wrong option\n");

				}
				flag = 1; // indicating search found
				break;
			}
			else
			{
				flag = 0; // no search found
			}
			j++; // increasing the count
			p = p->next; // moving on the next node	
		}
	}
	return (i);
	
}

// function to display the double linked list's contents
node *display(node *s)
{
	node *p, *i; // node variables
	i = s; // i poibts towards the start
	printf("Displaying the linked list\n");
	if(i == NULL) // if the double linked list is empty then there is nothing to display
	{
		printf("The linked list does not have any nodes\nNothing to display\n");
	}
	else
	{
		p = i; // pointing towards the start
		while(p != NULL) // iterating through the list
		{
			printf("%d\t", p->data); // printing the node's data
			p = p->next; // moving to the next node
		}
		printf("\n");
	}
	return (i);
}

// this program focuses on using the start node to perform operations
// this function retrieves the last node of the double linked list
node *getLastNode(node *s)
{
	node *i, *q; // node variables
	i = s; // i points towrards the start
	q = i;
	while (q->next != NULL) // iterating the loop to reach the last node
	{
		q = q->next;
	}
	return q; // returning the retrieved last node of the list
}

// this function shows the double linked list related informations
void showLLInfo(node *s)
{
	node *i, *q; // node variables
	i = s; // i points towrards the start
	if (i== NULL) // if the double linked list is empty then there is nothing to display
	{
		printf("Nothing to display\n");
		printf("Total no. of nodes in the list: 0\n");
	}
	else
	{
		printf("Start node: %d\n", i->data); // printing the start node's data
		q = getLastNode(i); // retrieving the last node
		printf("Last node: %d\n", q->data); // printing the last node's data
		printf("Total no. of nodes in the list: %d\n", count); // printing the total no. of nodes in the list
		printf("Displaying the linked list: \n"); // displaying the linked list
		display(i);	
	}
}
	
int main()
{
	int option, option1, option2;
	int c = 1;
	int h = 1;
	do
	{
		printf("\n\nChoose among the following: \n");
		printf("1) Insertion in Linked list\n"); // contains operations related to insertion into the linked list
		printf("2) Deletion in Linked list\n"); // contains operations related to deletion from the linked list
		printf("3) Search and Update the data\n"); // for searching and if needed updating value in the linked list
		printf("4) Show Double Linked List details\n"); // shows the details of the linked list
		printf("5) Exit\n"); // exiting from the program
		scanf("%d", &option); // receiving the choice from the user
		system("cls");
		switch(option)
		{
			case 1: do
				{
					printf("Choose among the following\n");
					printf("1) Insert at first of the linked list\n");
					printf("2) Insert at the end of the linked list\n");
					printf("3) Insert the node at a particular index of the linked list\n");
					printf("4) Exit\n");
					scanf("%d", &option1);
					system("cls");
					switch(option1)
					{
						case 1: start = insertFirst(start); // insert in the beginning
						break;

						case 2: start = insertLast(start); // insert at the last
						break;
						
						case 3: start = insertParticular(start); // insert the node at a particular location
						break;
						
						case 4: c = 4; // breaking out from the loop
						break;
				
						default: printf("Wrong choice\n");
					}
				}while(c != 4);		
				break;

			case 2:do
				{
					printf("Choose among the following\n");
					printf("1) Delete from the first of the linked list\n"); 
					printf("2) Delete from the end of the linked list\n"); 
					printf("3) Delete particular node\n"); 
					printf("4) Exit\n"); 
					scanf("%d", &option2);
					system("cls");
					switch(option2)
					{
						case 1: start = deleteFirst(start); // deleting the first node of the linked list
						break;

						case 2: start = deleteLast(start); // deleting the last node of the linked list
						break;
						
						case 3: start = deleteParticular(start); // deleting a partcular node of the linked list
						break;

						case 4: h = 4; // exit
						break;
				
						default: printf("Wrong choice\n");
					}
				}while(h != 4);			
				break;
			break;
			
			case 3: start = searchAndUpdate(start); // searching for a node within the linked list 
			break;
	
			case 4: showLLInfo(start); // for displaying the information related to the linked list
			break;
	
			case 5: printf("Exiting from the program\nThank you for executing the program\n");
			exit(0); // exiting the program
			break;

			default: printf("Wrong option\n"); // wrong option
		}
	}while(1);
	
	return 0;
}
