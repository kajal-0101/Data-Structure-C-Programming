/* Program to implement Insertion Sort */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Protyping */
void swap(int *, int *);
void display(int [], int );
void inssertionSort(int [], int );

/* Code for Insertion sort */
void insertionSort(int arr[15], int n)
{
	int i, j, key, change;
	for (i=1; i<n; i++)
	{
		change = 0;
		key = arr[i];
		printf("key = %d\n", key); // printing the key
		j = i-1;
		printf("pass = %d\n", (j+1)); // printing the pass
		while(j >=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
			change++;
		}
		arr[j+1] = key;
		printf("No. of swaps: %d\n", change);
		printf("Intermediate list: ");  // printing the intermediate array
		display(arr,n);
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
	insertionSort(arr,n);
	printf("After completion of sorting the elements are: ");
	display(arr, n);
	return 0;
}
