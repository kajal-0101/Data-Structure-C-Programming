#include <stdio.h>
#include <stdlib.h>

# define MAX 15

// function to display array
void display(int arr[MAX], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void searchAndUpdate(int arr[MAX], int number)
{
	int search; // variable to store the value to be searched within the array
	int arrayindexes[number]; // array to store the indexes where the matched value is found within the array
	// the size of this array is equal to the number of elements within the array
	int occurence=0, temp_flag=0;
	// occurence = variable to check the no. of searches found, the value 0 indicates that no searches were found, also the loop variable required for arrayindexes array
	// temp_flag must be used for checking if the given index for the purpose of update exists or not
	int j, index, update;
	// j = loop variable, index = to fetch the index from the user if more than one search match found for update
	// update = to store the value to be updated
	int choice; // variable to store choice on whether to update or not
	
	if(number == 0) // no elements within the array
	{
		printf("Cannot perform search and update operation on an empty stack\n");
	}
	else if(number == 1) // only one element within the array
	{
		printf("Since there is only one element within the array, no search operations will be performed\n");
	}
	else // executing the operations of the function
	{
		printf("Enter the element to be searched: ");
		scanf("%d", &search);
		for (j=0; j<number; j++)
		{
			if(arr[j] == search) // if match found
			{
				printf("Element found at %d index\n", j); // printing the index location
				arrayindexes[occurence] = j; // storing the index where the search has been found
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
							if (arrayindexes[j] == index) // if the enetered index matches the index value stored ih the arrayindexes array
							// then the value is updated and the temp_flag is set
							{
								printf("Printing the original array once, before updating the values: \n");
								display(arr, number); // displaying the array before updating it
								arr[index] = update; // updating the value
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
						printf("Printing the original array once, before updating the values: \n");
						display(arr, number); // printing the original array before updating it
						index = arrayindexes[0];
						arr[index] = update;
					}
			
					printf("Printing the current array\n");
					display(arr, number);
					break;
					
				case 2: printf("Printing the array, no updation\n"); // if there is no array update only searching
					display(arr, number);
					break;
				
				default: printf("Wrong choice\n"); // for wrong choice
			}		
		}
	}
	
}



int main()
{
	int choice, number=0;
	int arr[MAX];
	int m = 5; // no. of chances in case wrong choices are selected
	int i;
	int search = 0;
	printf("A linear Search Program to search and update value.\nIn case the search match is more than one, option will be given to choose the index\n");
	printf("Set the array, later the array can be set using the option\nThe maximum permissible size of the array is %d\n", MAX);
	printf("Enter the no. of elements for the array: ");
	scanf("%d", &number);
	if (number <0 || number > MAX)
	{
		printf("This size is not permissible\nPlease try again!\n");
	}
	else
	{
		printf("An array that can fit %d elements have been set\n", number);
		printf("Enter the %d elements\n", number);
		for (i=0; i<number; i++)
		{
			printf("Enter the value: ");
			scanf("%d", &arr[i]);
		}
		printf("Printing the array\n");
		display(arr, number);	
	}
	do
	{
		printf("1) Update the array size and contents\n");
		printf("2) Search and Update Value within the array\n");
		printf("3) Exit\n");
		scanf("%d", &choice);
		system("cls");
		
		switch(choice)
		{
			case 1: printf("Enter the updated size of the array: ");
					scanf("%d", &number);
					
					if (number <0 || number > 15)
					{
						printf("The array cannot be updated\n");
					}
					else
					{
						printf("Enter the %d numbers\n", number);
						for (i=0; i<number; i++)
						{
							printf("Enter the value: ");
							scanf("%d", &arr[i]);
						}
						printf("The array has been updated\n");
						printf("Printing the array\n");
						display(arr, number);	
					}
					break;
			
			case 2: searchAndUpdate(arr, number);
			break;
			
			case 3: printf("Thank you for executing the program\nBye!\n");  // exiting from the program
			exit(0);
			break;
			
			default: printf("Wrong choice\n"); // in case of wrong choice
			m-=1; // chances deducted
			// informing the user about deducting a chance
			printf("You have entered a wrong choice so you have %d chances left to perform executions on the array\n", m);
			if(m==0) // if no more chances are left the program gets over
			{
				printf("Your chances are over\nExiting the system\nThank you\n");
				exit(1);
			}
		}		
	}while(1);
	return 0;
}
