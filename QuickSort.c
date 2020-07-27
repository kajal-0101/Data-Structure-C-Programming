/* Program to implement Quick Sort taking pivot as last element*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Protyping */
void swap(int *, int *);
void display(int [], int );
int partition(int [], int , int);
void quickSort(int [], int, int);

/* Code for partition function */
int partition(int arr[15], int low, int high)
{
	int pivot;
	int i, j;
	pivot = arr[high];
	i = low-1;
	for(j=low; j<high; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;	
}

/* Function for quicksort*/
void quickSort(int arr[15], int low, int high)
{
	int p;
	if(low < high)
	{
		p = partition(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
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
	quickSort(arr, 0, n-1);
	printf("After sort the elements are: ");
	display(arr, n);
	return 0;
}
