/* Program to implement Selection Sort */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Protyping */
void swap(int *, int *);
void display(int [], int );
void splitAndMerge(int [], int , int);
void merge(int [], int, int, int);

/* Code for split and merge function */
void splitAndMerge(int arr[15], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		splitAndMerge(arr, low, mid);
		splitAndMerge(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

/* Function for merging the arrays*/
void merge(int arr[15], int low, int mid, int high)
{
	int i = low;
	int j = (mid + 1);
	int index = low;
	int k;
	int temp[15]; // auxilarry array as merge sort is not an inplace sort
	
	while(i<=mid && j<=high)
	{
		if(arr[i] <= arr[j])
		{
			temp[index] = arr[i];
			i = i + 1;
		}
		else
		{
			temp[index] = arr[j];
			j = j + 1;
		}
		index++;
	}
	if (i > mid)
	{
		while(j <= high)
		{
			temp[index] = arr[j];
			index++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index] = arr[i];
			index++;
			i++;
		}
	}
	k = low;
	while(k < index)
	{
		arr[k] = temp[k];
		k++;
		
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
	splitAndMerge(arr, 0, n-1);
	printf("After sort the elements are: ");
	display(arr, n);
	return 0;
}
