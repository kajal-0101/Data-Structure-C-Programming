/* Program to implement Selection Sort */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Protyping */
void swap(int *, int *);
void display(int [], int );
void selectionSort(int [], int );

/* Code for Selection sort */
void selectionSort(int arr[15], int n)
{
	int i, j, smallest;
	for(i=0; i<n; i++)
	{
		smallest = i;
		printf("smallest = %d\n", arr[smallest]);
		printf("Pass no: %d\n", (i+1));
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < arr[smallest])
			{
				smallest = j;
			}
		}
		swap(&arr[i], &arr[smallest]);   /* swapping elements */
		printf("Intermediate elements: ");
		display(arr, n);
		printf("\n");
	}
}

/* Code for displaying the array */
void display(int arr[15], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/* Code for swapping elements */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int arr[15];
	int i, n;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter %d elements: ",n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	system("cls"); // in case using ubuntu, change cls to clear
	printf("The entered numbers are: ");
	display(arr, n);
	selectionSort(arr,n);
	printf("After sort the elements are: ");
	display(arr, n);
	return 0;
}
